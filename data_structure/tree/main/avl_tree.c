/* 
zhanghu
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hu_system.h"
#include "avl_tree.h"

#define LEFT_HIGH +1
#define BALANCE  0
#define RIGHT_HIGH -1

void right_rotate(avl_tree_node_t node)
{
    avl_tree_node_t lc = node->left;
    node->left = lc->right;
    lc->right = node;
    node = lc;
}

void left_rotate(avl_tree_node_t node)
{
    avl_tree_node_t rc = node->right;
    node->right = rc->left;
    rc->left = node;
    node = rc;
}

void left_balance(avl_tree_node_t node)
{
    avl_tree_node_t lc,rd;
    lc = node->left;
    //查看以 node 的左子树为根结点的子树，失去平衡的原因，如果 bf 值为 1 ，
    //则说明添加在左子树为根结点的左子树中，需要对其进行右旋处理；
    //反之，如果 bf 值为 -1，说明添加在以左子树为根结点的右子树中，需要进行双向先左旋后右旋的处理
    switch (lc->bf) {
        case LEFT_HIGH:
            node->bf = lc->bf = BALANCE;
            right_rotate(node);
            break;
        case RIGHT_HIGH:
            rd = lc->right;
            switch(rd->bf) {
                case LEFT_HIGH:
                    node->bf = RIGHT_HIGH;
                    lc->bf = BALANCE;
                    break;
                case BALANCE:
                    node->bf = lc->bf = BALANCE;
                    break;
                case RIGHT_HIGH:
                    node->bf = BALANCE;
                    lc->bf = LEFT_HIGH;
                    break;
            }
            rd->bf = BALANCE;
            left_rotate(node->left);
            right_rotate(node);
            break;
    }
}

void right_balance(avl_tree_node_t node)
{
    avl_tree_node_t lc,rd;
    lc= node->right;
    switch (lc->bf)
    {
        case RIGHT_HIGH:
            node->bf = lc->bf = BALANCE;
            left_rotate(node);
            break;
        case LEFT_HIGH:
            rd = lc->left;
            switch(rd->bf)
        {
            case LEFT_HIGH:
                node->bf = BALANCE;
                lc->bf = RIGHT_HIGH;
                break;
            case BALANCE:
                node->bf = lc->bf = BALANCE;
                break;
            case RIGHT_HIGH:
                node->bf = BALANCE;
                lc->bf = LEFT_HIGH;
                break;
        }
            rd->bf = BALANCE;
            right_rotate(node->right);
            left_rotate(node);
            break;
    }
}

int insert_avl_tree(avl_tree_node_t node, int value, bool* taller)
{
    if (node==NULL) {
        node=(avl_tree_node_t)malloc(sizeof(struct avl_tree_node));
        node->bf = BALANCE;
        node->value = value;
        node->left = NULL;
        node->right = NULL;
        *taller= true;
    } else if (value == node->value) {
        *taller = false;
        return 0;
    } else if (value < node->value) {
        //如果插入过程，不会影响树本身的平衡，则直接结束
        if(!insert_avl_tree(node->left, value, taller)) {
            return 0;
        }
            
        //判断插入过程是否会导致整棵树的深度 +1
        if(*taller) {
            //判断根结点 node 的平衡因子是多少，由于是在其左子树添加新结点的过程中导致失去平衡，所以当 node 结点的平衡因子本身为 1 时，需要进行左子树的平衡处理，否则更新树中各结点的平衡因子数
            switch (node->bf) {
                case LEFT_HIGH:
                    left_balance(node);
                    *taller = false;
                    break;
                case  BALANCE:
                    node->bf = LEFT_HIGH;
                    *taller = true;
                    break;
                case RIGHT_HIGH:
                    node->bf = BALANCE;
                    *taller = false;
                    break;
            }
        }
    } else {   //同样，当 e>node->value 时，需要插入到以 node 为根结点的树的右子树中，同样需要做和以上同样的操作
        if(!insert_avl_tree(node->right, value, taller)) {
            return 0;
        }
        if (*taller) {
            switch (node->bf) {
                case LEFT_HIGH:
                    node->bf = BALANCE;
                    *taller = false;
                    break;
                case BALANCE:
                    node->bf = RIGHT_HIGH;
                    *taller = true;
                    break;
                case  RIGHT_HIGH:
                    right_balance(node);
                    *taller = false;
                    break;
            }
        }
    }
    return 1;
}

bool find_node(avl_tree_node_t root, int value, avl_tree_node_t node)
{
    avl_tree_node_t pt = root;
    node = NULL;
    while(pt) {
        if (pt->value == value) {
            node = pt;
            return true;
        } else if (pt->value > value) {
            pt = pt->left;
        } else {
            pt = pt->right;
        }
    }
    return false;
}

void avl_tree_mid_print(avl_tree_node_t root)
{
    if(root->left) {
        avl_tree_mid_print(root->left);
    }
        
    LOGI("%d",root->value);
   
    if(root->right) {
        avl_tree_mid_print(root->right);
    }    
}


res_err_t avl_tree_init()
{
    int array[] = {1, 23, 45, 34, 98, 9, 4, 35, 23};
    avl_tree_node_t root = NULL, pos;
    bool taller;
   
    for (int i=0; i<9; i++){
        insert_avl_tree(root, array[i], &taller);
    }

    //中序遍历输出
    avl_tree_mid_print(root);
    
    //判断平衡二叉树中是否含有数据域为 103 的数据
    if (find_node(root, 103, pos)) {
        LOGI("\n%d\n",pos->value);
    } else {
        LOGW("Not find thilHIs Node");
    }
}

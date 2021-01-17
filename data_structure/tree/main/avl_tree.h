#ifndef __AVL_TREE_H__
#define __AVL_TREE_H__

#include<stdio.h>
#include<stdlib.h>

typedef struct avl_tree_node*   avl_tree_node_t;

struct avl_tree_node
{
    struct avl_tree_node* left;  // 左子树
    struct avl_tree_node* right;    // 右子树
    struct avl_tree_handle* owner;
    int value;
    int bf;
}avl_tree_node;


void right_rotate(avl_tree_node_t node);

void left_rotate(avl_tree_node_t node);

void left_balance(avl_tree_node_t node);

void right_balance(avl_tree_node_t node);

int insert_avl_tree(avl_tree_node_t node, int value, bool* taller);

bool find_node(avl_tree_node_t root, int value, avl_tree_node_t node);

void avl_tree_mid_print(avl_tree_node_t root);

res_err_t avl_tree_init();

#endif

#ifndef __BIN_TREE_H__
#define __BIN_TREE_H__

#include<stdio.h>
#include<stdlib.h>

#define BLANK -1 
#define LEFT -2
#define RIGHT -3

typedef struct binary_tree_node*   binary_tree_node_t;
typedef struct binary_tree_handle* binary_tree_handle_t;

struct binary_tree_handle
{
    struct binary_tree_node* root;
    struct binary_tree_node* index;
    int count;
}binary_tree_handle;

struct binary_tree_node
{
    struct binary_tree_node* left;  // 左子树
    struct binary_tree_node* right;    // 右子树
    struct binary_tree_handle* owner;
    int value; 
}binary_tree_node;

 
binary_tree_node_t binary_tree_create(binary_tree_handle_t handle,  int value);

binary_tree_node_t binary_tree_add_node(binary_tree_handle_t handle, int value);

binary_tree_node_t create_node(int value);

binary_tree_node_t add_node(int value, binary_tree_node_t node);


/**
 * @brief       二叉搜索树插入
 *
 * @param[in]  root
 * @param[in]  value
 *
 * @return    int
 */
int binary_tree_search_insert(binary_tree_handle_t root,int value);

/**
 * @brief        二叉树删除
 *
 * @param[in]  root
 * @param[in]  value
 *
 * @return    int
 */ 
int binary_tree_erase(binary_tree_handle_t roote,int value);


/**
 * @brief        二叉搜索树查找
 *
 * @param[in]  root
 * @param[in]  value
 *
 * @return    int
 */
int binary_tree_search_find(binary_tree_handle_t root,int value);

/**
 * @brief        二叉树前序遍历
 *
 * @param[in]  root
 *
 * @return 
 */
void binary_tree_pre_print(binary_tree_handle_t root);

/**
 * @brief       二叉树中序遍历
 *
 * @param[in]  root
 *
 * @return
 */
void binary_tree_mid_print(binary_tree_node_t node);

/**
 * @brief       二叉树后序遍历
 *
 * @param[in]  root
 *
 * @return
 */
void binary_tree_back_print(binary_tree_handle_t root);

/**
 * @brief        层次遍历
 *
 * @param[in]  root
 *
 * @return
 */
void binary_tree_level_print(binary_tree_handle_t root);

/**
 * @brief        弹出链表第一个元素
 *
 * @param[in]  root
 *
 * @return
 */
binary_tree_handle_t binary_tree_top(binary_tree_node_t root);



#endif

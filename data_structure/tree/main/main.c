/* 
zhanghu
*/
#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "hu_system.h"
// binary_tree_handle_t
// binary_tree_node_t

void main()
{
    LOGI("Hello world!");

    // binary_tree_handle_t handle;


    binary_tree_node_t node = create_node(10);

    add_node(14, node);
    add_node(15, node);
    add_node(10, node);
    add_node(17, node);
    add_node(3, node);

    binary_tree_mid_print(node);
    // binary_tree_create(handle, 10);
    // printf("---%d \n", handle->index->value);
    // binary_tree_add_node(handle, 5);
    // binary_tree_add_node(handle, 6);
    // binary_tree_add_node(handle, 18);
    // binary_tree_add_node(handle, 15);
    // binary_tree_add_node(handle, 12);
    // binary_tree_add_node(handle, 8);
    // binary_tree_add_node(handle, 19);
    // binary_tree_add_node(handle, 2);
    // binary_tree_add_node(handle, 20);
    // binary_tree_add_node(handle, 3);


    // node_root->link = NULL;
    // binary_tree_search_insert(root,10);
    // binary_tree_search_insert(root,2);
    // binary_tree_search_insert(root,2);
    // binary_tree_search_insert(root,3);
    // binary_tree_search_insert(root,4);
    // binary_tree_search_insert(root,15);
    // binary_tree_search_insert(root,6);
    // binary_tree_search_find(root,15);

    // printf("前序遍历: ");
    // binary_tree_pre_print(root);
   
    // printf("中序遍历: ");
    // binary_tree_mid_print(root);
   
    // printf("后序遍历: ");
    // binary_tree_back_print(root);
   
    // printf("层次遍历: ");
    // binary_tree_level_print(root);
  
    // free(root);
    // return 0;

}

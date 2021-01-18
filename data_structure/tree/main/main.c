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
    binary_tree_node_t node = create_node(10);

    add_node(14, node);
    add_node(15, node);
    add_node(10, node);
    add_node(17, node);
    add_node(3, node);
    
    LOGI("binary tree");
    binary_tree_mid_print(node);
    
    LOGI("avl tree");
    avl_tree_init();

}

/* 
zhanghu
*/
#include <stdio.h>
#include "hu_system.h"
#include "binary_tree.h"


binary_tree_node_t binary_tree_create(binary_tree_handle_t handle, int value)
{
    binary_tree_node_t node = (binary_tree_node_t)malloc(sizeof(struct binary_tree_node));
    node->left = NULL;
    node->right = NULL;
    node->value = value;
    LOGI("---");
    if (handle == NULL) {
        handle = (binary_tree_handle_t)malloc(sizeof(struct binary_tree_handle)); 
        handle->root = node;
    }
     LOGI("---");
    node->owner = handle;
     LOGI("---");
    handle->index = node;
    LOGI("---");
    return handle->index;
}

binary_tree_node_t binary_tree_add_node(binary_tree_handle_t handle, int value)
{
    LOGI("---");
    // if(handle->index == NULL) {
    //     return binary_tree_create(handle, value);
    // }
    binary_tree_node_t node = handle->index;
    LOGI("---");
    if(value == handle->index->value)
    {
        return handle->index;
    }
 LOGI("---");
    if(value < handle->index->value)
    {
        if(handle->index->left == NULL)
        {
            handle->index->left = binary_tree_create(handle, value);
            return handle->index->left;
        }
        else
        {
            handle->index = handle->index->left;
            return binary_tree_add_node(handle, value);
        }
    }
    else
    {
        if(handle->index->right == NULL)
        {
            handle->index->right = binary_tree_create(handle, value);
            return handle->index->right;
        }
        else
        {
            handle->index = handle->index->right;
            return binary_tree_add_node(handle, value);
        }

    }
}

binary_tree_node_t create_node(int value)
{
    binary_tree_node_t node = (binary_tree_node_t)malloc(sizeof(struct binary_tree_node));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}	


binary_tree_node_t add_node(int value, binary_tree_node_t node)
	{
		if(node == NULL)
			return create_node(value);

		if(value == node->value)
		{
			return node;
		}

		if(value < node->value)
		{
			if(node->left == NULL)
			{
				node->left = create_node(value);
				return node->left;
			}
			else
			{
				return add_node(value, node->left);
			}
		}
		else
		{
			if(node->right == NULL)
			{
				node->right = create_node(value);
				return node->right;
			}
			else
			{
				return add_node(value, node->right);
			}

		}
	}

int binary_tree_search_insert(binary_tree_handle_t root,int value)
{
    return 0;
}


int binary_tree_erase(binary_tree_handle_t roote,int value)
{
    return 0;
}


int binary_tree_search_find(binary_tree_handle_t root,int value)
{
    return 0;
}



void binary_tree_pre_print(binary_tree_handle_t root)
{
    
}



void binary_tree_mid_print(binary_tree_node_t node)
{
	if(node != NULL)
	{
		binary_tree_mid_print(node->left);
		printf("%d\n", node->value);
		binary_tree_mid_print(node->right);
	}
}



void binary_tree_back_print(binary_tree_handle_t root)
{
    
}



void binary_tree_level_print(binary_tree_handle_t root)
{
    
}


binary_tree_handle_t binary_tree_top(binary_tree_node_t root)
{
    return NULL;
}



#include <stdlib.h>
#include "node.h"

/**
 * 新建分叉节点。
 * 
 */
node_t *new_fork(node_type_t type, node_t *left, node_t *right) {
    node_t *result = malloc(sizeof(node_t));
    result->type = type;
    result->value.fork.left = left;
    result->value.fork.right = right;
    return result;
}

/**
 * 新建数字节点。
 * 
 */
node_t *new_number(double number) {
    node_t *result = malloc(sizeof(node_t));
    result->type = NT_NUMBER;
    result->value.number = number;
    return result;
}

/**
 * 释放节点。
 * 
 */
void free_node(node_t *node) {
    switch (node->type) {
    case NT_NUMBER:
        break;
    case NT_ADDITION:
    case NT_SUBTRACTION:
    case NT_MULTIPLICATION:
    case NT_DIVISION:
        free_node(node->value.fork.left);
        free_node(node->value.fork.right);
        break;
    }
    free(node);
}
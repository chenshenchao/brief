#include <stdlib.h>
#include "node.h"

node_t *new_node_operation(node_operation_type_t type, node_t *left, node_t *right)
{
    node_t *result = malloc(sizeof(node_t));
    result->type = NT_OPERATION;
    result->value.operation.type = type;
    result->value.operation.left = left;
    result->value.operation.right = right;
    return result;
}

node_t *new_node_operand(const any_t *value)
{
    node_t *result = malloc(sizeof(node_t));
    result->type = NT_OPERAND;
    result->value.operand = *value;
    return result;
}

node_t *new_node_identifier(const char *value)
{
    node_t *result = malloc(sizeof(node_t));
    result->type = NT_IDENTIFIER;
    result->value.identifier = value;
    return result;
}
node_t *new_node_number(double value)
{
    node_t *result = malloc(sizeof(node_t));
    result->type = NT_OPERAND;
    result->value.operand.type = AT_NUMBER;
    result->value.operand.value.number = value;
    return result;
}
node_t *new_node_boolean(bool value)
{
    node_t *result = malloc(sizeof(node_t));
    result->type = NT_OPERAND;
    result->value.operand.type = AT_NUMBER;
    result->value.operand.value.boolean = value;
    return result;
}

/**
 * 释放节点。
 * 
 */
void free_node(node_t *node)
{
    switch (node->type)
    {
    case NT_OPERAND:
        break;
    case NT_OPERATION:
        free_node(node->value.operation.left);
        free_node(node->value.operation.right);
        break;
    }
    free(node);
}
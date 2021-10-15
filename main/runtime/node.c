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
node_t *new_node_let(node_t *name, node_t *expression)
{
    node_t *result = malloc(sizeof(node_t));
    result->type = NT_LET;
    result->value.node_let.name = name;
    result->value.node_let.expression = expression;
    return result;
}
node_t *new_node_call(node_t *name, node_t *args){
    node_t *result = malloc(sizeof(node_t));
    result->type = NT_CALL;
    result->value.node_call.name = name;
    result->value.node_call.args = args;
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
    case NT_LET:
        free_node(node->value.node_let.expression);
        free(node->value.node_let.name);
        break;
    }
    free(node);
}
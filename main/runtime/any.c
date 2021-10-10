#include "any.h"

/**
 * 求值。
 * 
 */
any_t evalute(node_t *node)
{
    any_t result;
    switch (node->type)
    {
    case NT_NUMBER:
    {
        result.type = AT_NUMBER;
        result.value.number = node->value.number;
        break;
    }
    case NT_ADDITION:
    {
        result.type = AT_NUMBER;
        any_t left = evalute(node->value.fork.left);
        any_t right = evalute(node->value.fork.right);
        result.value.number = left.value.number + right.value.number;
        break;
    }
    case NT_SUBTRACTION:
    {
        result.type = AT_NUMBER;
        any_t left = evalute(node->value.fork.left);
        any_t right = evalute(node->value.fork.right);
        result.value.number = left.value.number - right.value.number;
        break;
    }
    case NT_MULTIPLICATION:
    {
        result.type = AT_NUMBER;
        any_t left = evalute(node->value.fork.left);
        any_t right = evalute(node->value.fork.right);
        result.value.number = left.value.number * right.value.number;
        break;
    }
    case NT_DIVISION:
    {
        result.type = AT_NUMBER;
        any_t left = evalute(node->value.fork.left);
        any_t right = evalute(node->value.fork.right);
        result.value.number = left.value.number / right.value.number;
        break;
    }
    }
    return result;
}
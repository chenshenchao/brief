#ifndef BRIEF_RUNTIME_OPERATION_H
#define BRIEF_RUNTIME_OPERATION_H

#include "any.h"

typedef enum node_operation_type_e
{
    NOT_PLUS = 1,
    NOT_MINUS,
    NOT_STAR,
    NOT_SLASH,
    NOT_EQUAL,
    NOT_BLOCK,
    NOT_LIST,
    NOT_IDENTIFIER_LIST,
    NOT_LET,
    NOT_CALL,
} node_operation_type_t;

/* 操作节点 */
typedef struct node_operation_s
{
    node_operation_type_t type;
    struct node_s *left;
    struct node_s *right;
} node_operation_t;

any_t interpret_operation(node_operation_t *operation);

#endif

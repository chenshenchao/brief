#ifndef BRIEF_SYNTAX_OPERATION_H
#define BRIEF_SYNTAX_OPERATION_H

typedef enum node_operation_type_e
{
    NOT_PLUS = 1,
    NOT_MINUS,
    NOT_STAR,
    NOT_SLASH,
    NOT_EQUAL,
    NOT_BLOCK,
    NOT_LIST,
} node_operation_type_t;

typedef struct node_operation_s
{
    node_operation_type_t type;
    struct node_s *left;
    struct node_s *right;
} node_operation_t;

#endif

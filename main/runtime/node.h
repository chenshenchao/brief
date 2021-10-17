#ifndef RUNTIME_NODE_H
#define RUNTIME_NODE_H

#include "any.h"
#include "operation.h"

/**
 * 抽象语法树节点类型。
 * 
 */
typedef enum node_type_e
{
    NT_NIL = 0,
    NT_OPERAND,         // 操作数
    NT_IDENTIFIER,      // 变量
    NT_OPERATION,       // 操作
    NT_LET,             // 声明
    NT_CALL,            // 调用
    NT_END = -1         // 结尾
} node_type_t;

/**
 * 构建抽象语法树的节点。
 * 
 */
typedef struct node_s
{
    node_type_t type;
    union
    {
        any_t operand;
        const char *identifier;
        node_operation_t operation;
    } value;
} node_t;

node_t *new_node_operation(node_operation_type_t type, node_t *left, node_t *right);

node_t *new_node_operand(const any_t *value);
node_t *new_node_identifier(const char *value);
node_t *new_node_number(double value);
node_t *new_node_boolean(bool value);
void free_node(node_t *node);

#endif

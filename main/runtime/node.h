#ifndef RUNTIME_NODE_H
#define RUNTIME_NODE_H

/**
 * 抽象语法树节点类型。
 * 
 */
typedef enum node_type_e
{
    NT_NIL = 0,
    NT_NUMBER,         // 数字
    NT_ADDITION,       // 加法
    NT_SUBTRACTION,    // 减法
    NT_MULTIPLICATION, // 乘法
    NT_DIVISION,       // 除法
    NT_END = -1        // 结尾
} node_type_t;

/**
 * 分叉节点。
 * 
 */
struct fork_s
{
    struct node_s *left;
    struct node_s *right;
} fork_t;

/**
 * 构建抽象语法树的节点。
 * 
 */
typedef struct node_s
{
    enum node_type_e type;
    union {
        double number;
        struct fork_s fork;
    } value;
} node_t;

node_t *new_fork(node_type_t type, node_t *left, node_t *right);
node_t *new_number(double number);
void free_node(node_t *node);

#endif

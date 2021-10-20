#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "operation.h"
#include "variable.h"
#include "../interpreter.h"

extern interpreter_t interpreter;

any_t interpret_operation(node_operation_t *operation)
{
    any_t r;
    // printf("执行操作：%d\n", operation->type);
    switch (operation->type)
    {
    case NOT_BLOCK:
        interpret_node(operation->left);
        return interpret_node(operation->right);
    case NOT_LET:
        if (operation->left->type != NT_IDENTIFIER)
        {
            fprintf(stderr, "let 左边非标识符：%d\n", operation->left->type);
            exit(-1);
        }
        printf("let: %s\n", operation->left->value.identifier);
        variable_t *n = new_variable(operation->left->value.identifier);
        n->value = interpret_node(operation->right);

        variable_t *t = interpreter.current_scope->tail;
        if (t != 0)
        {
            t->next = n;
        }
        interpreter.current_scope->tail = n;

        r.type = AT_VOID;
        return r;
    case NOT_EQUAL:
        break;
    case NOT_CALL:
        if (operation->left->type != NT_IDENTIFIER)
        {
            fprintf(stderr, "let 左边非标识符：%d\n", operation->left->type);
            exit(-1);
        }
        printf("call: %s\n", operation->left->value.identifier);
        break;
    }
    return r;
}
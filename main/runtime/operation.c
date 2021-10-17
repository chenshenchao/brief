#include <stdio.h>
#include <stdlib.h>
#include "operation.h"
#include "variable.h"
#include "../interpreter.h"

extern interpreter_t interpreter;

any_t interpret_operation(node_operation_t *operation)
{
    any_t r;
    switch (operation->type)
    {
    case NOT_BLOCK:
        break;
    case NOT_LET:
        if (operation->left->type != NT_IDENTIFIER)
        {
            fprintf(stderr, "let 左边非标识符：%d\n", operation->left->type);
            exit(-1);
        }
        variable_t *t = interpreter.current_scope->tail;
        variable_t *n = new_variable(operation->left->value.identifier);
        // n->value = 
        t->next = n;
        break;
    case NOT_EQUAL:
        break;
    }
    return r;
}
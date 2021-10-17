#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "grammar/brief.h"
#include "interpreter.h"

extern FILE *yyin;
extern int yylineno;
extern int yyparse();

interpreter_t interpreter;

/* 初始化解释器 */
void init_interpreter()
{
    interpreter.global_scope.head = 0;
    interpreter.global_scope.tail = 0;
    interpreter.global_scope.periphery = 0;
    interpreter.current_scope = &interpreter.global_scope;
    interpreter.heap.head = 0;
    interpreter.heap.size = 0;
    interpreter.heap.threshold = 2000000;
    interpreter.stack.size = 0;
    interpreter.tree_root = 0;
}

/* 释放解释器 */
void quit_interpreter()
{
}

/**
 * 解释。
 */
int interpret(FILE *stream)
{
    /* 配置前端信息 */
    yyin = stream;

    /* 解释获取抽象语法树 */
    if (yyparse())
    {
        fprintf(stderr, "语法错误：\n");
        return -1;
    }

    /* 遍历树执行 */
    if (interpreter.tree_root->type != NT_OPERATION ||
        interpreter.tree_root->value.operation.type != NOT_BLOCK)
    {
        fprintf(stderr, "不是有效的程序开始\n");
    }
    interpret_operation(&interpreter.tree_root->value.operation);

    return 0;
}

/**
 * 由 bison 生成代码声明。
 * 错误打印处理。
 *
 */
void yyerror(char *message, ...)
{
    va_list pointer;
    va_start(pointer, message);

    fprintf(stderr, "%d error: ", yylineno);
    vfprintf(stderr, message, pointer);
    fprintf(stderr, "\n");
}

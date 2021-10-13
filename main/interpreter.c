#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "grammar/brief.h"
#include "interpreter.h"

extern FILE *yyin;
extern int yylineno;
extern int yyparse();

static interpreter_t interpreter;

/* 初始化解释器 */
void init_interpreter()
{
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
        fprintf(stderr, "syntax: error");
        return -1;
    }

    /* 遍历树执行 */
    
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

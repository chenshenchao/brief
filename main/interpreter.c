#include <stdarg.h>
#include <stdio.h>
#include "grammar/brief.h"

extern int yylineno;

/**
 * 错误打印处理。
 * 
 */
void yyerror(char *message, ...) {
    va_list pointer;
    va_start(pointer, message);

    fprintf(stderr, "%d error: ", yylineno);
    vfprintf(stderr, message, pointer);
    fprintf(stderr, "\n");
}

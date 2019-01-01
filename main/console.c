#include <stdio.h>
#include "grammar/brief.h"

/**
 * 命令行程序入口。
 * 
 */
int main(int count, char **arguments) {
    printf("> ");
    return yyparse();
}
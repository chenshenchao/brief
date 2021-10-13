#include <stdio.h>
#include "grammar/brief.h"
#include "interpreter.h"

/**
 * 命令行程序入口。
 * 
 */
int main(int argc, char **args)
{
    if (argc != 2)
    {
        fprintf(stderr, "usage:%s script.brf", args[0]);
        return -1;
    }

    /* 读取文件 */
    FILE *stream = fopen(args[1], "r");
    if (stream == NULL)
    {
        fprintf(stderr, "%s is not found.", args[1]);
        return -2;
    }

    /* 执行解释 */
    init_interpreter();
    int code = interpret(stream);

    /* 回收资源 */
    fclose(stream);
    quit_interpreter();
    return code;
}
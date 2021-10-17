#ifndef BRIEF_INTERPRETER_H
#define BRIEF_INTERPRETER_H

#include <stdio.h>
#include "runtime/heap.h"
#include "runtime/node.h"
#include "runtime/scope.h"
#include "runtime/stack.h"

/* 解释器 */
typedef struct interpreter_s
{
    scope_t global_scope;
    scope_t *current_scope;
    node_t *tree_root;
    heap_t heap;
    stack_t stack;
} interpreter_t;

/* 初始化解释器。 */
void init_interpreter();

/* 释放解释器。 */
void quit_interpreter();

/* 解释文件流 */
int interpret(FILE *stream);

/* 对堆数据进行校验标记。*/
void check_heap();

/* 清理被标记的 */
void sweep_heap();

#endif

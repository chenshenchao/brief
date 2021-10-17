#ifndef BRIEF_RUNTIME_VARIABLE_H
#define BRIEF_RUNTIME_VARIABLE_H

#include <stddef.h>
#include "any.h"

/* 变量链表节点 */
typedef struct variable_s
{
    const char *name;
    struct any_s value;
    struct variable_s *next;
} variable_t;

variable_t *new_variable(const char *name);

#endif

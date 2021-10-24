#ifndef BRIEF_RUNTIME_SCOPE_H
#define BRIEF_RUNTIME_SCOPE_H

#include <stdbool.h>

/* 作用域 */
typedef struct scope_s
{
    bool in_function;
    struct scope_s *periphery;
    struct variable_s *head;
    struct variable_s *tail;
} scope_t;

struct variable_s *find_variable(scope_t *scope, const char *name);
void unmark_garbage_all(scope_t *scope);

#endif

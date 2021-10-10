#ifndef BRIEF_RUNTIME_SCOPE_H
#define BRIEF_RUNTIME_SCOPE_H

/* 作用域 */
typedef struct scope_s
{
    struct scope_s *periphery;
    struct variable_s *list_head;
} scope_t;

#endif

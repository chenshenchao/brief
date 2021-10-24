#include <string.h>
#include "scope.h"
#include "object.h"
#include "variable.h"

struct variable_s *find_variable(scope_t *scope, const char *name)
{
    while (scope != 0)
    {
        variable_t *pointer = scope->head;
        while (pointer != 0)
        {
            if (strcmp(pointer->name, name) == 0)
            {
                return pointer;
            }
            pointer = pointer->next;
        }

        // 向上级作用域查找
        if (!scope->in_function)
        {
            scope = scope->periphery;
        }
    }
}

/**
 * 把作用域里面用到的变量解除垃圾标签。
 * 
 */
void unmark_garbage_all(scope_t *scope)
{
    while (scope != 0)
    {
        variable_t *pointer = scope->head;
        while (pointer != 0)
        {
            if (pointer->value.type == AT_OBJECT)
            {
                pointer->value.value.target->is_garbage = false;
            }
            pointer = pointer->next;
        }
        scope = scope->periphery;
    }
}
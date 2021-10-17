#include <stdlib.h>
#include "variable.h"

variable_t *new_variable(const char *name)
{
    variable_t *result = malloc(sizeof(variable_t));
    result->name = name;
    return result;
}
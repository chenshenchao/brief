#ifndef BRIEF_RUNTIME_STRING_H
#define BRIEF_RUNTIME_STRING_H

#include <stddef.h>
#include <stdbool.h>

typedef struct string_s {
    bool is_literal;
    char *content;
} string_t;

#endif

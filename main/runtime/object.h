#ifndef BRIEF_RUNTIME_OBJECT_H
#define BRIEF_RUNTIME_OBJECT_H

#include <stdbool.h>
#include "array.h"
#include "string.h"

/**
 *
 */
typedef enum object_type_e {
    OT_ARRAY,
    OT_STRING,
} object_type_t;

/**
 * 引用类型
 * 
 */
typedef struct object_s {
    enum object_type_e type;
    bool is_garbage; // 回收标记
    union {
        struct array_s data;
        struct string_s text;
    } value;
    struct object_s *fore;
    struct object_s *back;
} object_t;

void mark_garbage(object_t *target);

#endif

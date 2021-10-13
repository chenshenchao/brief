#ifndef ANY_H
#define ANY_H

#include <stdbool.h>
#include "native.h"

/* 类型枚举 */
typedef enum any_type_e
{
    AT_NULL = 0,
    AT_BOOL,
    AT_NUMBER,
    AT_OBJECT,
} any_type_t;

/* 通用数据类型 */
typedef struct any_s
{
    any_type_t type;

    union
    {
        bool boolean;
        double number;
        struct object_s *target;
        pointer_t pointer;
    } value;
} any_t;

#endif

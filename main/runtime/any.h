#ifndef ANY_H
#define ANY_H

#include "node.h"

/**
 * 类型枚举。
 * 
 */
typedef enum any_type_e {
    AT_NUMBER
} any_type_t;

/**
 * 通用数据类型。
 * 
 */
typedef struct any_s {
    any_type_t type;
    union {
        double number;
    } value;
} any_t;

any_t *evalute(node_t *node);
void free_any(any_t *any);

#endif

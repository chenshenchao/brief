#ifndef BRIEF_RUNTIME_ARRAY_H
#define BRIEF_RUNTIME_ARRAY_H

/* 数组类型 */
typedef struct array_s
{
    int length;
    int capactiy;
    struct any_s *storage;
} array_t;

#endif

#ifndef BRIEF_RUNTIME_HEAP
#define BRIEF_RUNTIME_HEAP

/* 堆 */
typedef struct heap_s
{
    int size;
    int threshold; // 回收阈值
    struct object_s *head;
} heap_t;

void clear_mark(heap_t *heap);

#endif

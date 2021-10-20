#ifndef BRIEF_RUNTIME_HEAP
#define BRIEF_RUNTIME_HEAP

/* 堆 */
typedef struct heap_s
{
    int size;
    int threshold; // 回收阈值
    struct object_s *head;
} heap_t;

void mark_garbage_all(heap_t *heap);
struct object_s *alloc_object(heap_t *heap, int size);
void free_object(heap_t *heap, struct object_s *one);

#endif

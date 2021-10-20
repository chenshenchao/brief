#include "heap.h"
#include "object.h"

void mark_garbage_all(heap_t *heap)
{
    object_t *pointer = heap->head;
    while (pointer != 0)
    {
        pointer->is_garbage = true;
        pointer = pointer->back;
    }
}
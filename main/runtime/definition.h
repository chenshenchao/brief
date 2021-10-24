#ifndef BRIEF_RUNTIME_DEFINITION_H
#define BRIEF_RUNTIME_DEFINITION_H

typedef enum node_definition_type_e {
    NDT_FUNCTION,
    NDT_METHOD,
    NDT_CLOSURE,
} node_definition_type_t;

typedef struct node_definition_s {
    const char *name;
    struct node_operation_s *param;
    struct node_operation_s *block;
} node_definition_t;

#endif

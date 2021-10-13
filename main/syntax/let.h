#ifndef BRIEF_SYNTAX_LET_H
#define BRIEF_SYNTAX_LET_H

/* 声明变量 */
typedef struct node_let_s
{
    struct node_s *name;
    struct node_s *expression;
} node_let_t;



#endif

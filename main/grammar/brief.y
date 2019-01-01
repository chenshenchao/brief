%{
    #include <stdio.h>
    #include "brief.h"
%}

%union {
    double number;
    struct node_s *node;
}

%token <number> NUMBER;
%token PLUS MINUS STAR SLASH EQUAL
%token COLON SEMICOLON
%token EOL

// 优先级
%left PLUS MINUS
%left STAR SLASH

%type <node> program statement expression

%start program

%%

program: statement EOL {
        any_t *result = evalute($1);
        printf("= %4.4g\n", result->value.number);
        free_node($1);
    }
    | program statement EOL {
        any_t *result = evalute($1);
        printf("= %4.4g\n", result->value.number);
        free_node($2);
    }
    ;

statement: expression SEMICOLON { $$ = $1; }
    ;

expression: NUMBER { $$ = new_number($1); }
    | expression PLUS expression { $$ = new_fork(NT_ADDITION, $1, $3); }
    | expression MINUS expression { $$ = new_fork(NT_SUBTRACTION, $1, $3); }
    | expression STAR expression { $$ = new_fork(NT_MULTIPLICATION, $1, $3); }
    | expression SLASH expression { $$ = new_fork(NT_DIVISION, $1, $3); }
    ;
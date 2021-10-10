%{
    #include <stdio.h>
    #include "brief.h"
%}

// 返回数据类型
%union {
    double number;
    struct node_s *node;
}

// 词素
%token <number> L_NUMBER;
%token L_STRING
%token IDENTIFIER
%token PLUS MINUS STAR SLASH EQUAL
%token COLON SEMICOLON
%token EOL
%token P_L P_R B_L B_R C_L C_R
%token K_IF K_ELSE
%token K_FN
%token K_TRUE K_FALSE
%token K_NULL

// 优先级
%left PLUS MINUS
%left STAR SLASH

%type <node> program statement expression

%start program

%%

program: statement EOL {
        any_t result = evalute($1);
        printf("= %4.4g\n", result.value.number);
        free_node($1);
    }
    | program statement EOL {
        any_t result = evalute($1);
        printf("= %4.4g\n", result.value.number);
        free_node($2);
    }
    ;

statement: expression SEMICOLON { $$ = $1; }
    ;

expression: L_NUMBER { $$ = new_number($1); }
    | expression PLUS expression {  $$ = new_fork(NT_ADDITION, $1, $3); }
    | expression MINUS expression { $$ = new_fork(NT_SUBTRACTION, $1, $3); }
    | expression STAR expression { $$ = new_fork(NT_MULTIPLICATION, $1, $3); }
    | expression SLASH expression { $$ = new_fork(NT_DIVISION, $1, $3); }
    ;
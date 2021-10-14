%{
    #include <stdio.h>
    #include "brief.h"
    #include "../interpreter.h"

    extern interpreter_t interpreter;
%}

// 返回数据类型
%union {
    bool boolean;
    double number;
    struct any_s *value;
    struct node_s *node;
    struct variable_s *identifier;
}

// 词素
%token <number> L_NUMBER
%token <value> L_STRING
%token <node> IDENTIFIER
%token PLUS MINUS STAR SLASH EQUAL
%token COLON SEMICOLON
%token EOL
%token P_L P_R B_L B_R C_L C_R
%token K_IF K_ELSE
%token K_FN
%token K_LET
%token <boolean> K_TRUE K_FALSE
%token K_NULL

// 结合性（标注）与优先级（低到高）
%right EQUAL
%left PLUS MINUS
%left STAR SLASH

%type <node> program statement statement_list expression let block

%start program

%%

program: statement_list {
        interpreter.tree_root = $$;
    }
    ;

statement:
    expression SEMICOLON {
        $$ = $1;
    }
    | let
    | block
    | statement EOL {
        $$ = $1;
    }
    ;

statement_list:
    statement {
        $$ = new_node_operation(NOT_BLOCK, $1, 0);
    }
    | statement_list statement {
        $1->value.operation.right = $2;
        $$ = $1;
    }
    ;

 /* 表达式 */
expression:
    K_TRUE {
        $$ = new_node_boolean($1);
    }
    | K_FALSE {
        $$ = new_node_boolean($1);
    }
    | L_NUMBER {
        $$ = new_node_number($1);
    }
    | expression PLUS expression {
        $$ = new_node_operation(NOT_PLUS, $1, $3);
    }
    | expression MINUS expression {
        $$ = new_node_operation(NOT_MINUS, $1, $3);
    }
    | expression STAR expression {
        $$ = new_node_operation(NOT_STAR, $1, $3);
    }
    | expression SLASH expression {
        $$ = new_node_operation(NOT_SLASH, $1, $3);
    }
    | IDENTIFIER EQUAL expression {
        $$ = new_node_operation(NOT_EQUAL, $1, $3);
    }
    ;



let: K_LET IDENTIFIER EQUAL expression SEMICOLON {
        $$ = new_node_let($2, $4);
    }
    ;

block: C_L statement_list C_R {
        $$ = $2;
    }
    ;

/*

function: K_FN IDENTIFIER P_L P_R {

    }
    ;

 */
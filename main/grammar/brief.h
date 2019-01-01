#ifndef GRAMMAR_BRIEF_H
#define GRAMMAR_BRIEF_H

#include "brief.bison.h"
#include "../runtime/any.h"
#include "../runtime/node.h"

int yylex();
int yyparse();
void yyerror(char *message, ...);

#endif

%option noyywrap

%{
    #include "brief.h"
%}

ENONATION ([Ee][-+]?[0-9]+)

%%

"+" { return PLUS; }
"-" { return MINUS; }
"*" { return STAR; }
"/" { return SLASH; }
"=" { return EQUAL; }
":" { return COLON; }
";" { return SEMICOLON; }

[0-9]+("."[0-9])?{ENONATION}? {
    yylval.number = atof(yytext);
    return NUMBER;
}

\n { return EOL; }
[ \t] { }
. { yyerror("Mystery charactor %c\n", *yytext); }

%%

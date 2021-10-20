%option noyywrap yylineno

%{
    #include "brief.h"
%}

 /* 独占模式：注释模式 、 字符串模式 */
%x COMMENT_MODE STRING_MODE

ENONATION ([Ee][-+]?[0-9]+)

%%

 /* 操作符 */
<INITIAL>"+" { return PLUS; }
<INITIAL>"-" { return MINUS; }
<INITIAL>"*" { return STAR; }
<INITIAL>"/" { return SLASH; }
<INITIAL>"=" { return EQUAL; }
<INITIAL>"." { return DOT; }
<INITIAL>"," { return COMMA; }
<INITIAL>":" { return COLON; }
<INITIAL>";" { return SEMICOLON; }
<INITIAL>"(" { return P_L; }
<INITIAL>")" { return P_R; }
<INITIAL>"[" { return B_L; }
<INITIAL>"]" { return B_R; }
<INITIAL>"{" { return C_L; }
<INITIAL>"}" { return C_R; }

 /* 关键字 */
<INITIAL>"if" { return K_IF; }
<INITIAL>"else" { return K_ELSE; }
<INITIAL>"fn" { return K_FN; }
<INITIAL>"let" { return K_LET; }
<INITIAL>"true" {
    yylval.boolean = true;
    return K_TRUE;
}
<INITIAL>"false" {
    yylval.boolean = false;
    return K_FALSE;
}
<INITIAL>"null" { return K_NULL; }

 /* 标识符 */
<INITIAL>[A-Za-z][0-9A-Za-z]* {
    yylval.node = new_node_identifier(yytext, yyleng);
    return IDENTIFIER;
}

 /* 字面量，数字 */
<INITIAL>[0-9]+("."[0-9])?{ENONATION}? {
    yylval.number = atof(yytext);
    return L_NUMBER;
}

<INITIAL>[ \t\r\n] { }

 /* 字符串字面量 */
<INITIAL>\" {
    BEGIN STRING_MODE;
}

<STRING_MODE>\" {
    BEGIN INITIAL;
    return L_STRING;
}

 /* 单行注释 */
<INITIAL># {
    BEGIN COMMENT_MODE;
}

 /* 换行切换回正常模式 */
<COMMENT_MODE>\r?\n {
    BEGIN INITIAL;
}

 /* 忽略掉注释模式下的任何字符 */
<COMMENT_MODE>. { }

 /* 未定义的词素，报错，必须在最后 */
<INITIAL>. {
    yyerror("Mystery charactor [%c]\n", *yytext);
}

%%

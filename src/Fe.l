digit               [0-9]
letter              [a-zA-Z_]
hexdigit            [a-fA-F0-9]


%{
#include <stdio.h>
#include <stdlib.h>
#include "src/types_and_symbols.h"
#include "src/semantic_actions.h"
#include "structfe.tab.h"
%}

%option yylineno
%option noyywrap

%x comment



%%

"/*"                    BEGIN(comment);
<comment>.              ;
<comment>"*/"           BEGIN(INITIAL);  




"const"                 { return CONSTANT; }
"else"                  { return ELSE; }
"extern"                { return EXTERN; }
"for"                   { return FOR; }
"if"                    { return IF; }
"int"                   { return INT; }
"return"                { return RETURN; }
"sizeof"                { return SIZEOF; }
"struct"                { return STRUCT; }
"void"                  { return VOID; }
"while"                 { return WHILE; }

">="                    { return GE_OP; }
"<="                    { return LE_OP; }
"=="                    { return EQ_OP; }
"!="                    { return NE_OP; }
"&&"                    { return AND_OP; }
"||"                    { return OR_OP; }

{digit}+             { return INTEGER; }
{letter}({letter}|{digit})* {yylval.string = strdup(yytext);return IDENTIFIER;}


":"        		        { return ':';}
";"     		        { return ';';}
"("                     { return '(';}
")"                     { return ')';}
"{"                     { return '{';}
"}"                     { return '}';}
"["       		        { return '[';}
"]"        		        { return ']';}

"+"             	{ return '+'; }
"-"             	{ return '-'; }
"*"             	{ return '*'; }
"/"             	{ return '/'; }
"%"             	{ return '%'; }
"="             	{ return '='; }
"&"             	{ return '&'; }

"/*"([^*]|"**"+[^*/])*"*/"             { /* ignore block comments */ }
[ \t\v\n\f]+                           { /* ignore whitespace */ }
.                                      { fprintf(stderr, "Caractère invalide '%s' à la ligne %d\n", yytext, yylineno); }





%%




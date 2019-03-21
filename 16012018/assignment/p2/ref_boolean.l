%{
#include "ref_boolean.tab.h"
#include <string.h>
%}
%option noyywrap
%%
[0-9]+"/"[0-9]+"/"[0-9]+ return DATANUMERICA;
Data return DATA;
VAR return VAR;
AND return AND;
OR return OR;
NOT return NOT;
FALSE return FALSE;
TRUE return TRUE;
[_a-zA-Z0-9]+ { yylval.string = strdup(yytext); return ID; }

[():;,/] return *yytext;
[ \n\t\r] ;
%%


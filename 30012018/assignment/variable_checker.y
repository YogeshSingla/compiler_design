/* simplest version of variable checker */
%{
#include <stdio.h>
%}

/* declare tokens */
%token KEYWORD IDENTIFIER
%token SEPARATOR EOL
%token SEPARATOR_COMMA SEPARATOR_SEMICOLON SEPARATOR_START_BRACKET SEPARATOR_END_BRACKET
%%

exp:
KEYWORD IDENTIFIER extend|
KEYWORD IDENTIFIER SEPARATOR_START_BRACKET param SEPARATOR_END_BRACKET SEPARATOR_SEMICOLON {printf("\n\nVALID FUNCTION DECLARATION\n\n\n");}
;

extend: SEPARATOR_SEMICOLON {printf("\n\nVALID VARIABLE DECLARATION\n\n\n");}|
SEPARATOR_COMMA IDENTIFIER extend 
;

param:
KEYWORD IDENTIFIER |
KEYWORD IDENTIFIER SEPARATOR_COMMA param
;

%%

void print(){
	printf("\n\nVALID EXPRESSION\n\n\n");
}

main(int argc, char **argv){
	yyparse();
}

yyerror(char *s){
	//fprintf(stderr, "error: %s\n", s);
}
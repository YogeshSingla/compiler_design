%{
#include <stdio.h>

int yylex();
int yyerror(const char *p){
	fprintf(stderr,"Error\n");
}
%}

%token KEYW ID CO LP RP TE

%%
res: start TE{
	printf("ok\n");
}

start: KEYW ID
| KEYW ID LP val RP

val: KEYW ID
| KEYW ID CO val
%%

int main(){
	yyparse();
	return 0;
}
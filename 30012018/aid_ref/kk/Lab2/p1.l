%{
#include<stdio.h>
%};

%%
[a-zA-Z_][a-zA-Z0-9_]+ { 
	printf("Valid Identifier\n"); 
}
	
[a-zA-Z0-9.,;:+*/@$&_-]+ { 
	printf("Invalid Identifier\n"); 
}
%%

int main()
{
 	yylex();
	return 0;
}


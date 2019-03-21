%{
#include<stdio.h>
%}

%%

['][a-zA-Z0-9]['] {
	printf("Character constant");
}

["][a-zA-Z0-9]+["] {
	printf("String constant");
}

['"a-zA-Z0-9]+ {
	printf("Invalid");
}

%%

int main(){
	yylex();
	return 0;
}

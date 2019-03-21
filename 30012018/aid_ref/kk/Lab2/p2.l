%{
#include<stdio.h>
#include<string.h>
%};

%%
[0-9]+ {
	int i;
	int zero = 0;
	int one = 0;
	for(i=0;i<strlen(yytext);i++)
	{
		if(yytext[i] == '0')
			zero++;
		else if(yytext[i] == '1')
			one++;
		else break;
	}
	if(i != strlen(yytext) || zero%2 == 1 || one%1 == 1)
	{ printf("Valid String"); }
	else
	{ printf("Invalid String"); }
}

[a-zA-Z0-9]+ { 
printf("Invalid String"); 
}

%%

int main()
{
	yylex();
	return 0;
}

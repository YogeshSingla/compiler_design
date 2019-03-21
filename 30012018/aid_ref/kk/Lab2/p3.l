%{
#include<stdio.h>
#include<string.h>
%};

%%
-[1-9][0-9]+ { printf("Negative Decimal");}
[1-9][0-9]+ { printf("Positive Decimal"); }
-[0][x][0-9A-F]+ { printf("Negative Hexadecimal"); }
[0][x][0-9A-F]+ { printf("Positive Hexadecimal"); }
-[0-1]+ { printf("Negative Binary"); }
[0-1]+ { printf("Positive Binary"); }
-[0-7]+ { printf("Negative Octal"); }
[0-7]+ { printf("Positive Octal"); }
-[1-9][0-9]+[L] { printf("Negative Long Integer"); }
[1-9][0-9]+[L] { printf("Positive Long Integer"); }
%%

int main()
{
	yylex();
	return 0;
}

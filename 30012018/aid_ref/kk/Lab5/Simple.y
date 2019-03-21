%{

#include <string>
#include <map>
#include <cstdlib>
using namespace std;
int yylex();
int yyerror(const char *p)
{
	cerr<<"Error!"<<endl;
}
%}
%union{
 char sym;
}
%token <sym> TYPE ID COMMA ID STOP
%token <sym>TYPE FUNC LP TYPE ID COMMA TYPE ID RP STOP
%%
G1: | TYPE ID STOP { printf("Variable Declaration"); }
G2: | G1 COMMA ID STOP { printf("Variable Declaration"); }
G3: | TYPE ID LP TYPE ID RP STOP { printf("Function Declaration"); }
G4: | TYPE ID LP TYPE ID COMMA TYPE ID RP STOP { printf("Function Declaration"); }
%%
int main()
{
	yyparse();
	return 0;
}

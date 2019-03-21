%{
#include "Simple.tab.h"
#include <iostream>
using namespace std;
%}
%%
"void" {return TYPE;}
"int" {return TYPE;}
"char" {return TYPE;}
"float" {return TYPE;}
"(" { return LP; }
")" { return RP; }
";" { return STOP; }
"," { return COMMA;}
[a-zA-Z0-9]+   { yylval.sym = yytext[0]; return ID; }
<<EOF>> { return 0; }
[ \t\n ]+ { }
.  { cerr<<"Unrecognized token!" <<endl; exit(1); }
%%

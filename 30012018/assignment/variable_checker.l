/*recognize tokens for the variable_checker and print them out*/
%{
# include "variable_checker.tab.h"
%}
%%
"void" { printf("\nkeyword: void"); return KEYWORD;  }
"int" { printf("\nkeyword: int"); return KEYWORD; }
"char" { printf("\nkeyword: char"); return KEYWORD; }
"float" { printf("\nkeyword: float"); return KEYWORD; }
"," { printf("\nseparator: comma"); return SEPARATOR_COMMA; }
";" { printf("\nseparator: semicolon"); return SEPARATOR_SEMICOLON; }
"(" { printf("\nseparator: start_bracket"); return SEPARATOR_START_BRACKET; }
")" { printf("\nseparator: end_bracket"); return SEPARATOR_END_BRACKET; }
[a-zA-Z_][a-zA-Z0-9_]* { printf("\nidentifier"); return IDENTIFIER; }
\n { return EOL; }
[ \t] { /* ignore whitespace */ }
. { printf("Mystery character %c\n", *yytext); }
%%

/*
Write a FLEX application that will recognize valid identifiers having symbols a-z, A-Z, 0-0 and underscore(_). Each identifier should not start with a symbol from 0-9. Any other symbols like decimal point/full stop (.), comma(,), semi-colon(;), colon(+,-,*,/,@,$,& etc) are considered as invalid symbols.
*/
%{

%}

%%
[0-9]+[a-zA-Z_0-9]* { printf("invalid\n"); }
[a-zA-Z_]+[a-zA-Z_0-9]* { printf("valid\n"); }
. { printf("invalid symbol\n"); }


%%

main(int argc, char **argv)
{
yylex();
}

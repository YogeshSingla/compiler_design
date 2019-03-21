/*
Write a FLEX application that will identify signed/unsigned interger and long integer constants in decimal, hexadecimal, binary and octal representation used in C language.
*/

%{
%}

%%
(unsigned)[ ][a-z]* { printf("unsigned "); }
[+-] { printf("signed "); }
[0-9]+[lL] { printf("long"); }
[01]+ { printf("binary"); }
[0]+[0-7]+ { printf("octal"); }
[0-9]+[.][0-9]* { printf("decimal"); }
(0x)[0-9A-F]+ { printf("hexadecimal"); }
[0-9]+ { printf("int"); }

%%
main(int argc, char **argv)
{
yylex();
}


/*
Write a FLEX program that will identify character and string constants as defined in C language.
*/
%{
%}
%%
['][\\][a-z0]['] { printf("escape character"); }
['][a-zA-z0-9]['] { printf("character"); }
["][a-zA-z0-9 ]*["] { printf("string"); }
.* { printf("cannot be parsed"); }
%%
main(int argc, char ** argv){
yylex();
}

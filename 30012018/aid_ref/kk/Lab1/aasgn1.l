%{
int chars=0;
int words=0;
int lines=0;
int punctuations=0;
%};

%%
[a-zA-Z0-9]+ {words++; chars+=strlen(yytext);}
\n           {lines++; chars++;}
[. , : ; ? " '] { punctuations++; chars++;}
%%


main(int argc, char **argv)
{
  yylex();
printf("%8d%8d%8d%8d\n",chars,words,lines,punctuations);


}


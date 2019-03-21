%{
#include<stdio.h>
%}
%token HUNDRED
%token ONE
%token TWO 
%token THREE
%token FOUR
%token FIVE
%token SIX
%token SEVEN 
%token EIGHT
%token NINE
%token N
%token ZERO
%token TEN
%token ELEVEN
%token TWELVE
%token THIRTEEN
%token FOURTEEN
%token FIFTEEN
%token SIXTEEN
%token SEVENTEEN
%token EIGHTEEN
%token NINETEEN
%token TWENTY
%token THIRTY
%token FOURTY
%token FIFTY
%token SIXTY
%token SEVENTY
%token EIGHTY
%token NINETY
%%
beg:

EOL| beg s EOL {printf("\n");}
;
s: u
;
u: t d
| tp
| dp
;
t: h x
;
tp: h y
;
h:
| dpp
| d HUNDRED {printf("hundred");}
;
d:
| ONE {printf("one");}
| TWO {printf("two");}
| THREE {printf("three");}
| FOUR {printf("four");}
| FIVE {printf("five");}
| SIX {printf("six");}
| SEVEN {printf("seven");}
| EIGHT {printf("eight");}
| NINE {printf("nine");}
;
dp: ONE {printf("one");}
| TWO {printf("two");}
| THREE {printf("three");}
| FOUR {printf("four");}
| FIVE {printf("five");}
| SIX {printf("six");}
| SEVEN {printf("seven");}
| EIGHT {printf("eight");}
| NINE {printf("nine");}
| TEN {printf("ten");}
;
x:
| TWENTY {printf("twenty");}
| THIRTY {printf("thirty");}
| FORTY {printf("forty");}
| FIFTY {printf("fifty");}
| SIXTY {printf("sixty");}
| SEVENTY {printf("seventy");}
| EIGHTY {printf("eighty");}
| NINETY {printf("ninety");}
;
y: TEN {printf("ten");}
| ELEVEN {printf("eleven");}|
| TWELVE {printf("twelve");}
| THIRTEEN {printf("thirteen");}
| FOURTEEN {printf("fourteen");}
| FIFTEEN {printf("fifteen");}
| SIXTEEN {printf("sixteen");}
| SEVENTEEN {printf("seventeen");}
| EIGHTEEN {printf("eighteen");}
| NINETEEN {printf("nineteen");}
;
dpp: ONE {printf("one");}
| TWO {printf("two");}
| THREE {printf("three");}
| FOUR {printf("four");}
| FIVE {printf("five");}
| SIX {printf("six");}
| SEVEN {printf("seven");}
| EIGHT {printf("eight");}
| NINE {printf("nine");}
;
%%
main(int argc, char **argv)
{
yyparse();
}
yyerror(char *s1)
{
fprintf(stderr,"error: %s\n",s1);
}
yywrap()
{
return (1);
}

/* ref_as.y file */
%{
#include<stdio.h>
#include<stdlib.h>
%}
%token ONE
%token TWO
%token THREE
%token FOUR

%token FIVE
%token SIX
%token SEVEN
%token EIGHT
%token NINE
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
%token FORTY
%token FIFTY
%token SIXTY
%token SEVENTY
%token EIGHTY
%token NINETY
%token HUNDRED
%token EOL
%%
num:/*nothing*/
| a b c d EOL {printf("Valid Form\n\n\n");}
;
a:
| ONE
{printf("one\t");}
| TWO {printf("two\t");}
| THREE {printf("three\t");}
| FOUR {printf("four\t");}
| FIVE {printf("five\t");}
| SIX
{printf("six\t");}
| SEVEN {printf("seven\t");}
| EIGHT {printf("eight\t");}
| NINE {printf("nine\t");}
;
b:
| HUNDRED
{printf("hundred\t");}
;
c: ELEVEN
{printf("eleven\t");}
| TWELVE
{printf("twelve\t");}
| THIRTEEN {printf("thirteen\t");}
| FOURTEEN {printf("fourteen\t");}
| FIFTEEN
{printf("fifteen\t");}
| SIXTEEN
{printf("sixteen\t");}
| SEVENTEEN {printf("seventeen\t");}

| EIGHTEEN {printf("eighteen\t");}
| NINETEEN {printf("nineteen\t");}
| TWENTY
{printf("twenty\t");}
| THIRTY
{printf("thirty\t");}
| FORTY
{printf("forty\t");}
| FIFTY
{printf("fifty\t");}
| SIXTY
{printf("sixty\t");}
| SEVENTY {printf("seventy\t");}
| EIGHTY
{printf("eighty\t");}
| NINETY
{printf("ninenty\t");}
;
d:
| ONE {printf("one\t");}
| TWO {printf("two\t");}
| THREE {printf("three\t");}
| FOUR {printf("four\t");}
| FIVE {printf("five\t");}
| SIX {printf("six\t");}
| SEVEN {printf("seven\t");}
| EIGHT {printf("eight\t");}
| NINE {printf("nine\t");}
| TEN {printf("ten\t");} ;
%%
main(int argc, char **argv)
{
yyparse();
}
yyerror(char *s)
{
fprintf(stderr, "error: %s\n", s);
}

/* ref_as.l file */
%{
# include "ref_as.tab.h"
%}
%%
"hundred" {return HUNDRED;}
"one" {return ONE;}
"two" {return TWO;}
"three" {return THREE;}
"four" {return FOUR;}
"five" {return FIVE;}
"six" {return SIX;}
"seven" {return SEVEN;}
"eight" {return EIGHT;}
"nine" {return NINE;}
"ten" {return TEN;}
"eleven" {return ELEVEN;}
"twelve" {return TWELVE;}
"thirteen" {return THIRTEEN;}
"fourteen" {return FOURTEEN;}
"fifteen" {return FIFTEEN;}
"sixteen" {return SIXTEEN;}
"seventeen" {return SEVENTEEN;}
"eighteen" {return EIGHTEEN;}
"nineteen" {return NINETEEN;}
"twenty" {return TWENTY;}
"thirty" {return THIRTY;}
"forty" {return FORTY;}
"fifty" {return FIFTY;}
"sixty" {return SIXTY;}
"seventy" {return SEVENTY;}
"eighty" {return EIGHTY;}
"ninety" {return NINETY;}
\n {return EOL;}
[ \t] { /* ignore whitespace */ }
. { printf("Mystery character %c\n", *yytext); }
%%



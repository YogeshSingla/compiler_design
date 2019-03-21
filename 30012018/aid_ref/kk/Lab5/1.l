%{
#include "1.tab.h"
#include <string.h>
%}

%%
[a-zA-Z][a-zA-Z0-9]* {
	if(strcmp(yytext,"void")==0 || strcmp(yytext,"int")==0 || strcmp(yytext,"float")==0 || strcmp(yytext,"char")==0){
		return KEYW;
	}else{
		return ID;
	}
}

"," {
	return CO;
}

"(" {
	return LP;
}

")" {
	return RP;
}

";" {
	return TE;
}

[ \t\n] {

}

. {
	fprintf(stderr,"Unrecognized Token\n");
}
%%
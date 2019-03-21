%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASHSIZE 101
/*Definizione della Struttura della Symbol Table*/
struct nlist {
struct nlist *next;
char *name;
int value;
};
struct nlist *hashtab[HASHSIZE];
unsigned int hash(char *s);
struct nlist *lookup(char *s);
struct nlist *ins_attr(char *s,int i);
struct nlist *ins_token(char *name) ;
void yyerror (char const *);
int curr_attr;
%}
%token DATANUMERICA DATA FALSE TRUE ID AND OR NOT '(' ')' ',' ';' ':'
%token <string> VAR
%type <boolean> truth_value
%type <boolean> expr
%union {
int boolean;
char *string;
}
%left OR
%left AND
%right NOT
%start program
%%
program: date_declaration list_expr;
date_declaration:
DATA ':' DATANUMERICA ';'
;
list_expr:
/* empty expression */
|
expr maybe_vars ';' list_expr
;
maybe_vars:
/* empty list of vars */
|
':' nonempty_list_vars
;
nonempty_list_vars:
VAR ID {

ins_token($1);
ins_attr($1, curr_attr);
if (curr_attr)
printf("%s=TRUE;",$1);
else
printf("%s=FALSE;",$1);
}
|
VAR ID ',' nonempty_list_vars {
ins_token($1);
ins_attr($1, curr_attr);
if (curr_attr)
printf("%s=TRUE;",$1);
else
printf("%s=FALSE;",$1);
}
;
truth_value:
TRUE { $$ = 1; }
|
FALSE { $$ = 0; }
;
expr:
ID { $$=1; curr_attr = $$; }
|
truth_value { $$=$1; curr_attr = $$; }
|
'(' expr ')' { $$=$2; curr_attr = $$; }
|
expr OR expr { $$=($1 || $3); curr_attr = $$; }
|
expr AND expr { $$=($1 && $3); curr_attr = $$; }
|
NOT expr { $$=!$2; curr_attr = $$; }
;
%%
void yyerror (char const *s) {
fprintf(stderr, "%s\n", s);
}
int main() {
yyparse();
return 0;
}
unsigned int hash(char *s) {
/* calcolare HASH di s;*/
int h=0;
for(;*s!='\0';s++)
h=(127*h+*s)%HASHSIZE;
return h;
}
struct nlist *lookup(char *s) {
/* cercare s nella tabella HASH */
struct nlist *np;
for (np = hashtab[hash(s)]; np != NULL;np = np->next)
if (strcmp(s,np->name) == 0)
return np;
return NULL;

}
struct nlist *ins_attr(char *s,int i) {
/* cercare s nella tabella HASH e inserisce l'attributo i*/
struct nlist *np;
np=lookup(s);
if(np!=NULL){
np->value=i;
return np;
}
return NULL;
}
struct nlist *ins_token(char *name) {
/* inserire l'elemento di token */
struct nlist *np;
unsigned hashval;
if ((np = lookup(name)) == NULL) {/*se non è già presente*/
if ((np = (struct nlist *)malloc(sizeof(*np)))==NULL)
return NULL;
np->name = strdup(name);
np->value=0;
hashval = hash(name);
np->next = hashtab[hashval];
hashtab[hashval] = np;
}
return np;
}

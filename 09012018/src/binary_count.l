/*
Write a FLEX application that will recognize strings of odd numbers of 0's and even numbers of 1's.
*/
%{
int odd_0 = 0;
int even_1 = 0;
int zero=0;
int one=0;
%}

%%
[0] { zero++; printf("#zero=%d\n",zero);}
[1] { one++; printf("#one=%d\n",one);}

%%
/*

^0(0+0)*$ { printf("\nodd number of 0s"); }
^(11)(11)*$ { printf("even number of 1s"); }
 
*/
main(int argc, char **argv){
yylex();

if((zero%2==1)&&(one%2==0))
	printf("odd number of 0s and even number of 1s\n");
}

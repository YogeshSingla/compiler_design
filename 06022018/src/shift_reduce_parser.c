#include <stdio.h>

#define MAX_INPUT 100

char input[MAX_INPUT]={0};
char stack[MAX_INPUT]={0};

void main(){
	char ch;

	puts("Read input");

	while((ch = getchar())!='\0'){
		puts(ch);
	}
}
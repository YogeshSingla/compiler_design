#include<stdio.h>
//#include<conio.h>
#include<string.h>
#include<stdlib.h>
//#include<process.h>

void main()
{
//clrscr();
char s1[100],s2[100],o1[100],o2[100],temp1,temp2;
printf("Enter first statement:");
scanf("%s",s1);
printf("Enter second statement:");
scanf("%s",s2);
//printf("%c",s1[0]);
if(s1[0]!=s2[0])
{
printf("Sorry");
//getch();
exit(0);
}

o1[0]=s1[0];
o1[1]='-';
o1[2]='>';
int i=0;
for(i=3;s1[i]==s2[i];i++)
o1[i]=s1[i];
temp1=i;
temp2=i;

o1[i++]='Z';
o1[i++]='\0';
o2[0]='Z';
o2[1]='-';
o2[2]='>';
int p=3;
int j=temp1;
for(j=temp1;j<strlen(s1);j++)
{ o2[p]=s1[j];
p++;
}
o2[p++]='/';

for(j=temp2;j<strlen(s2);j++)
{
o2[p]=s2[j];
p++;
}
o2[p++]='\0';
puts(o1);
puts(o2);
//getch();
} 

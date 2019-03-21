#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int len=0;
int ss=0,ips=0;
void reduce();
int i=0,j=0,k=0,z=0;
char a[20],sh[10],sta[20],rede[25],redt[25],redf[25];
int main(){
 printf("Grammar is : E-> E+E \n E->E*E \n E->(E)|id ");
 printf("Enter the input string\n");
 gets(a);
 len=strlen(a);
 strcpy(sh,"SHIFT->");
 printf("stack \t reminputstring \t action \n");
 for(k=0,i=0;j<len;i++,j++,k++){
          if(a[j]=='i' && a[j+1]=='d')
           {
              ips++;
              sta[i]=a[j];
              sta[i+1]=a[j+1];
              sta[i+2]='\0';
              a[j]=' ';
              a[j+1]=' ';
              printf("\n$%s\t%s$\t%sid",sta,a,sh);
              reduce();
           }
           else
           {
              ips++;
              sta[i]=a[j];
              sta[i+1]='\0';
              a[j]=' ';
              printf("\n$%s\t%s$\t%s%c",sta,a,sh,sta[i]);
              reduce();
           }

  }
printf("\n");
ss++;
if(sta[0]=='E'&&sta[1]=='\0') 
  printf("string accepted\n");
else
  printf("string not accepted\n");

printf("No. of stack scans and input scans are : %d and %d respectively\n",ss,ips);
}


void reduce(){
   strcpy(rede,"REDUCE TO E");
   strcpy(redt,"REDUCE TO T");
   strcpy(redf,"REDUCE TO F");
   
    for(z=0; z<len; z++)
       if(sta[z]=='(' && sta[z+1]=='E' && sta[z+2]==')')
         {
              ss++;
           sta[z]='E';
           sta[z+1]='\0';
           sta[z+2]='\0';
           printf("\n$%s\t%s$\t%s",sta,a,redf);
           i=i-2;
         }
     for(z=0; z<len; z++)
       if(sta[z]=='i' && sta[z+1]=='d')
         {
           ss++;
           sta[z]='E';
           sta[z+1]='\0';
           printf("\n$%s\t%s$\t%s",sta,a,redf);
           j++;
         }
    
    for(z=0; z<len; z++)
       if(sta[z]=='E' && sta[z+1]=='*' && sta[z+2]=='E')
         {
           ss++;
           sta[z]='E';
           sta[z+1]='\0';
           sta[z+2]='\0';
           printf("\n$%s\t%s$\t%s",sta,a,rede);
           i=i-2;
         }
     for(z=0; z<len; z++)
       if(sta[z]=='E' && sta[z+1]=='+' && sta[z+2]=='E')
         {
           ss++;
           sta[z]='E';
           sta[z+1]='\0';
           sta[z+2]='\0';
           printf("\n$%s\t%s$\t%s",sta,a,rede);
           i=i-2;
         }
}

#include <stdio.h>
#include <string.h>

int k=0,z=0,i=0,j=0,c=0;
char a[16],ac[20],stk[15],act[10];

int f_flag=0;
int t_flag=0;

void check();

void check(){
  strcpy(ac,"REDUCE TO E");
  for(z=0; z<c; z++)
    //reduce id by E->T->F->id
    if(stk[z]=='i' && stk[z+1]=='d'){
      stk[z]='E';
      stk[z+1]='\0';

      printf("\n$%s\t%s$\t%s",stk,a,ac);
      j++;
    }

  for(z=0; z<c; z++)
    //reduce by E->E+E
    if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='E'){
      stk[z]='E';
      stk[z+1]='\0';
      stk[z+2]='\0';
      printf("\n$%s\t%s$\t%s",stk,a,ac);
      i=i-2;
      t_flag=1;
    }

  for(z=0; z<c; z++)
    //reduce by E->E*E
    if(stk[z]=='E' && stk[z+1]=='*' && stk[z+2]=='E'){
      stk[z]='E';
      stk[z+1]='\0';
      stk[z+1]='\0';
      printf("\n$%s\t%s$\t%s",stk,a,ac);
      i=i-2;
    }

  for(z=0; z<c; z++)
    //reduce by E->(E)
    if(stk[z]=='(' && stk[z+1]=='E' && stk[z+2]==')'){
      stk[z]='E';
      stk[z+1]='\0';
      stk[z+1]='\0';
      printf("\n$%s\t%s$\t%s",stk,a,ac);
      i=i-2; 

      f_flag=1;
    }
}

void main(){
  //stk is the stack 
  //a is the input string
  //act is the action to be taken
  puts("GRAMMAR is E->E+E \n E->E*E \n E->(E) \n E->id");
  puts("Enter input string: ");
  gets(a);
  //c stores length of string
  c=strlen(a);
  strcpy(act,"SHIFT->");
  puts("stack \t input \t action");
  for(k=0,i=0; j<c; k++,i++,j++)
   {
     if(a[j]=='i' && a[j+1]=='d')
       {
          //push id to stack and remove from input string
          stk[i]=a[j];
          stk[i+1]=a[j+1];
          stk[i+2]='\0';
          a[j]=' ';
          a[j+1]=' ';
          //print stack trace
          printf("\n$%s\t%s$\t%sid",stk,a,act);
          //check for shift-reduce
          check();
       }
     else
       {
          stk[i]=a[j];
          stk[i+1]='\0';
          a[j]=' ';
          printf("\n$%s\t%s$\t%ssymbols",stk,a,act);
          check();
       }
   }

   //printf("my: %s",stk);
   if(f_flag==0 && t_flag==0){
   // if(stk[0]=='E' && stk[1]!=' ')
    printf("\nNOT PARSED COMPLETELY. INVALID INPUT");
   }

   printf("\n\n");
}

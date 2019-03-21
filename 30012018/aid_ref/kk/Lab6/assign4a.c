 #include<stdio.h>
//#include<conio.h>
#include<string.h>
int k=0,z=0,i=0,j=0,c=0;
char a[16],ac[20],stk[15],act[10];
void check();
void main()
   {
  
      puts("GRAMMAR is \n E->E+T|T \n T->T*F|F \n F->(E)|id \n");
      puts("enter input string ");
    //  gets(a);
     /* for(i=0;i<16;i++)
      {
       scanf("%c",&a[i]);
      }*/
      scanf("%s",a);
      c=strlen(a);
      strcpy(act,"SHIFT->");
      puts("stack \t\t\t input \t\t\t action");
      for(k=0,i=0; j<c; k++,i++,j++)
       {
         if(a[j]=='i' && a[j+1]=='d')
           {
              stk[i]=a[j];
              stk[i+1]=a[j+1];
              stk[i+2]='\0';
              a[j]=' ';
              a[j+1]=' ';
              printf("\n$%s\t\t\t%s$\t\t\t%sid",stk,a,act);
              check();
           }
         else
           {
              stk[i]=a[j];
              stk[i+1]='\0';
              a[j]=' ';
              printf("\n$%s\t\t\t%s$\t\t\t%ssymbols",stk,a,act);
              check();
           }
       }
     if(stk[1]!='\0')
      printf("\nInput string is not accepted\n");
     else
     printf("\nInput string is accepted\n");
    
   }
void check()
   {
     strcpy(ac,"REDUCE TO a");
     for(z=0; z<c; z++)
       if(stk[z]=='i' && stk[z+1]=='d')
         {
           stk[z]='a';
           stk[z+1]='\0';
           printf("\n$%s\t\t\t%s$\t\t\t%s",stk,a,ac);
           j++;
         }
     for(z=0; z<c; z++)
       if(stk[z]=='a' && stk[z+1]=='+' && stk[z+2]=='a')
         {
           stk[z]='a';
           stk[z+1]='\0';
           stk[z+2]='\0';
           printf("\n$%s\t\t\t%s$\t\t\t%s",stk,a,ac);
           i=i-2;
         }
     for(z=0; z<c; z++)
       if(stk[z]=='a' && stk[z+1]=='*' && stk[z+2]=='a')
         {
           stk[z]='a';
           stk[z+1]='\0';
           stk[z+2]='\0';
           printf("\n$%s\t\t\t%s$\t\t\t%s",stk,a,ac);
           i=i-2;
         }
     for(z=0; z<c; z++)
       if(stk[z]=='(' && stk[z+1]=='a' && stk[z+2]==')')
         {
           stk[z]='a';
           stk[z+1]='\0';
           stk[z+2]='\0';
           printf("\n$%s\t\t\t%s$\t\t\t%s",stk,a,ac);
           i=i-2; 
         }
    
   }



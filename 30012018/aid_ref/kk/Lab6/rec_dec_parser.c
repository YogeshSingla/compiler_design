#include<stdio.h>
#include<ctype.h>
#include<string.h>
 

void E();
void check(); 

 
 
char expression[10];
int count, flag;
 
int main()
{
      count = 0;
      flag = 0;
      printf("\nEnter an Algebraic Expression:\t");
      scanf("%s", expression);
      E();

      if((strlen(expression) == count) && (flag == 0))
      {
            printf("\nThe Expression %s is Valid\n", expression);
      }
      else 
      {
            printf("\nThe Expression %s is Invalid\n", expression);
      }
}
                    
void E()
{
	if(expression[count]=='a' && expression[count-1]!='a' && expression[count-1]!='b' &&expression[count-1]!='c')
	{
		count++;
		if(count<strlen(expression))
		{
			E();
		}
	}
	else if(expression[count]=='b'  && expression[count-1]!='a' && expression[count-1]!='b' &&expression[count-1]!='c')
	{
		count++;
		if(count<strlen(expression))
		{
			E();
		}
	}
	else if(expression[count]=='c' && expression[count-1]!='a' && expression[count-1]!='b' &&expression[count-1]!='c')
	{
		count++;
		if(count<strlen(expression))
		{
			E();
		}
	}	
	else if(expression[count]=='+')
	{
				
		count++;		
		if(expression[count]=='+' || expression[count]=='*')
		{
			printf("hello");
			flag=1;
		}
		E();
	}
	else if(expression[count]=='*')
	{
		count++;
		
		if(expression[count]=='+' || expression[count]=='*')
		{
			flag=1;
		}
		E();
	}
}	
 

 
void check()
{
      if(isalnum(expression[count]))
      {
            count++;
      }
      else if(expression[count] == '(')
      {
            count++;
            E();
            if(expression[count] == ')')
            {
                  count++;
            }
            else
            {
                  flag = 1; 
            }
      }         
      else
      {
            flag = 1;
      }
}
 


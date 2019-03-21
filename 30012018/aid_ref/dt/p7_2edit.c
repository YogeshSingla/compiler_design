#include<ctype.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

char gram[10][10],vFirst[10],nonT[10],vFollow[10];
char frst[10][10] = {'0'}, fol[10][10] = {'0'};
int m=0,p,i=0,j=0;
int elem[10],size,fPt,k=0;
int getGram()
{
	char ch;
	int i,j,k;
	printf("\n Enter number of productions: ");
	scanf("%d",&size);
	printf("\n Enter grammar in the form of A=A+B and $ for epsilon. Here in o/p $ also represents bottomost stack symbol and z represents epsillon\n");
	for(i=0;i<size;i++)
	{
		scanf("%s%c",gram[i],&ch);
		elem[i]=strlen(gram[i]);
	}
}
int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}
int f_First(char ch)
{
	//int j,i;
	if(!(isupper(ch)))
		vFirst[k++]=ch;
	else
	{
		for(j=0;j<size;j++)
		{
			if(gram[j][0]==ch)
			{
				if(gram[j][2]=='$')
				{
					//frst[i][k++] = 'z';
					vFirst[k++]='z';
				}	
				else if(islower(gram[j][2]))
				{
					//frst[i][k++] = gram[j][2];
					vFirst[k++]=gram[j][2];
				}	
				else
				{
					f_First(gram[j][2]);
				}	
			}
		}
	}
}
void first(char ch)
{
	int k;
	if(!(isupper(ch)))
	{
		//fol[i][m++] = ch;
		vFollow[m++]=ch;
	}
	for(k=0;k<size;k++)
	{
		if(gram[k][0]==ch)
		{
			if(gram[k][2]=='$')
				f_Follow(gram[i][0]);
			else if(islower(gram[k][2]))
			{
				//fol[i][m++] = gram[k][2];
				vFollow[m++]=gram[k][2];
			}			
			else
				first(gram[k][2]);
		}
	}
}
void f_Follow(char ch)
{
	if(gram[0][0]==ch)
	{
		//fol[i][m++] = '$';
		vFollow[m++]='$';
	}
	for(i=0;i<size;i++)
	{
		for(j=2;j<strlen(gram[i]);j++)
		{
			if(gram[i][j]==ch)
			{
				if(gram[i][j+1]!='\0')
					first(gram[i][j+1]);
				if(gram[i][j+1]=='\0' && ch!=gram[i][0])
					f_Follow(gram[i][0]);
			}
		}
	}
}
void fifi(int *y, int *f)
{
	for(i=0; i<strlen(vFirst); i++)
	{
		for(j=0; j<strlen(vFirst); j++)
		{
			if(i!=j)
			{
				if(frst[*y][i]==frst[*y][j] && frst[*y][i]!='0')
				{
					*f = 1;
					break;
				}
			}
		}
	}
}
void fifo(int *y, int *f)
{
	for(i=0; i<strlen(vFirst); i++)
	{
		for(j=0; j<strlen(vFollow); j++)
		{
			if(frst[*y][i]==fol[*y][j] && frst[*y][i]!='0')
			{
				*f = 1;
				break;
			}
		}
	}
}
void check_llone(int l)
{
	
	//first set
	/*printf("\n first set \n");
	for(i=0; i<l; i++)
	{
		j = 0;
		while(j<10)
		{
			printf("%c ", frst[i][j]);
			j++;
		}
		printf("\n");
	}*/
	/*for(i=0; i<l; i++)
	{
		qsort(frst[i], 10, sizeof(int *), comp);
		qsort(fol[i], 10, sizeof(int *), comp);
	}
	for(i=0; i<l; i++)
	{
		j = 0;
		while(j<10)
		{
			printf("%c ", frst[i][j]);
			j++;
		}
		printf("\n");
	}*/
	int f = 0;
	for(i=0; i<l; i++)
	{
		fifi(&i, &f);
		if(f==1)
		{
			printf("\n Not LL(1) grammar \n");
			break;	
		}	
		else
		{
			int x = 0;
			for(i=0; i<size; i++)
			{
				if(gram[i][0]==nonT[i] && gram[i][2]=='$')
				{
					x = 1;
					break;
				}
			}
			if(x==1)
			{
				fifo(&i, &f);
				if(f==1)
				{
					printf("\n Not LL(1) grammar \n");
					break;	
				}
			}
		}
	}
	if(f==0)
	{
		printf("\n It is LL(1) grammar \n");
	}
}

int main()
{
	int i,j,l=0;
	//int p = 0;
	getGram();
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			if(gram[i][0]==gram[j][0])
				break;
		}
		if(i==j)
		{
			nonT[l]=gram[i][0];
			l++;
		}
	}
	for(i=0;i<l;i++)
	{
		k=0;
		f_First(nonT[i]);
		printf("\n First of %c is { ",nonT[i]);
		for(j=0;j<strlen(vFirst);j++)
		{
			printf(" %c",vFirst[j]);
			frst[i][j] = vFirst[j];
		}
		printf(" }\n");
	}
	int s=0;
	for(s=0;s<l;s++)
	{
		m=0;
		printf("\n Follow of %c is { ",nonT[s]);
		f_Follow(nonT[s]);
		for(i=0;i<m;i++)
		{
			printf("%c ",vFollow[i]);
			fol[s][i] = vFollow[i];
		}		
		printf(" }\n");
	}
	check_llone(l);
	return 0;
}
					

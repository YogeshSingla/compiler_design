#define M 1000
#define N 1048576
#include<math.h>
int main()
{
int C[N],A[M+1],B[M+1];
register unsigned int i,j,b;
for(i=0;i<(M+1);i++)
A[i]=rand();
b=((unsigned int)C/sizeof(int));
i=0;
if(b%16!=0)
 {
   for(j=b%16;j<16;j++,i++)//prologue loop
       C[i]=0;
 }
b=N-(N%16);
if((N-i)>=16)
{
 for(;i<b;i+=16)//unrolled loop
   {
    C[i]=0;
    C[i+1]=0;
    C[i+3]=0;
    C[i+2]=0;
    C[i+6]=0;
    C[i+7]=0;
    C[i+5]=0;
    C[i+4]=0;
    C[i+12]=0;
    C[i+13]=0;
    C[i+15]=0;
    C[i+14]=0;
    C[i+10]=0;
    C[i+11]=0;
    C[i+9]=0;
    C[i+8]=0;
   }
 }
for(;i<N;i++)//epilogue loop
    C[i]=0;
for(i=1;i<=M;i++)
  C[A[i]]=C[A[i]]+1;
for(i=1;i<=N;i++)
  C[i]=C[i]+C[i-1];
for(i=M;i>=0;i--)
  {
    B[C[A[i]]]=A[i];
    C[A[i]]=C[A[i]]-1;
  }
return 0;
}

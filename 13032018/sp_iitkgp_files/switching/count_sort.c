#define M 1000
#define N 1048576
#include<math.h>
int main()
{
int C[N],A[M+1],B[M+1];
register int i;
for(i=0;i<(M+1);i++)
 A[i]=rand(); 
for(i=0;i<N;i++)
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

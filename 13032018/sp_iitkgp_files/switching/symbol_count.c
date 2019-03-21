#define M 1048576
#define N 1000
#include<math.h>
int main()
 {
  int string[N];
  int count[M];
  register int i;
  for(i=0;i<N;i++)
      string[i]=rand();
  for(i=0;i<M;i++)
     count[i]=0;
  for(i=0;i<N;i++)
      count[string[i]]++;
  return 0;
 }

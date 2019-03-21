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
  for(i=0;i<M;i+=16)
    {
     count[i]=0;
     count[i+1]=0;
     count[i+2]=0;
     count[i+3]=0;
     count[i+4]=0;
     count[i+5]=0;
     count[i+6]=0;
     count[i+7]=0;
     count[i+8]=0;
     count[i+9]=0;
     count[i+10]=0;
     count[i+11]=0;
     count[i+12]=0;
     count[i+13]=0;
     count[i+14]=0;
     count[i+15]=0;
    }
  for(i=0;i<N;i++)
      count[string[i]]++;
  return 0;
 }

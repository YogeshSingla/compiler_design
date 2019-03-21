#define W 1000000
#define n 3
struct knapsack_trace
     {
        int a;
        int last_added; 
     };
int main() 
{
struct knapsack_trace kt[W];
        int c[n] = {0, 1, 2}; 
        int v[n]= {3, 4, 5};
	register int i,j,b;
b=((unsigned int)kt)/sizeof(struct knapsack_trace);
i=0;
if(b%16!=0)
 {
   for(j=b%16;j<16;j++,i++)//prologue loop
      {
       kt[i].a=0;
       kt[i].last_added = 0x80000000;
      }
 }
b=W-(W%16);
if((W-i)>=16)
{
	for(;i<b;i+=16)//unrolled loop 
           {
             kt[i].a=0;
             kt[i+1].a=0;
             kt[i+3].a=0;
             kt[i+2].a=0;
             kt[i+6].a=0;
             kt[i+7].a=0;
             kt[i+5].a=0;
             kt[i+4].a=0;
             kt[i+12].a=0;
             kt[i+13].a=0;
             kt[i+15].a=0;
             kt[i+14].a=0;
             kt[i+10].a=0;
             kt[i+11].a=0;
             kt[i+9].a=0;
             kt[i+8].a=0;
             kt[i].last_added = 0x80000000;
             kt[i+1].last_added = 0x80000000;
             kt[i+3].last_added = 0x80000000;
             kt[i+2].last_added = 0x80000000;
             kt[i+6].last_added = 0x80000000;
             kt[i+7].last_added = 0x80000000;
             kt[i+5].last_added = 0x80000000;
             kt[i+4].last_added = 0x80000000;
             kt[i+12].last_added = 0x80000000;
             kt[i+13].last_added = 0x80000000;
             kt[i+15].last_added = 0x80000000;
             kt[i+14].last_added = 0x80000000;
             kt[i+10].last_added = 0x80000000;
             kt[i+11].last_added = 0x80000000;
             kt[i+9].last_added = 0x80000000;
             kt[i+8].last_added = 0x80000000;
	   }
 }
for(;i<W;i++)//epilogue loop
   {
    kt[i].a=0;
    kt[i].last_added = 0x80000000;
   }
	for(i=1;i<=W;i++)
           {
		for(j=0;j<n;j++)
                   {
			if ((c[j]<=i)&&(kt[i].a<kt[i-c[j]].a+v[j])) 
                           {
				kt[i].a=kt[i-c[j]].a+v[j];
                                kt[i].last_added = j;
			   }
                   }
           }
 return 0;
}

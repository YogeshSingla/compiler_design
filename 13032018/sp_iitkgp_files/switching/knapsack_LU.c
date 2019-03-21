#define W 1000000
#define n 3
int main() 
{
	int a[W];
        int last_added[W]; 
        int c[n] = {0, 1, 2}; 
        int v[n]= {3, 4, 5};
	register int i, j;
	for(i=0;i<W;i+=16) 
           {
             a[i]=0;
             a[i+1]=0;
             a[i+2]=0;
             a[i+3]=0;
             a[i+4]=0;
             a[i+5]=0;
             a[i+6]=0;
             a[i+7]=0;
             a[i+8]=0;
             a[i+9]=0;
             a[i+10]=0;
             a[i+11]=0;
             a[i+12]=0;
             a[i+13]=0;
             a[i+14]=0;
             a[i+15]=0;
             last_added[i] = -1;
             last_added[i+1] = -1;
             last_added[i+2] = -1;
             last_added[i+3] = -1;
             last_added[i+4] = -1;
             last_added[i+5] = -1;
             last_added[i+6] = -1;
             last_added[i+7] = -1;
             last_added[i+8] = -1;
             last_added[i+9] = -1;
             last_added[i+10] = -1;
             last_added[i+11] = -1;
             last_added[i+12] = -1;
             last_added[i+13] = -1;
             last_added[i+14] = -1;
             last_added[i+15] = -1;
	   }
     	for(i=1;i<=W;i++)
           {
		for(j=0;j<n;j++)
                   {
			if ((c[j]<=i)&&(a[i]<a[i-c[j]]+v[j])) 
                           {
				a[i]=a[i-c[j]]+v[j];
                                last_added[i] = j;
			   }
                   }
           }
 return 0;
}

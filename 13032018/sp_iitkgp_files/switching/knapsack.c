#define W 1000000
#define n 3
int main() 
{
	int a[W];
        int last_added[W]; 
        int c[n] = {0, 1, 2}; 
        int v[n]= {3, 4, 5};
	register int i, j;
	for(i=0;i<W;i++) 
           {
		a[i]=0;
                last_added[i] = -1;
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

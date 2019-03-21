#include <bits/stdc++.h>
using namespace std;

const clock_t c_time = clock();
int main()
{
	int X[1000] = {0};
	int Y[1024] = {0};
	int total[1024]= {0};
	int i = 0;
	for(i=0;i<1024;i++)
     {
       total[i] = X[i]+Y[i];
//	   cout<<total[i]<<"\n";     
     }
    cout<<"Output derived in "<<float( clock () - c_time ) /  CLOCKS_PER_SEC<<"ms\n";
	return 0;
}
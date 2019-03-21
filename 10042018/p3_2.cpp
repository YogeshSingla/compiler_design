//loop enrolling factor = 4
#include <bits/stdc++.h>
using namespace std;

const clock_t c_time = clock();
int main()
{
	int X[1000] = {0};
	int Y[1024] = {0};
	int total[1024]= {0};
	int i = 0;
	for(i=0;i<1024;i += 4)
     {
       total[i] = X[i]+Y[i];
	   total[i+1] = X[i+1]+Y[i+1];
	   total[i+2] = X[i+2]+Y[i+2];
	   total[i+3] = X[i+3]+Y[i+3]; 
	 //  cout<<total[i]<<"\n"<<total[i+1]<<"\n"<<total[i+2]<<"\n"<<total[i+3]<<"\n";     
     }
    cout<<"Output derived in "<<float( clock () - c_time ) /  CLOCKS_PER_SEC<<"ms\n";
	return 0;
}
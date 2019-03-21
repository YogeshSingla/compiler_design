#include <bits/stdc++.h>
using namespace std;


int main()
{
	const clock_t c_time = clock();
	
	int P[1000];
	int i = 0;
	for(i=0;i<1000;i++)
    { 
    	P[i]=2-i%2;
        //cout<<"For i = "<<i<<" "<<P[i]<<"\n";
    }
    cout<<"Output derived in "<<float( clock () - c_time ) /  CLOCKS_PER_SEC<<"ms\n";
	return 0;
}
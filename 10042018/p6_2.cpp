#include <bits/stdc++.h>
using namespace std;

int foo(int n) {
   int sum=0;
   int i;
   for (i = 0; i < n; ++i) {
          sum +=5+2*(i+1);
   }
 return sum;
} 

int main()
{
    const clock_t c_time = clock();
    
	foo(1000000);

    cout<<"Output derived in "<<float( clock () - c_time ) <<" units\n";
	return 0;
}
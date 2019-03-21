// C++ program to find out execution time of
// of functions
#include <algorithm>
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;
 
 //measure time of this function
   extern int sum;
    int foo(int n) {
       int i, j;
       j = 5;
       for (i = 0; i < n; ++i) {
              j += 2;
              sum += j;
       }
     return sum;
    }

#define LOOP_COUNT 10000

int main(){
 
 	long time[LOOP_COUNT];
 	long sum=0;

 	for(int i=0;i<LOOP_COUNT;i++){

	    // Get starting timepoint
	    auto start = high_resolution_clock::now();
	 
	    // Call the function, here sort()
	    foo();
	 
	    // Get ending timepoint
	    auto stop = high_resolution_clock::now();
	    // Get duration. Substart timepoints to 
	    // get durarion. To cast it to proper unit
	    // use duration cast method
	    auto duration = duration_cast<microseconds>(stop - start);
	    
	    time[i] = duration.count();
	    sum+=time[i];
	 }

	cout << "Average time taken by function: "
	         << sum/LOOP_COUNT << " microseconds" << endl;
    return 0;
}
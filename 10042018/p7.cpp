// C++ program to find out execution time of
// of functions
#include <algorithm>
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;
 
 //measure time of this function
 void myfunction(){
  int x = 0;
  int y = 10;
  int z = 20;
  long n = 50000;	//50 thousand elements in array
  int a[n];

  int x2 = x*x;

  for (int i = 0; i < n; i++) {
       	//Change 1 : Move this statement outside the loop
       	//x = y + z; 
  	   	//Result : Time of program execution reduces by 20 microseconds. 
  		//A ~16% increase in performance.
      	
      	a[i] = 6 * i + x * x;

      	//Change 2 : Replace x*x by another variable.
      	// a[i] = 6 * i + x2;
      	//Result : Time of program execution reduces by 
      	//a[i] = 6 * i + x2;
   }
   x = y + z;
   
 }

#define LOOP_COUNT 10000

int main(){
 
 	long time[LOOP_COUNT];
 	long sum=0;

 	for(int i=0;i<LOOP_COUNT;i++){

	    // Get starting timepoint
	    auto start = high_resolution_clock::now();
	 
	    // Call the function, here sort()
	    myfunction();
	 
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
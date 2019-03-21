#include <bits/stdc++.h>
using namespace std;


int main()
{
    const clock_t c_time = clock();
    
	int A[16][16];
    int B[16][16];
    int C[16][16];

    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            A[i][j] = rand()%100;
            B[i][j] = rand()%100;
        }
    }

    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            for(int k=0;k<16;k++){
                C[i][j] = A[i][k] * B[k][j];
            }
        }
    }

    cout<<"Output derived in "<<float( clock () - c_time ) <<" units\n";
	return 0;
}
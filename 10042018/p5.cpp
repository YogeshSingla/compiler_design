#include <ctime>
#include <iostream>
using namespace std;
int
main(int, const char**)
{
     int a[1000][1000];
     int i,j;
     std::clock_t    start;
     start = std::clock();
     for(i=0;i<10;i++)
          for(j=0;j<1000;j++)
               a[i][j]=0;
    for(i=0;i<1000;i++)
          a[i][i]=0;
     std::cout << "Time before: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
          std::clock_t    strt;
    strt = std::clock();
     for(i=0;i<10;i++)
  {
          for(j=0;j<1000;j++)
               a[i][j]=0;
          a[i][i]=0;
  }
    std::clock_t nd;
          std::cout << "Time after: " << (std::clock() - strt) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
     return 0;
}
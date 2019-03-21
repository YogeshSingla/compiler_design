#include<math.h>
#define n 512
struct treasure_island_path_cost
      {
        int max_treasure_path;/*stores the path from (1,1) to (n,n) with maximized treasure cost*/
        int Treasure_cost_Table;/*memoization of subproblems solved, so that it can be used solve the same subproblem on demand in future*/
      };
int main()
{
 register int i,j,k,b,m;
 int treasure_island[n][n];/*stores treasure cost at each grid*/
 struct treasure_island_path_cost tipc[n][n];  
 for(i=0;i<n;i++)
 { 
   for(j=0;j<n;j++)
    {
     treasure_island[i][j]=rand();
    }
 }
b=((unsigned int)tipc)/sizeof(struct treasure_island_path_cost);
for(i=0;i<n;i++)
  {
    j=0;
    if(b%16!=0)
     {
       for(k=b%16;k<16;k++,j++)//prologue loop
         {
          tipc[i][j].max_treasure_path=0;
          tipc[i][j].Treasure_cost_Table = 0x80000000;
         }
     }
   m=n-(n%16);
   if((n-i)>=16)
    {
     for(j=0;j<m;j+=16)
      {
       tipc[i][j].max_treasure_path=0;
       tipc[i][j+1].max_treasure_path=0;
       tipc[i][j+3].max_treasure_path=0;
       tipc[i][j+2].max_treasure_path=0;
       tipc[i][j+6].max_treasure_path=0;
       tipc[i][j+7].max_treasure_path=0;
       tipc[i][j+5].max_treasure_path=0;
       tipc[i][j+4].max_treasure_path=0;
       tipc[i][j+12].max_treasure_path=0;
       tipc[i][j+13].max_treasure_path=0;
       tipc[i][j+15].max_treasure_path=0;
       tipc[i][j+14].max_treasure_path=0;
       tipc[i][j+10].max_treasure_path=0;
       tipc[i][j+11].max_treasure_path=0;
       tipc[i][j+9].max_treasure_path=0;
       tipc[i][j+8].max_treasure_path=0;
       tipc[i][j].Treasure_cost_Table=0;
       tipc[i][j+1].Treasure_cost_Table=0;
       tipc[i][j+3].Treasure_cost_Table=0;
       tipc[i][j+2].Treasure_cost_Table=0; 
       tipc[i][j+6].Treasure_cost_Table=0;
       tipc[i][j+7].Treasure_cost_Table=0;
       tipc[i][j+5].Treasure_cost_Table=0;
       tipc[i][j+4].Treasure_cost_Table=0;
       tipc[i][j+12].Treasure_cost_Table=0;
       tipc[i][j+13].Treasure_cost_Table=0;
       tipc[i][j+15].Treasure_cost_Table=0;
       tipc[i][j+14].Treasure_cost_Table=0; 
       tipc[i][j+10].Treasure_cost_Table=0;
       tipc[i][j+11].Treasure_cost_Table=0;
       tipc[i][j+9].Treasure_cost_Table=0;
       tipc[i][j+8].Treasure_cost_Table=0;
     }
    }
  for(;j<n;j++)//epilogue loop
   {
    tipc[i][j].max_treasure_path=0;
    tipc[i][j].Treasure_cost_Table=0;
   }
  } 
   tipc[n][n].Treasure_cost_Table=treasure_island[n][n];
   for(i=n-1;i>=0;i--)
     {
       for(j=n-1;j>=0;j--)
         {
           if((i<n-1)&&(j==n-1))
              { 
                tipc[i][j].max_treasure_path=1;
                tipc[i][j].Treasure_cost_Table=treasure_island[i][j]+tipc[i+1][j].Treasure_cost_Table;// move up
              }
           else
           if((i==n-1)&&(j<n-1))  
              { 
                tipc[i][j].max_treasure_path=2;
                tipc[i][j].Treasure_cost_Table=treasure_island[i][j]+tipc[i][j+1].Treasure_cost_Table;// move right
              }
           else
              {        
                 if(tipc[i+1][j].Treasure_cost_Table>tipc[i][j+1].Treasure_cost_Table)
                   {
                      tipc[i][j].max_treasure_path=1;//move up
                      tipc[i][j].Treasure_cost_Table=treasure_island[i][j]+tipc[i+1][j].Treasure_cost_Table;
                   }
                 else
                   {
                      tipc[i][j].max_treasure_path=2;//move right
                      tipc[i][j].Treasure_cost_Table=treasure_island[i][j]+tipc[i][j+1].Treasure_cost_Table;
                   }
              }
         }
     }
 return 0;
}



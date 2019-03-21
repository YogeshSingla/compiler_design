#include<math.h>
#define n 512
int main()
{
 register int i,j;
 int treasure_island[n][n];/*stores treasure cost at each grid*/
 int max_treasure_path[n][n];/*stores the path from (1,1) to (n,n) with maximized treasure cost*/
 int Treasure_cost_Table[n][n];/*memoization of subproblems solved, so that it can be used solve the same subproblem on demand in future*/
 for(i=0;i<n;i++)
 { 
   for(j=0;j<n;j++)
    {
     treasure_island[i][j]=rand();
    }
 }
for(i=0;i<n;i++)
  {
    for(j=0;j<n;j+=16)
     { 
      max_treasure_path[i][j]=0;
      max_treasure_path[i][j+1]=0;
      max_treasure_path[i][j+2]=0;
      max_treasure_path[i][j+3]=0;
      max_treasure_path[i][j+4]=0;
      max_treasure_path[i][j+5]=0;
      max_treasure_path[i][j+6]=0;
      max_treasure_path[i][j+7]=0;
      max_treasure_path[i][j+8]=0;
      max_treasure_path[i][j+9]=0;
      max_treasure_path[i][j+10]=0;
      max_treasure_path[i][j+11]=0;
      max_treasure_path[i][j+12]=0;
      max_treasure_path[i][j+13]=0;
      max_treasure_path[i][j+14]=0;
      max_treasure_path[i][j+15]=0;
      Treasure_cost_Table[i][j]=0;
      Treasure_cost_Table[i][j+1]=0;
      Treasure_cost_Table[i][j+2]=0;
      Treasure_cost_Table[i][j+3]=0; 
      Treasure_cost_Table[i][j+4]=0;
      Treasure_cost_Table[i][j+5]=0;
      Treasure_cost_Table[i][j+6]=0;
      Treasure_cost_Table[i][j+7]=0;  
      Treasure_cost_Table[i][j+8]=0;
      Treasure_cost_Table[i][j+9]=0;
      Treasure_cost_Table[i][j+10]=0;
      Treasure_cost_Table[i][j+11]=0; 
      Treasure_cost_Table[i][j+12]=0;
      Treasure_cost_Table[i][j+13]=0;
      Treasure_cost_Table[i][j+14]=0;
      Treasure_cost_Table[i][j+15]=0;  
     }
  } 
   Treasure_cost_Table[n][n]=treasure_island[n][n];
   for(i=n-1;i>=0;i--)
     {
       for(j=n-1;j>=0;j--)
         {
           if((i<n-1)&&(j==n-1))
              { 
                max_treasure_path[i][j]=1;
                Treasure_cost_Table[i][j]=treasure_island[i][j]+Treasure_cost_Table[i+1][j];// move up
              }
           else
           if((i==n-1)&&(j<n-1))  
              { 
                max_treasure_path[i][j]=2;
                Treasure_cost_Table[i][j]=treasure_island[i][j]+Treasure_cost_Table[i][j+1];// move right
              }
           else
              {        
                 if(Treasure_cost_Table[i+1][j]>Treasure_cost_Table[i][j+1])
                   {
                      max_treasure_path[i][j]=1;//move up
                      Treasure_cost_Table[i][j]=treasure_island[i][j]+Treasure_cost_Table[i+1][j];
                   }
                 else
                   {
                      max_treasure_path[i][j]=2;//move right
                      Treasure_cost_Table[i][j]=treasure_island[i][j]+Treasure_cost_Table[i][j+1];
                   }
              }
         }
     }
 return 0;
}



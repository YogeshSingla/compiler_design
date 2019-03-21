#define WHITE 0
#define GRAY 1
#define BLACK 2
#define N 1024
void DFS_Visit(int,int[][],int[],int[]);
int main()
{
 int color[N];
 int path[N];
 int graph[N][N];
 register int i,j;
  for(i=0;i<N;i++)
    {
       for(j=0;j<N;j++)
        {
          if(i==j)
            graph[i][j]=0;
          else
            graph[i][j]=rand()%2;
        }
     }
 for(i=0;i<N;i+=16)
  {
    color[i]=WHITE;
    color[i+1]=WHITE;
    color[i+2]=WHITE;
    color[i+3]=WHITE;
    color[i+4]=WHITE;
    color[i+5]=WHITE; 
    color[i+6]=WHITE;
    color[i+7]=WHITE;
    color[i+8]=WHITE;
    color[i+9]=WHITE;
    color[i+10]=WHITE;
    color[i+11]=WHITE;
    color[i+12]=WHITE;
    color[i+13]=WHITE; 
    color[i+14]=WHITE;
    color[i+15]=WHITE;
    path[i]=-1;
    path[i+1]=-1;
    path[i+2]=-1;
    path[i+3]=-1;
    path[i+4]=-1;
    path[i+5]=-1;
    path[i+6]=-1;
    path[i+7]=-1;
    path[i+8]=-1;
    path[i+9]=-1;
    path[i+10]=-1;
    path[i+11]=-1;
    path[i+12]=-1;
    path[i+13]=-1;
    path[i+14]=-1;
    path[i+15]=-1;
  }   
 for(i=0;i<N;i++)
  {
   if(color[i]==WHITE)
        DFS_Visit(i,graph,color,path);
  }
 return 0;
}
void DFS_Visit(int u,int graph[][N],int color[],int path[])
 {
  register int v;
  color[u]=GRAY;
  for(v=0;v<N;v++)
    {
     if((graph[u][v]==1)&&(color[v]==WHITE))
        {
          path[v]=u;
          DFS_Visit(v,graph,color,path);
        }
    }
   color[u]=BLACK;
 }

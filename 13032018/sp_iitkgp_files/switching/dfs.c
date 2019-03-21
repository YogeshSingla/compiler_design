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
 for(i=0;i<N;i++)
  {
    color[i]=WHITE;
    path[i]=-1;
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

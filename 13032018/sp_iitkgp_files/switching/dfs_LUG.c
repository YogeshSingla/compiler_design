#define WHITE 0
#define GRAY 1
#define BLACK 2
#define N 1024
struct color_path
 { 
  int color;
  int path;
 };
void DFS_Visit(int,int[][],struct color_path[]);
int main()
{
 register unsigned int i,j,b;
 struct color_path cp[N];
  int graph[N][N];
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
b=((unsigned int)cp)/sizeof(struct color_path);
i=0;
if(b%16!=0)
 {
   for(j=b%16;j<16;j++,i++)//prologue loop
      {
       cp[i].color=0;
       cp[i].path=0;
      }
 }
b=N-(N%16);
if((N-i)>=16)
{
 for(;i<b;i+=16)
  {
    cp[i].color=WHITE;
    cp[i+1].color=WHITE;
    cp[i+3].color=WHITE;
    cp[i+2].color=WHITE;
    cp[i+6].color=WHITE;
    cp[i+7].color=WHITE; 
    cp[i+5].color=WHITE;
    cp[i+4].color=WHITE;
    cp[i+12].color=WHITE;
    cp[i+13].color=WHITE;
    cp[i+15].color=WHITE;
    cp[i+14].color=WHITE;
    cp[i+10].color=WHITE;
    cp[i+11].color=WHITE; 
    cp[i+9].color=WHITE;
    cp[i+8].color=WHITE;
    cp[i].path=0x80000000;
    cp[i+1].path=0x80000000;
    cp[i+3].path=0x80000000;
    cp[i+2].path=0x80000000;
    cp[i+6].path=0x80000000;
    cp[i+7].path=0x80000000;
    cp[i+5].path=0x80000000;
    cp[i+4].path=0x80000000;
    cp[i+12].path=0x80000000;
    cp[i+13].path=0x80000000;
    cp[i+15].path=0x80000000;
    cp[i+14].path=0x80000000;
    cp[i+10].path=0x80000000;
    cp[i+11].path=0x80000000;
    cp[i+9].path=0x80000000;
    cp[i+8].path=0x80000000;
  }
}   
for(;i<N;i++)//epilogue loop
   {
    cp[i].color=0;
    cp[i].path=0x80000000;
   }
 for(i=0;i<N;i++)
  {
    if(cp[i].color==WHITE)
        DFS_Visit(i,graph,cp);
  }
 return 0;
}
void DFS_Visit(int u,int graph[][N],struct color_path cp[])
 {
  register int v;
  cp[u].color=GRAY;
  for(v=0;v<N;v++)
    {
     if((graph[u][v]==1)&&(cp[v].color==WHITE))
        {
          cp[v].path=u;
          DFS_Visit(v,graph,cp);
        }
    }
   cp[u].color=BLACK;
 }

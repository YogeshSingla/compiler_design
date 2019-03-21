#include<dos.h>
union REGS i,o;
 initmouse();
int getmousepos(int *button,int*x,int*y);
 showmouseptr();
 restrictmouseptr(int x1,int y1,int x2,int y2);
void hide(void);
void mouse()
{
restrictmouseptr(1,1,616,192);
initmouse();
showmouseptr();
}
 initmouse()
  {
   i.x.ax=0;
   int86(0x33,&i,&o);
   return (o.x.ax);
  }
int showmouseptr()
{
i.x.ax=1;
int86(0x33,&i,&o);
return 0;
}
 restrictmouseptr(int x1,int y1,int x2,int y2)
{
i.x.ax=7;
i.x.cx=x1;
i.x.dx=x2;
int86(0x33,&i,&o);
i.x.ax=8;
i.x.cx=y1;
i.x.dx=y2;
int86(0x33,&i,&o);
return 0;
}
int getmousepos(int *button,int*x,int*y)
{
i.x.ax=3;
int86(0x33,&i,&o);
*button=o.x.bx;
*x=o.x.cx/8;
*y=o.x.dx/8;
return 0;
}
void hide(void)
{
i.x.ax=2;
int86(0x33,&i,&o);
}

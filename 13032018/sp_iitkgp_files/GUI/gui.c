#include<stdio.h>
#include<conio.h>
#include"menu.h"
#include"mouse.h"
#include<alloc.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
union REGS rg1,rg2;
struct stu
 {
   char name[25];
   int roll;
   char course[15];
   int fees;
   struct stu*m;
 }*p,*q,*start1;
struct staff
 {
   char n[25];
   int eno;
   char dept[15];
   int sal;
   struct staff*v;
 }*a,*b,*start2;
void company(void)
{
int i;
textbackground(GREEN);
textcolor(RED);
for(i=0;i<=78;i++)
cprintf(" ");
gotoxy(32,1);
cprintf("USHA    INFOTECH ");
printf("\n");
textbackground(BLACK);
textcolor(WHITE);
}
char reportmenu(int*n);
char editmenu(int*n);
int STAR(void);
char entrymenu(int*n);
int design(char ch,int x);
int entrysub(void);
int repsub(void);
int editsub(void);
void ss(int);
void ss2(int);
void ss3(int);
void enter(int);
void report(int);
void edit(int I);
void menupaint()
{
textbackground(MAGENTA);
textcolor(WHITE);
}
void firstletter()
{
     textbackground(WHITE);
     textcolor(RED);
}
void rest()
{
 textbackground(LIGHTGREEN);
 textcolor(BLUE);
}
void screendesign()
{
int i,x,y,z;
char ch,t;
clrscr();
  textbackground(RED);
  for(x=1;x<=80;x++)
   for(y=1;y<=24;y++)
    {
     gotoxy(x,y);
     cprintf(" ");
    }
  textcolor(YELLOW);
gotoxy(1,1);
for(i=0;i<=79;i++)
  {
   cprintf("%c",196);
  }
gotoxy(1,1);
cprintf("%c",218);
for(i=0;i<=22;i++)
  {
  gotoxy(1,i+2);
   cprintf("%c",179);
  }
gotoxy(1,i+2);
cprintf("%c",192);
for(i=0;i<=76;i++)
  {
   cprintf("%c",196);
  }
cprintf("%c",217);
for(i=22;i>=0;i--)
  {
   gotoxy(79,i+2);
   cprintf("%c",179);
  }
gotoxy(79,1);
cprintf("%c",191);
gotoxy(2,3);
for(i=0;i<=76;i++)
  {
cprintf("%c",196);
  }
}
void menudesign()
{
int i;
for(i=2;i<=78;i++)
{
gotoxy(i,2);
textbackground(LIGHTGREEN);
 cprintf(" ");
}
menupaint();
firstletter();
gotoxy(5,2);
cprintf("E");
rest();
cprintf("NTRY");
gotoxy(35,2);
cprintf("E");
firstletter();
cprintf("D");
rest();
cprintf("IT");
gotoxy(65,2);
firstletter();
cprintf("R");
rest();
cprintf("EPORT");
_setcursortype(_NOCURSOR);
mouse();
gotoxy(2,2);
firstletter();
cprintf("*");
}
void main()
{
  char ch,S;
  int x,z,p,q,px,py,button,a,b,c;
   char pw[6];
 int i,flag;
 char *pass="SONAI";
clrscr();
  x=0;
  z=0;
  p=0;
 a=1;b=1;c=1;
 textbackground(BLACK);
 textcolor(GREEN);
mouse();
_setcursortype(_SOLIDCURSOR);
do
{
clrscr();
cprintf("\nENTER A PASS WORD OF FIVE CHARACTERS:");
gotoxy(38,2);
i=0;
do
   {
  getmousepos(&button,&px,&py);
  ch=getch();
    S=ch;
    if(ch==0)
    ch=getch();
    if(((ch==75)||(ch==8))&&(i>0))
    {
     gotoxy(wherex()-1,2);
     cprintf(" ");
     i--;
     gotoxy(wherex()-1,2);
    }
   else
    if((S!=13)&&((S>=65)&&(S<=122)))
    {
    pw[i++]=S;
    cprintf("*");
    }
   }while(S!=13);
pw[i]='\0';
for(i=0;pass[i]!='\0';i++)
 {
  if(toupper(pw[i])==pass[i])
   flag=1;
   else
   {
   flag=0;
   break;
   }
}
}while(flag!=1);
_setcursortype(_NOCURSOR);
screendesign();
menudesign();
gotoxy(2,2);
menupaint();
cprintf("*");
do
{
getmousepos(&button,&px,&py);
if(kbhit())
{
ch=getch();
if(ch==0)
   {
	    ch=getch();
   if((ch==77)||(ch==75)||((ch==80)&&(z==0)))
      {
	     menudesign();
	     clear();
	   if(ch==77)
	    {
		 p:
		 if(x==4)
		  x=0;
		  design(ch,++x);
	    }
	    else
	   if(ch==75)
	   {
	     q:
	   if(x==0)
	   x=4;
	   design(ch,--x);
	   }
	     else
	   if((ch==80)&&(z==0))
	     {
	       design(p,x);
	       z=1;
	      }			   if(z==1)
				    {
				    if(x==1)
				    {
				      ch=entrymenu(&a);
				       getmousepos(&button,&px,&py);
				       menudesign();
					  clear();
				    if(ch==77)
				    {
				      goto p;
				    }
				    else
				    if(ch==75)
				    {
				      goto q;
				    }
				    else
				    if(ch==18)
				      {
				      x--;
				      goto p;
				      }
				     else
				    if(ch==32)
				    {
				      goto p;
				    }
				      else
				    if(ch==19)
				    {
				      x++;
				      goto p;
				    }
				   else
				    if((ch=='t')||(ch=='s')||(ch==13)||(ch=='T')||(ch=='S'))
				       {
				       x=-1;
				       goto p;
				       }
				  }
				    else
				    if(x==2)
				    {
				    ch=editmenu(&b);
				      getmousepos(&button,&px,&py);
					 menudesign();
				       clear();
					if(ch==77)
					{
					goto p;
				    }
				    else
				    if(ch==75)
				    {
				      goto q;
				    }
				    else
				    if(ch==18)
				      {
				       goto q;
				      }
				     else
				    if(ch==32)
				    {
				      x++;
				      goto q;
				    }
				      else
				    if(ch==19)
				    {
					goto p;
				    }
				   else
				    if((ch=='T')||(ch=='t')||(ch==13)||(ch=='S')||(ch=='s')||(ch=='A')||(ch=='a')||(ch=='u')||(ch=='U'))
				       {
				       x=-1;
				       goto p;
				       }
				    }
				   else
				    if(x==3)
				    {
				    ch=reportmenu(&c);
				      getmousepos(&button,&px,&py);
				       menudesign();
				       clear();
				       if(ch==77)
					{

				       goto p;
				    }

				    else
				    if(ch==75)
				    {
				      goto q;
				    }
				    else
				    if(ch==18)
				      {
				      x--;
				      goto q;
				      }
				     else
				    if(ch==32)
				    {
				      goto q;
				    }
				      else
				    if(ch==19)
				    {
				      x--;
				      goto p;
				    }
				   else
				    if((ch=='t')||(ch=='s')||(ch==13)||(ch=='T')||(ch=='S'))
				       {
				       x=-1;
				       goto p;
				       }

				    }

				    }

		 }

			    else
			   if((ch==18)||(ch==32)||(ch==19))
			    {

			     clear();
			      menudesign();
			      x=design(ch,x);
				     z=1;
				if(ch==18)
			       {
			       ch=entrymenu(&a);
				      getmousepos(&button,&px,&py);
				      menudesign();
				       clear();
					if(ch==77)
					{

				       goto p;
				     }

				    else
				    if(ch==75)
				    {
				      goto q;
				    }
				    else
				    if(ch==18)
				      {
				      x--;
				      goto p;
				      }
				     else
				    if(ch==32)
				    {
				      goto p;
				    }
				      else
				    if(ch==19)
				    {
				      x++;
				      goto p;
				    }
				     else
				     if((ch=='t')||(ch=='s')||(ch==13)||(ch=='T')||(ch=='S'))
				       {
				       x=-1;
				       goto p;
				       }

else
if((button==2)&&(px==1)&&(py==1))
break;
else
if((px>=3)&&(px<=9)&&(py==1)&&(button==1))
{
ch=18;
z=1;
x=0;
STAR();
goto p;
}
else
if((px>=33)&&(px<=38)&&(py==1)&&(button==1))
{
ch=32;
z=1;
x=1;
STAR();
goto p;
}
}

				  else
			      if(ch==32)
			      {
			      ch=editmenu(&b);
				      getmousepos(&button,&px,&py);
				 menudesign();
			      clear();
					if(ch==77)
					{
					goto p;
					 }

				    else
				    if(ch==75)
				    {
				      goto q;
				    }
				    else
				    if(ch==18)
				      {
				       goto q;
				      }
				     else
				    if(ch==32)
				    {
				      x++;
				      goto q;
				    }
				      else
				    if(ch==19)
				    {
					goto p;
				    }
				   else
				    if((ch=='T')||(ch=='t')||(ch==13)||(ch=='S')||(ch=='s')||(ch=='A')||(ch=='a')||(ch=='u')||(ch=='U'))
				       {
				       x=-1;
				       goto p;
					       }


				    }

				  else
			      if(ch==19)
			       {
				    ch=reportmenu(&c);
				      getmousepos(&button,&px,&py);
				       menudesign();
				       clear();
				       if(ch==77)
					{

				       goto p;
				    }

				    else
				    if(ch==75)
				    {
				      goto q;
				    }
				    else
				    if(ch==18)
				      {
				      x--;
				      goto q;
				      }
				     else
				    if(ch==32)
				    {
				      goto q;
				    }
				      else
				    if(ch==19)
				    {
				      x--;
				      goto p;
				    }
				   else
				    if((ch=='t')||(ch=='s')||(ch==13)||(ch=='T')||(ch=='S'))
				       {
				       x=-1;
				       goto p;
				       }

				}

		    }

   }
   if((ch==13)&&(z==0))
  {
     z=1;
     if(x==1)
				    {
				    ch=entrymenu(&a);
				      getmousepos(&button,&px,&py);
				       menudesign();
				       clear();
				       if(ch==77)
					{

				       goto p;
				    }

				    else
				    if(ch==75)
				    {
				      goto q;
				    }
				    else
				    if(ch==18)
				      {
				      x--;
				      goto p;
				      }
				     else
				    if(ch==32)
				    {
				      goto p;
				    }
				      else
				    if(ch==19)
				    {
				      x++;
				      goto p;
				    }
				    else
				    if((ch=='t')||(ch=='s')||(ch==13)||(ch=='T')||(ch=='S'))
				       {
				       x=-1;
				       goto p;
				       }

				    }

     else
     if(x==2)
     {
     ch=editmenu(&b);
				      getmousepos(&button,&px,&py);
			      menudesign();
			      clear();
					if(ch==77)
					{
					goto p;
					 }
				    else
				    if(ch==75)
				    {
				      goto q;
				    }
				    else
				    if(ch==18)
				      {
				       goto q;
				      }
				     else
				    if(ch==32)
				    {
				      x++;
				      goto q;
				    }
				      else
				    if(ch==19)
				    {
					goto p;
				    }
				   else
				    if((ch=='T')||(ch=='t')||(ch==13)||(ch=='S')||(ch=='s')||(ch=='A')||(ch=='a')||(ch=='u')||(ch=='U'))
				       {
				       x=-1;
				       goto p;
					       }

}
				 else
				 if(x==3)
			      {
				    ch=reportmenu(&c);
				      getmousepos(&button,&px,&py);
					      menudesign();
				       clear();
				       if(ch==77)
					{

				       goto p;
				    }

				    else
				    if(ch==75)
				    {
				      goto q;
				    }
				    else
				    if(ch==18)
				      {
				      x--;
				      goto q;
				      }
				     else
				    if(ch==32)
				    {
				      goto q;
				    }
				      else
				    if(ch==19)
				    {
				      x--;
				      goto p;
				    }
				   else
				    if((ch=='t')||(ch=='s')||(ch==13)||(ch=='T')||(ch=='S'))
				    {
				       x=-1;
				       goto p;
				       }

				    }

     }
  else
      if(z==0)
       {

	  if((ch=='E')||(ch=='e'))
	  {
	   menudesign();
	   x=design(ch,1);
	  }
	  else
	  if((ch=='D')||(ch=='d'))
	    {
	    menudesign();
	    x=design(ch,2);
	    }
	  else
	  if((ch=='R')||(ch=='r'))
	   {
	   menudesign();
	   x=design(ch,3);
	   }
       }
p=ch;
 }
if((button==2)&&(px==1)&&(py==1))
break;
else
if((px>=3)&&(px<=9)&&(py==1)&&(button==1))
{
ch=18;
z=1;
x=0;
menudesign();
goto p;
}
else
if((px>=33)&&(px<=38)&&(py==1)&&(button==1))
{
ch=32;
z=1;
x=1;
menudesign();
goto p;
}
else
if((px>=63)&&(px<=70)&&(py==1)&&(button==1))
{
ch=19;
z=1;
x=2;
menudesign();
goto p;
}
}
while(ch!=27);
textbackground(BLACK);
textcolor(WHITE);
clrscr();
hide();
_setcursortype(_NORMALCURSOR);
}
int design(char ch,int x)
{
if((ch==77)||(ch==75)||(ch=='E')||(ch=='R')||(ch=='D')||(ch=='e')||(ch=='d')||(ch=='r'))
     {

      if(x==1)
       ch=18;
       else
       if(x==2)
       ch=32;
      else
      if(x==3)
      ch=19;

    }

   if((x>=0)&&(x<=4))
   menupaint();

   if(ch==18)
     {
	 x=1;
      gotoxy(5,2);
cprintf("ENTRY");
       }
     else
       if(ch==32)
     {
	 x=2;
	    gotoxy(35,2);
     cprintf("EDIT");
 }
	else
	if(ch==19)
      {
	 x=3;
      gotoxy(65,2);

cprintf("REPORT");
 }
      if((x==4)||(x==0))
      {
      gotoxy(2,2);
      cprintf("*");
     }
     return x;
}
int STAR(void)
{
     gotoxy(2,2);
      textbackground(WHITE);
     textcolor(RED);
     cprintf("*");
return 0;
}
char entrymenu(int*n)
{
int x,y,px,py,button;
char ch;
gotoxy(9,3);
textbackground(WHITE);
textcolor(MAGENTA);
cprintf("%c",218);
for(x=10;x<=25;x++)
 {
  gotoxy(x,3);
  cprintf("%c",196);
 }
for(x=4;x<11;x++)
 {
  gotoxy(9,x);
  cprintf("%c",179);
 }
gotoxy(9,x-1);
cprintf("%c",192);
for(x=10;x<25;x++)
 {
    cprintf("%c",196);
 }
cprintf("%c",217);
for(x=9;x>3;x--)
 {
  gotoxy(25,x);
  cprintf("%c",179);
 }
 gotoxy(25,x);
 cprintf("%c",191);
 textbackground(LIGHTGREEN);
for(x=10;x<=24;x++)
 for(y=4;y<=9;y++)
   {
   gotoxy(x,y);
   cprintf(" ");
   }
do
{
  entrysub();
   ss(*n);
  delay(200);
   getmousepos(&button,&px,&py);
    if((button==1)&&(px>=10)&&(px<=16)&&(py==4))
  {
    *n=1;
  ss(*n);
ch=1;
  enter(1);
  break;
  }
   else
  if((button==1)&&(px>=10)&&(px<=16)&&(py==6))
  {
   *n=2;
   ss(*n);
 ch=1;
  enter(2);
  break;
  }
else
if((button==1)&&((px>=33)&&(px<=38)&&(py==1)))
{
 ch=32;
 break;
}
else
if((button==1)&&((px>=63)&&(px<=70)&&(py==1)))
{
 ch=19;
 break;
}
else
if((button==2)&&(px==1)&&(py==1))
  {
  ch=27;
  break;
  }
  else
if((button==1)&&!((px>=3)&&(px<=8)&&(py==1)))
{
 ch=1;
 break;
}
else
   getmousepos(&button,&px,&py);
    if((button==1)&&(px>=10)&&(px<=16)&&(py==4))
  {
    *n=1;
  ss(*n);
ch=1;
  enter(1);
  break;
  }
   else
  if((button==1)&&(px>=10)&&(px<=16)&&(py==6))
  {
   *n=2;
   ss(*n);
 ch=1;
  enter(2);
  break;
  }
else
if((button==1)&&((px>=33)&&(px<=38)&&(py==1)))
{
 ch=32;
 break;
}
else
if((button==1)&&((px>=63)&&(px<=70)&&(py==1)))
{
 ch=19;
 break;
}
else
if((button==2)&&(px==1)&&(py==1))
  {
  ch=27;
  break;
  }
  else
if((button==1)&&!((px>=3)&&(px<=8)&&(py==1)))
{
 ch=1;
 break;
}
else
  if(kbhit())
  {
   ch=getch();
  if((ch=='t')||(ch=='T'))
 {
 *n=1;
 ss(*n);
enter(1);
 break;
 }
 else
 if((ch=='f')||(ch=='F'))
 {
     *n=2;
    ss(*n);
enter(2);
 break;
 }

 else
 {
 if(ch==0)
 {
ch=getch();
   if(ch==80)
     {
	(*n)++;
	 if(*n==3)
	  *n=1;
     }
     else
    if(ch==72)
    {
    (*n)--;
    if(*n==0)
      *n=2;
    }
   else
   if((ch==75)||(ch==77)||(ch==18)||(ch==19)||(ch==32))
   break;
}
   else
   if(ch==13)
   {
   enter(*n);
   break;
   }
  }
 }
}while(ch!=27);
return ch;
}
int entrysub(void)
{
 gotoxy(11,5);
 textbackground(LIGHTGREEN);
 textcolor(BLUE);
 cprintf("STUDEN");
 textbackground(BLACK);
  textcolor(WHITE);
   cprintf("T");
 gotoxy(11,7);
 textbackground(LIGHTGREEN);
 textcolor(BLUE);
 cprintf("STAF");
textbackground(BLACK);
 textcolor(WHITE);
   cprintf("F");
 textbackground(LIGHTGREEN);
   cprintf("  ");
return 0;
}
char editmenu(int*n)
{
int x,y,px,py,button;
char ch;
gotoxy(23,3);
textbackground(WHITE);
textcolor(MAGENTA);
cprintf("%c",218);
for(x=24;x<=45;x++)
 {
  gotoxy(x,3);
  cprintf("%c",196);
 }
for(x=4;x<22;x++)
 {
  gotoxy(23,x);
  cprintf("%c",179);
 }
gotoxy(23,x-1);
cprintf("%c",192);
for(x=23;x<44;x++)
 {
    cprintf("%c",196);
 }
cprintf("%c",217);
for(x=wherey()-1;x>3;x--)
 {
  gotoxy(45,x);
  cprintf("%c",179);
 }
 gotoxy(45,x);
 cprintf("%c",191);
 textbackground(LIGHTGREEN);
for(x=24;x<=44;x++)
 for(y=4;y<21;y++)
   {
   gotoxy(x,y);
   cprintf(" ");
   }
do
{
  editsub();
  ss3(*n);
   delay(200);
   getmousepos(&button,&px,&py);
    if((button==1)&&(px>=25)&&(px<=38)&&(py==4))
  {
    *n=1;
  ss3(*n);
ch=1;
  edit(1);
  break;
  }
   else
  if((button==1)&&(px>=25)&&(px<=38)&&(py==6))
  {
   *n=2;
   ss3(*n);
 ch=1;
  edit(2);
  break;
  }
   else
  if((button==1)&&(px>=25)&&(px<=38)&&(py==8))
  {
   *n=3;
   ss3(*n);
   ch=1;
   edit(3);
  break;
  }
   else
  if((button==1)&&(px>=25)&&(px<=38)&&(py==10))
  {
   *n=4;
   ss(*n);
 ch=1;
  edit(4);
  break;
  }
else
   if((button==1)&&((px>=3)&&(px<=9)&&(py==1)))
  {
  ch=18;
  break;
  }
else
if((button==1)&&((px>=63)&&(px<=70)&&(py==1)))
{
 ch=19;
 break;
}
else
if((button==2)&&(px==1)&&(py==1))
  {
  ch=27;
  break;
  }
  else
if((button==1)&&!((px>=3)&&(px<=8)&&(py==1)))
{
 ch=1;
 break;
}
else
  if(kbhit())
  {
  ch=getch();
   {
  if((ch=='S')||(ch=='s'))
   {
    *n=1;
    ss3(*n);
   edit(1);
 break;
 }
 else
 if((ch=='T')||(ch=='t'))
 {
   *n=2;
   ss3(*n);
 edit(2);
   break;
 }
 else
 if((ch=='U')||(ch=='u'))
 {
   *n=3;
   ss3(*n);
 edit(2);
 break;
 }
  else
 if((ch=='A')||(ch=='a'))
 {
 *n=4;
    ss3(*n);
   edit(2);
break;
 }
 else
 if(ch==0)
 {
ch=getch();
   if(ch==80)
     {
	 (*n)++;
	 if(*n==5)
	  *n=1;
     }
     else
    if(ch==72)
    {
    (*n)--;
    if(*n==0)
      *n=4;
    }
   else
   if((ch==75)||(ch==77)||(ch==18)||(ch==19)||(ch==32))
   break;
  }
   else
   if(ch==13)
   {
  edit(*n);
   break;
   }
  }
 }
}while(ch!=27);
return ch;
}
char reportmenu(int*n)
{
int x,y,button,px,py;
char ch;
gotoxy(60,3);
textbackground(WHITE);
textcolor(MAGENTA);
cprintf("%c",218);
for(x=61;x<=75;x++)
 {
  gotoxy(x,3);
  cprintf("%c",196);
 }
for(x=4;x<11;x++)
 {
  gotoxy(60,x);
  cprintf("%c",179);
 }
gotoxy(60,x-1);
cprintf("%c",192);
for(x=61;x<=75;x++)
 {
    cprintf("%c",196);
 }
cprintf("%c",217);
for(x=wherey()-1;x>3;x--)
 {
  gotoxy(76,x);
  cprintf("%c",179);
 }
 gotoxy(76,x);
 cprintf("%c",191);
 textbackground(LIGHTGREEN);
for(x=61;x<=75;x++)
 for(y=4;y<10;y++)
   {
   gotoxy(x,y);
   cprintf(" ");
   }
do
{
  repsub();
  ss2(*n);
  getmousepos(&button,&px,&py);
  delay(200);
 if((button==1)&&(px>=64)&&(px<=71)&&(py==4))
  {
   *n=1;
   ss2(*n);
  ch=1;
  report(1);
  break;
  }
   else
  if((button==1)&&(px>=64)&&(px<=71)&&(py==6))
  {
   *n=2;
   ss2(*n);
  ch=1;
  report(2);
  break;
  }
  else
   if((button==1)&&((px>=3)&&(px<=9)&&(py==1)))
  {
  ch=18;
  break;
  }
  else
   if((button==1)&&((px>=33)&&(px<=38)&&(py==1)))
  {
  ch=32;
  break;
  }
 else
if((button==2)&&(px==1)&&(py==1))
{
ch=27;
break;
}
else
if((button==1)&&!((px>=63)&&(px<=70)&&(py==1)))
{
 ch=1;
 break;
}
else
if(kbhit())
  {
  ch=getch();
 if((ch=='t')||(ch=='T'))
 {
    *n=1;
    ss2(*n);
report(1);
 break;
 }
 else
 if((ch=='f')||(ch=='F'))
 {
     *n=2;
    ss2(*n);
report(2);
 break;
 }

 else
 {
 if(ch==0)
 {
ch=getch();
   if(ch==80)
     {
	 (*n)++;
	 if(*n==3)
	  *n=1;
     }
     else
    if(ch==72)
    {
    (*n)--;
    if(*n==0)
	*n=2;
    }
   else
   if((ch==75)||(ch==77)||(ch==18)||(ch==19)||(ch==32))
   break;
}
   else
   if(ch==13)
   {
  report(*n);
   break;
   }
  }
 }
}while(ch!=27);
return ch;
}
void enter(int x)
{
  int j;
  char ch;
FILE *S,*E;
  clrscr();
  _setcursortype(_NORMALCURSOR);
    if(x==1)
    {

S=fopen("STUDENT.DAT","a");
	  start1=NULL;
     do
     {

       p=(struct stu*)malloc(sizeof(struct stu));
    cprintf("\nNAME:");
      gets(p->name);
       for(j=strlen(p->name);j<24;j++)
       p->name[j]=' ';
       p->name[j]='\0';
       fflush(stdin);
      printf("\nROLL:");
     scanf("%d",&p->roll);
      fflush(stdin);
	 printf("\nCOURSE:");
      gets(p->course);
      for(j=strlen(p->course);j<14;j++)
	p->course[j]=' ';
	p->course[j]='\0';
	    fflush(stdin);
     printf("\nFEES:");
     scanf("%d",&p->fees);
	fflush(stdin);
  fprintf(S,"%s%8d     %s%10d\n",p->name,p->roll,p->course,p->fees);
	  p->m=NULL;
    if(start1==NULL)
	  start1=p;
	  else
	  {
	   q=start1;
	   while(q->m!=NULL)
	    q=q->m;
	    q->m=p;
	 }
	  printf("\npress any key to continue or esc to exit:\n");
      ch=getch();
      }while(ch!=27);
   }
   else
      if(x==2)
    {
     E=fopen("STAFF.DAT","a");
      start2=NULL;
      do
     {
       a=(struct staff*)malloc(sizeof(struct staff));
	 cprintf("\nNAME:");
      gets(a->n);
       for(j=strlen(a->n);j<24;j++)
	a->n[j]=' ';
	a->n[j]='\0';
       fflush(stdin);
      printf("\nEMP.NO.:");
     scanf("%d",&a->eno);
      fflush(stdin);
	 printf("\nDEPARTMENT:");
      gets(a->dept);
      for(j=strlen(a->dept);j<14;j++)
	a->dept[j]=' ';
	a->dept[j]='\0';
	    fflush(stdin);
     printf("\nSALARY:");
     scanf("%d",&a->sal);
	fflush(stdin);
  fprintf(E,"%s%10d      %s%17d\n",a->n,a->eno,a->dept,a->sal);
	  a->v=NULL;
	  if(start2==NULL)
	  start2=a;
	  else
	  {
	   b=start2;
	   while(b->v!=NULL)
	    b=b->v;
	    b->v=a;
	  }
  printf("\npress any key to continue or esc to exit:\n");
      ch=getch();


      }while(ch!=27);

   }
     fcloseall();
_setcursortype(_NOCURSOR);
screendesign();
menudesign();
menupaint();
gotoxy(2,2);
cprintf("*");
}

void ss(int n)
{
 textbackground(BLACK);
 textcolor(WHITE);
 if(n==1)
  {
  gotoxy(11,5);
  cprintf("Student");
  }
  else
  if(n==2)
  {
  gotoxy(11,7);
  cprintf("Staff  ");

  }
}
void ss3(int n)
{
 textbackground(BLACK);
 textcolor(WHITE);
if(n==1)
  {
    gotoxy(25,5);
    cprintf("STUDENT SEARCH");
 }
 else
 if(n==2)
 {
 gotoxy(25,7);
 cprintf("STAFF SEARCH  ");
 }
else
if(n==3)
{
gotoxy(25,9);
cprintf("STUDENT DELETE");
}
else
if(n==4)
{
 gotoxy(25,11);
  cprintf("STAFF DELETE  ");
}
}
void ss2(int n)
{
 textbackground(BLACK);
 textcolor(WHITE);
 if(n==1)
  {
  gotoxy(65,5);
  cprintf("Student");
  }
  else
  if(n==2)
  {
  gotoxy(65,7);
  cprintf("Staff  ");

  }
}
int repsub(void)
{
 gotoxy(65,5);
 textbackground(LIGHTGREEN);
 textcolor(BLUE);
 cprintf("STUDEN");
 textbackground(BLACK);
 textcolor(WHITE);
 cprintf("T");
 gotoxy(65,7);
 textbackground(LIGHTGREEN);
 textcolor(BLUE);
 cprintf("STAF");
 textbackground(BLACK);
 textcolor(WHITE);
   cprintf("F");
 textbackground(LIGHTGREEN);
    cprintf("  ");
return 0;
}
void report(int x)
{
  int i=0,j=0,px,py,button;
  char STR;
  FILE *S,*E;
  clrscr();
  _setcursortype(_NOCURSOR);
   if(x==1)
   {
     S=fopen("STUDENT.DAT","r");
     company();
     printf("NAME\t\t\t    ROLL     COURSE\t\t FEES\n................................................................................\r");
     while((STR=fgetc(S))!=EOF)
      {
     if(i==1240)
      {
       i=0;
       printf("\rPRESS ANY KEY TO CONTINUE.\r");
       getch();
       clrscr();
       company();
       printf("NAME\t\t\t    ROLL     COURSE\t\t FEES\n................................................................................\r");
      }
       i++;
       printf("%c",STR);
       if(i%62==0)
       j++;

     }
 printf("\n               TOTAL STUDENTS :%d",j);
 }
   else
   if(x==2)
    {
     E=fopen("STAFF.DAT","r");
       company();
       printf("NAME\t\t\t    EMP.NO.     DEPARTMENT\t\t SALARY\n................................................................................\r");
     while((STR=fgetc(E))!=EOF)
     {
       if(i==1440)
      {
       i=0;
       printf("\rPRESS ANY KEY TO CONTINUE.\r");
       getch();
       clrscr();
       company();
       printf("NAME\t\t\t    EMP.NO.     DEPARTMENT\t\t SALARY\n................................................................................\r");
       }
       printf("%c",STR);
       i++;
       if(i%72==0)
       j++;
     }
 printf("\n                      TOTAL STAFFS :%d",j);
 }
fcloseall();
getch();
screendesign();
menudesign();
menupaint();
gotoxy(2,2);
cprintf("*");
}
int editsub(void)
{
 gotoxy(25,5);
 textbackground(BLACK);
 textcolor(WHITE);
 cprintf("S");
 textbackground(LIGHTGREEN);
 textcolor(BLUE);
 cprintf("TUDENT SEARCH");
 gotoxy(25,7);
  cprintf("S");
 textbackground(BLACK);
  textcolor(WHITE);
   cprintf("T");
 textbackground(LIGHTGREEN);
 textcolor(BLUE);
 cprintf("AFF SEARCH  ");
gotoxy(25,9);
 textbackground(LIGHTGREEN);
 textcolor(BLUE);
 cprintf("ST");
 textbackground(BLACK);
  textcolor(WHITE);
   cprintf("U");
 textbackground(LIGHTGREEN);
 textcolor(BLUE);
 cprintf("DENT DELETE");
 gotoxy(25,11);
  cprintf("ST");
 textbackground(BLACK);
  textcolor(WHITE);
   cprintf("A");
 textbackground(LIGHTGREEN);
 textcolor(BLUE);
 cprintf("FF DELETE  ");
return 0;
}
void edit(int x)
{
   int rol,flag=0;
    int i=0;
   FILE *S,*E,*a;
char*name,*course;
int roll,fees;
clrscr();
if(x==1)
{
 S=fopen("STUDENT.DAT","r");
 printf("Enter the roll no.:");
 scanf("%d",&rol);
 while(!feof(S))
 {
  fgets(name,25,S);
  fscanf(S,"%8d     %s%10d",&roll,course,&fees);
  if(roll==rol)
  {
  flag=1;
  break;
  }
}
if(flag)
{
printf("PRESENT IN THE LIST\n\n");
printf("%s%8d     %s%10d",name,roll,course,fees);
}
else
printf("NOT PRESENT IN THE LIST");
}
else
if(x==2)                                             //for employee
{
 E=fopen("STAFF.DAT","r");
 printf("Enter the emp no.:");
 scanf("%d",&rol);
 while(!feof(E))
 {
  fgets(name,25,E);
  fscanf(E,"%10d      %s%17d\n",&roll,course,&fees);
  if(roll==rol)
   {
   flag=1;
   break;
  }
 }
if(flag)
{
printf("PRESENT IN THE LIST\n\n");
printf("%s%10d      %s%17d\n",name,roll,course,fees);
}
else
printf("NOT PRESENT IN THE LIST");
}
else
if(x==3)
{
 a=fopen("TEMP.DAT","w");
 S=fopen("STUDENT.DAT","r");
 printf("Enter the roll no.:");
 scanf("%d",&rol);
 while(!feof(S))
 {
  fgets(name,25,S);
  fscanf(S,"%8d     %s%10d",&roll,course,&fees);
  if(roll!=rol)
  {
  fprintf(a,"%s%8d     %s%10d",name,roll,course,fees);
  flag=0;
  }
  else
  flag=1;
 }
fcloseall();
rename("TEMP.DAT","STUDENT.DAT");
//remove("TEMP.DAT");
if(flag)
{
printf("PRESENT IN THE LIST\n\n");
printf("%s%8d     %s%10d",name,roll,course,fees);
}
}

_setcursortype(_NORMALCURSOR);
fcloseall();
getch();
clrscr();
_setcursortype(_NOCURSOR);
textcolor(BLACK);
textbackground(BLACK);
clrscr();
screendesign();
menudesign();
menupaint();
gotoxy(2,2);
cprintf("*");
}





































































































































































































































































































































































































































































































































































































































































































































































































































































































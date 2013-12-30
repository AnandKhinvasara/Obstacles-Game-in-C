#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <math.h>
#include <stdarg.h>




union REGS mou;



void scanline(int poly[10][2],int col,int n)
{

	       int i,k,xi[50],temp,y,j;
	       float slope[50],dx,dy,c;



	      for(i=0;i<n;i++)
		{
			dy=poly[i+1][1]-poly[i][1];
			dx=poly[i+1][0]-poly[i][0];

			if(dy==0) slope[i]=1.0;
			if(dx==0) slope[i]=0.0;

			if((dy!=0)&&(dx!=0))
			{
				slope[i]=(float) dx/dy;
			}
		}

	      for(y=0;y< 480;y++)
		{
			k=0;
			for(i=0;i<n;i++)
			{

				if( ((poly[i][1]<=y)&&(poly[i+1][1]>y))||
				((poly[i][1]>y)&&(poly[i+1][1]<=y)))
				{
					xi[k]=(int)(poly[i][0]+slope[i]*(y-poly[i][1]));
					k++;
				}
			}

	      for(j=0;j<k-1;j++)

	  for(i=0;i<k-1;i++)
	      {
			if(xi[i]>xi[i+1])
		{
			temp=xi[i];
			xi[i]=xi[i+1];
			xi[i+1]=temp;
		}
	      }

	setcolor(col);

	for(i=0;i<k;i+=2)
	{
		line(xi[i],y,xi[i+1]+1,y);
	      //	delay(10);
	}

	}

}

int sign(float dx)
    {
	if(dx>0)
	{
		return(1);
	}
	else if(dx<0)
		return(-1);
	else

		return 0;
    }



void dda_line(float x1,float y1,float x2,float y2)
{

    float dx,dy,x,y,length;
    int i;

    setlinestyle(0,2,3);
    dx=x2-x1;
    dy=y2-y1;

    if(dx>=dy)
    {
	length=dx;
    }

    else
	length=dy;

	dx=(x2-x1)/length;    ///dx,dy to find pixelate distance
	dy=(y2-y1)/length;

	x=(x1+(0.5*sign(dx)));    //0.5 to avoid truncated
	y=(y1+(0.5*sign(dy)));

	i=1;

	while(i<=length)
	{
	      //	delay(10);
		putpixel(x,y,12);
		putpixel(x+1,y+1,12);
		putpixel(x-1,y-1,12);

		x=x+dx;   //put pixel at a distance dx,dy
		y=y+dy;
		i++;
	}
}

//sign function//
void bresenham(int x1,int y1,int x2,int y2)
{
  int x,y,e,i=1;
  int s1,s2,count,dx,dy,len;
  dx=abs(x2-x1);
  dy=abs(y2-y1);
  x=x1;
  y=y1;
  s1=sign(x2-x1);
  s2=sign(y2-y1);
  e=2*dy-dx;
  if(dx>dy)
  {
    count=0;
  }
  else
  {
    len=dy;
    dy=dx;
    dx=len;
    count=1;
  }
  while(i<=dx)
  {
    delay(10);
    putpixel(x,y,WHITE);
    while(e>=0)
    {
      if(count==1)
	 x=x+s1;
      else
	y=y+s2;
      e=e-2*dx;
    }
    if(count==1)
      y=y+s2;
    else
      x=x+s1;
    e=e+2*dy;
    i++;
  }
}

void init_mou()
{
	mou.x.ax=0;
	int86(0x33,&mou,&mou);
}

void set_mou(int x1,int y1)
{
	mou.x.ax=4;
	mou.x.cx=x1;
	mou.x.dx=y1;
	int86(0x33,&mou,&mou);

}
void show_mou()
{
	mou.x.ax=1;
	int86(0x33,&mou,&mou);
}

void get_mou(int *x1,int*y1)
{
	mou.x.ax=3;

	    int86(0x33,&mou,&mou);

	    *x1=mou.x.cx;
	    *y1=mou.x.dx;
	  //  *click=mou.x.bx;


}

void restrict_mou(int x1, int y1, int x2, int y2)
{
	mou.x.ax = 7;
	mou.x.cx = x1;
	mou.x.dx = x2;
	int86(0x33, &mou, &mou);

	mou.x.ax = 8;
	mou.x.cx = y1;
	mou.x.dx = y2;
	int86(0x33, &mou, &mou);
}

void wait_mou()
{
	while(mou.x.bx!=0)
		int86(0x33,&mou,&mou);
}

void hide_mou()
{
	mou.x.ax=2;
	int86(0x33,&mou,&mou);
}




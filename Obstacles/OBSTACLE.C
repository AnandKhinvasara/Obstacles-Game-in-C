/*  				Obstacles
	Anand Khinvasara(2357)
	Sumit Kaulkar(2355)
*/


#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <math.h>
#include <stdarg.h>
#define SOUND 3500
#include"header.h"
#include<string.h>
#include<time.h>
int next;
void closewindow();
void mainpage();
void openwindow();
void menu();
void dda_line(float ,float ,float ,float );
int detect(int ,int ,int ,int ,int ,int );
int detect1(int ,int ,int );
void runner();

void scanline(int poly[10][2],int col,int n);
void rect(int ,int );
void brick(int,int,int,int);
////////////////////////////////////////////////////////////////////////////////////////////////
void bricks(int,int,int,int);
int level2();
//void brick();
//int sign(float);
int about();
void display();
int help();


int stage1();





























/////////////////////////////////////////////////////////////////////////////////////////////////
void main()
{


    int mode,driver=DETECT,i,j,choice;
    initgraph(&driver,&mode,"C:\\TC\\bgi");
    do
    {
	  cleardevice();
	  openwindow();

	// setbkcolor(BLACK);
	 choice=getche();
	switch(choice)
	{
		case '1':
			setfillstyle(1,GREEN);
			bar(210,130,330,170);
			delay(10);
			cleardevice();
			runner();
		    //	cleardevice();
			stage1();
			break;
		case '2':
			next:
			cleardevice();
		  //	runner();
		    //	cleardevice();
			level2();
			break;
		case '3':
			cleardevice();
			help();
			getch();
			break;
		case '4':
		       //	setfillstyle(1,YELLOW);
		   //	bar(210,130,330,170);
		     //	delay(10);
		  //	cleardevice();
		       //	runner();
			cleardevice();
			about();
			getch();
			break;
		 case 5:break;



	}
      //	cleardevice();
    flushall();
    }while(choice!='5');
//    getch();
    closegraph();
   // return 0;
}





int help()
{             int j,i,x1,x22,x2,x11,y1,y11,y2,y22,a,y,k,speed;


	 setcolor(RED);
	 settextstyle(1,HORIZ_DIR,7);
	outtextxy(200,50,"HELP");

	  setcolor(YELLOW);
	  settextstyle(1,HORIZ_DIR,2);
	outtextxy(100,200,"1. Use mouse for moving through obstacles\n");
	outtextxy(100,240,"2. save the pointer to touch from the walls\n");
	outtextxy(100,280,"3. NEVER go back while moving forword\n");
	outtextxy(100,320,"4. select choice for stage from menu\n");
	outtextxy(100,360,"5. making the use of arrow keys is not allowded");
	return 0;
}


int about()
{             int j,i,x1,x22,x2,x11,y1,y11,y2,y22,a,y,k,speed;


	 setcolor(WHITE);
	 settextstyle(1,HORIZ_DIR,7);
	outtextxy(200,50,"ABOUT");

	  setcolor(YELLOW);
	  settextstyle(1,HORIZ_DIR,2);
	outtextxy(100,200," PROJECT BY\n");
	outtextxy(100,240,"\t * Sumit Kaulkar(2355)\n");
	outtextxy(100,280,"\t * Anand Khinvasara(2357)\n");
	outtextxy(120,320,"Guided by Y.K.Sharma Sir and Meshram Sir");
	//outtextxy(150,350," Y.K.Sharma Sir \n");

	return 0;
}


void runner()
{
int j=100,i=0,x1,x22,x2,x11,y1,y11,y2,y22,a,y,k=2,speed;
float ang1=3.839724354,ang2=5.585053606, c1=0.05,
c2=-0.05,var1=2.967059728,var2=5.410520681,d1=0.072,d2=-0.072,s=2.35619449;

cleardevice();delay(1000);
while(k>=1)
{
 while(i<=700)
 {
	setcolor(RED);
settextstyle(1,HORIZ_DIR,4);
	outtextxy(150,50,"LOADING . . .");
	setlinestyle(2,2,3);
	 setcolor(8);


 circle(i,j,22);line(i,j+22,i-13,j+115);
 x1=i+50*cos(ang1);x2=i+50*cos(ang2);
 y1=j+22-50*sin(ang1);y2=j+22-50*sin(ang2);
 x11=x1+45*cos(ang1+1.54532952); x22=x2+45*cos(ang2+1.54532952);
 y11=y1-45*sin(ang1+1.54532952);
y22=y2-45*sin(ang2+1.54532952);setcolor(RED);

line(i,j+22,x1,y1);line(x1,y1,x11,y11);setcolor(GREEN);line(i,j+22,x2,y2);
line(x2,y2,x22,y22);
 x1=i-15+60*cos(ang1);  x2=i-15+60*cos(ang2);
 y1=j+115-60*sin(ang1); y2=j+115-60*sin(ang2);
 x11=x1+60*cos(var1); x22=x2+60*cos(var2);
 y11=y1-60*sin(var1); y22=y2-60*sin(var2);

line(i-13,j+115,x1,y1);line(x1,y1,x11,y11);setcolor(RED);line(i-13,j+115,x2,y2);line(x2,y2,x22,y22);
 ang1=ang1+c1; ang2=ang2+c2;
 var1=var1+d1; var2=var2+d2;if(i==0) a=x22;
 if(ang1<=3.839724354)
 {c1=0.05;var1=2.967059728;d1=0.072;};

if(ang1>=5.585053606)
{c1=-0.05;var1=5.410520681;d1=-0.072;a=x11+10;s=2.35619449;};
 if(ang2<=3.839724354)
 {c2=0.05;var2=2.967059728;d2=0.072;};
 if(ang2>=5.585053606)
 {c2=-0.05;var2=5.410520681;d2=-0.072;a=x22+10;s=2.35619449;};
 i=a+150*cos(s)+50;j=320-150*sin(s)-20;s=s-0.045;
 delay(30);if(k!=1);cleardevice();
 }
 i=0;k--;
 }

 }



void openwindow()
{

int aa,bb,cc,dd,maxx,maxy,i=10,k=0,x,y,choice;
int poly[8][8];


aa=250;

bb=400;

cc=260;

for(dd=250;dd<350;dd+=20)

{

setfillstyle(1,GREEN);

bar(dd,bb,cc,bb+10);

cc+=20;   //space between rectangles

}

aa=250;

bb=400;

cc=260;


dda_line(530,400,570,400);
dda_line(530,400,570,360);
dda_line(570,360,570,400);

poly[0][0]=530;
poly[0][1]=400;
poly[1][0]=570;
poly[1][1]=400;
poly[2][0]=570;
poly[2][1]=400;
poly[3][0]=570;
poly[3][1]=360;
poly[4][0]=570;
poly[4][1]=360;
poly[5][0]=530;
poly[5][1]=400;
poly[6][0]=530;
poly[6][1]=400;
scanline(poly,BLACK,4);

while(!kbhit())

{

delay(5);
setcolor(k);
settextstyle(1,HORIZ_DIR,4);
outtextxy(210,140,"1.STAGE 1");
outtextxy(210,190,"2.STAGE 2");
outtextxy(210,240,"3.HELP");
outtextxy(205,300,"4.ABOUT");
outtextxy(205,350,"5:Exit");
k++;

//setbkcolor(13);
setcolor(GREEN);
settextstyle(1,HORIZ_DIR,8);
outtextxy(120,15,"OBSTACLES");

//setlinestyle(1,2,3);
line(125,120,470,120);

if((aa==350)&&(cc==360))

{

aa=250;

cc=260;

continue;

}

else

{

setcolor(10);

rectangle(aa,bb,cc,bb+10);

rectangle(aa-1,bb-1,cc+1,bb+11);

}

delay(300);

setcolor(BLACK);

rectangle(aa,bb,cc,bb+10);

rectangle(aa-1,bb-1,cc+1,bb+11);

aa+=20;

cc+=20;

    x=random(640);
    y=random(480);
    setcolor(15);
    for(i=1;i<10;i++)
     {
      circle(x,y,i);
      delay(10);
     }
    setfillstyle(1,15);
    line(x+8,y-2,x+40,y);
    line(x+8,y+2,x+40,y);
    floodfill(x+11,y,15);
    line(x-8,y-2,x-40,y);
    line(x-8,y+2,x-40,y);
    floodfill(x-11,y,15);
    line(x-2,y+8,x,y+40);
    line(x+2,y+8,x,y+40);
    floodfill(x,y+11,15);
    line(x-2,y-8,x,y-40);
    line(x+2,y-8,x,y-40);
    floodfill(x,y-11,15);
    line(x+8,y-2,x+20,y-20);
    line(x+2,y-8,x+20,y-20);
    floodfill(x+15,y-15,15);
    line(x+8,y+2,x+20,y+20);
    line(x+2,y+8,x+20,y+20);
    floodfill(x+15,y+15,15);
    line(x-8,y+2,x-20,y+20);
    line(x-2,y+8,x-20,y+20);
    floodfill(x-15,y+15,15);
    line(x-8,y-2,x-20,y-20);
    line(x-2,y-8,x-20,y-20);
    floodfill(x-15,y-15,15);
    sound(4000);
    setcolor(0);
    for(i=40;i>=10;i--)
     {
      line(x+8,y-2,x+i,y);
      line(x+8,y+2,x+i,y);
     }
    for(i=40;i>=10;i--)
     {
      line(x-8,y-2,x-i,y);
      line(x-8,y+2,x-i,y);
     }
    for(i=40;i>=10;i--)
     {
      line(x-2,y+8,x,y+i);
      line(x+2,y+8,x,y+i);
     }
    for(i=40;i>=10;i--)
     {
      line(x-2,y-8,x,y-i);
      line(x+2,y-8,x,y-i);
     }
    for(i=20;i>=7;i--)
     {
      line(x+8,y-2,x+i,y-i);
      line(x+2,y-8,x+i,y-i);
     }
    for(i=20;i>=7;i--)
     {
      line(x+8,y+2,x+i,y+i);
      line(x+2,y+8,x+i,y+i);
     }
    for(i=20;i>=7;i--)
     {
      line(x-8,y+2,x-i,y+i);
      line(x-2,y+8,x-i,y+i);
     }
    for(i=20;i>=7;i--)
     {
      line(x-8,y-2,x-i,y-i);
      line(x-2,y-8,x-i,y-i);
     }
    for(i=9;i>0;i--)
     {
      circle(x,y,i);
      delay(10);
     }
    nosound();
   }



}








void closewindow()

{

int i,j,k;

cleardevice();

rectangle(0,0,638,478);

k=0;

while(!kbhit())

{

setcolor(k);

settextstyle(5,0,8);

outtextxy(100,200,"THANK YOU");

line(90,300,600,300);

delay(200);

k++;


}
}











































//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int stage1()
{
int i,clk,x1,y1,flag1=0,flag,flag3=0,z,a,b,c,d,click;
	int current_pos,current_pos1;
	char str[]="Game Over!!!";
	char str1[]="OBSTACLES";
	char str2[]="Stage 1";
	char str3[]="YOU WIN";


	long int size;
	void far *buff;


	     init_mou();
	     show_mou();
	     restrict_mou(80,155,560,318);
	     set_mou(82,240);
	     display();

	     bricks(80,90,560,150);
	     bricks(80,330,560,390);

	  //   bar()
	     settextstyle(4,0,5);
	     setcolor(6);
	     outtextxy(190,10,str1);
	     setcolor(WHITE);
	     settextstyle(1,0,1);
	     outtextxy(270,60,str2);

	     setfillstyle(1,BLACK);
	     bar(80,150,560,330);
	     setfillstyle(1,8);
	     bar(70,80,570,90);
	     bar(560,80,570,395);
	     bar(70,380,570,395);
	     bar(70,80,80,390);
       //	     setlinestyle(0,2,3);
	     dda_line(75,85,565,85);
	     dda_line(565,85,565,387);
	     dda_line(565,387,75,385);
	     dda_line(75,85,75,385);

	     i=0,a=1;
	     while(!kbhit()&&!flag1==1)
	     {
  //			z=x1;

			get_mou(&x1,&y1);

	/*	setcolor(WHITE);
		mouse_gui(x1,y1,current_pos,current_pos1);
		delay(50);
		setcolor(BLACK);
		mouse_gui(x1,y1,current_pos,current_pos1);
	 */

		setfillstyle(5,GREEN);
			bar(180,160+i,210,300+i);

			bar(260,160+i,290,300+i);
			bar(340,160+i,370,300+i);
			bar(420,160+i,450,300+i);


			bar(220,180-i,250,320-i);
			bar(300,180-i,330,320-i);
			bar(380,180-i,410,320-i);
			bar(460,180-i,490,320-i);

			if(x1>=180&&x1<=210)
				flag1=detect(x1,y1,160+i,300+i,180,210);
			if(x1>=220&&x1<=250)
				flag1=detect1(y1,180-i,320-i);
			if(x1>=260&&x1<=290)
				flag1=detect1(y1,160+i,300+i);
			if(x1>=300&&x1<=330)
				flag1=detect1(y1,180-i,320-i);
			if(x1>=340&&x1<=370)
				flag1=detect1(y1,160+i,300+i);
			if(x1>=380&&x1<=410)
				flag1=detect1(y1,180-i,320-i);
			if(x1>=420&&x1<=450)
				flag1=detect1(y1,160+i,300+i);
			if(x1>=460&&x1<=490)
				flag1=detect1(y1,180-i,320-i);
			if(x1==560)
			{
				flag3=1;
			       flag1=1;
			}
			///////
			delay(150);
			//////
			setfillstyle(5,BLACK);
			bar(260,160+i,290,300+i);
			bar(180,160+i,210,300+i);
			bar(340,160+i,370,300+i);
			bar(420,160+i,450,300+i);

			bar(220,180-i,280,320-i);
			bar(300,180-i,330,320-i);
			bar(380,180-i,410,320-i);
			bar(460,180-i,490,320-i);


		      /*	setcolor(BLACK);
			rectangle(260,160+i,290,300+i);
			rectangle(180,160+i,210,300+i);
			rectangle(340,160+i,370,300+i);
			rectangle(420,160+i,450,300+i);
			///
		      */


			/////////////////////
			if(flag==0)
			{
				i+=2;
				a++;
				if(a>10)
					flag=1;

			}
			else
			{
				i-=2;
				a--;
				if(a==0)
					flag=0;
			}
	     }
	     ////////////////////////end of while
	     if(flag1==1&&flag3==1)
	     {
		setcolor(WHITE);
		settextstyle(1,0,5);

		outtextxy(180,200,str3);
		getch();
		//goto <next>;
		return 0;
	     }
	     else if(flag1==1)
	     {

		setcolor(WHITE);
		settextstyle(4,0,5);

		outtextxy(200,200,str);
		getch();
		return 0;
	     }


   //getch();
	return 0;


}



void display()
{
		int i;





		setfillstyle(1,3);
	       //	bar(0,0,640,480);

		setcolor(WHITE);
	     rectangle(80,90,560,390);   //outer rectangle
	     setfillstyle(1,BROWN);
	     bar(80,90,560,150)   ;
	     rectangle(80,90,560,150);   //brown blocks
	     rectangle(80,330,560,390);
	     bar(80,330,560,390);

		setfillstyle(5,BLUE);
	     for(i=0;i<280;i+=80)
	     {
			delay(10) ;
			setcolor(WHITE);
			bar(180+i,160,210+i,300);
			rectangle(180+i,160,210+i,300);
	     }
	  //   setfillstyle()
	     for(i=0;i<210;i+=80)
	     {
			delay(10) ;
			setcolor(WHITE);
			bar(220+i,180,250+i,320);
		     //	rectangle(220+i,180,250+i,320);
	     }

}






void bricks(x1,y1,x2,y2)
{
     int i,j;
     setfillstyle(1,7);
     setcolor(BLACK);
     bar3d(x1,y1,x2,y2,0,0);
     setfillstyle(1,RED);
     for(i=x1;i<560;i+=48)
     {//   setcolor(BLUE);
	// line(i+1,y1+4,i+41,y1+4);
	// line(i+41,y1+4,i+41,y1+9);
	 setlinestyle(0,2,3);
	 setcolor(BLACK);
	 bar3d(i+4,y1+3,i+48,y1+10,0,0);
	 setcolor(12);
	 dda_line(i+4,y1+3,i+48,y1+3);
	 dda_line(i+4,y1+3,i+4,y1+10);
     }
     for(j=x1+21;j<=518;j+=48)
     {

	 setcolor(BLACK);
	bar3d(j+4,y1+15,j+48,y1+22,0,0);
	 setcolor(12);
	 dda_line(j+4,y1+15,j+48,y1+15);
	 dda_line(j+4,y1+15,j+4,y1+22);
     }
     for(i=x1;i<560;i+=48)
     {

	 setcolor(BLACK);

	 bar3d(i+4,y1+27,i+48,y1+34,0,0);
	 setcolor(12);
	 dda_line(i+4,y1+27,i+48,y1+27);
	 dda_line(i+4,y1+27,i+4,y1+34);
     }
     for(j=x1+21;j<=518;j+=48)
     {
	setcolor(BLACK);
	bar3d(j+4,y1+39,j+48,y1+46,0,0);
	 setcolor(12);
	 dda_line(j+4,y1+39,j+48,y1+39);
	 dda_line(j+4,y1+39,j+4,y1+46);
     }
     for(i=x1;i<560;i+=48)
     {
	setcolor(BLACK);
	bar3d(i+4,y1+51,i+48,y1+58,0,0);
	setcolor(12);
       dda_line(i+4,y1+51,i+48,y1+51);
       dda_line(i+4,y1+51,i+4,y1+58);
     }
}


int detect(int a,int b,int y1,int y2,int x1,int x2)
{

	 if(y1<=b&&b<=y2)
	{

		if(x1<=a&&a<=x2)
			return 1;
	}

	return 0;
}
int detect1(int b,int y1,int y2)
{

	 if(y1<=b&&b<=y2)
	{

	     //	if(x1<=a&&a<=x2)
			return 1;
	}

	return 0;
}






































































////////////////////////////////////////////////////////////////////////////////////////////////////



int level2()
{
	int i,x,y,k,m,n,flag=0,flag1,flag2=0;
	setbkcolor(15);
	//setfillstyle()
	init_mou();
	set_mou(30,420);
	setcolor(RED);
	settextstyle(  SANS_SERIF_FONT,HORIZ_DIR,3);
	      //	settextstyle(2,0,10);
		outtextxy(240,10,"STAGE 2");
	brick(0,50,20,480);
	brick(620,50,640,480);
	brick(20,50,620,70);
	brick(20,460,620,480);

	brick(40,100,80,460);
	brick(560,100,600,460);
//	brick(560,70,600,430);

	brick(310,70,330,430);

	brick(80,100,280,200);
	brick(330,200,400,430);
	brick(490,200,560,430);

	brick(350,160,540,180);

	brick(330,100,440,120);
	brick(450,100,560,120);

	brick(100,250,310,270);
	brick(80,290,290,310);
	brick(100,330,310,350);
	brick(80,370,290,390);
	brick(100,410,310,430);
       //	set_mou(37,420);
	rect(25,420);
      //	delay(1000);
	do
	{


		setcolor(6);
		for(i=0;i<50;i++)
		{
			get_mou(&x,&y);
			rect(x,y);
			k=getpixel(x+6,y+7);
			m=getpixel(x-6,y-7);
			if(k==RED||k==GREEN||m==RED||m==GREEN)
			{
				flag=1;

				break;
			}
			else
			{
				flag=0;
			       //	break;
			}
			setcolor(GREEN);
			line(100,i+200,260,i+200);
			line(400+i,200,400+i,300);
			line(490-i,200,490-i,300);

			line(400+i,330,400+i,430);
			line(490-i,330,490-i,430);

		    //	line(400+i,200,400+i,430);
		      //	line(490-i,200,490-i,430);
			delay(40);
		}
	       //	setcolor(WHITE);
		setfillstyle(1,15);
		setcolor(WHITE);
		bar3d(95,200,270,249,0,0);
		bar3d(400,200,490,300,0,0);
		bar3d(400,330,490,430,0,0);
	       //	delay(10);
		setcolor(MAGENTA);
		line(600,460,620,460);
		if(y+5==460)
		{
			if(x>600&&x<620)
			{
				flag2=1;
				flag=1;
			}
		}

	}while(!kbhit()&&flag==0);
  //	clrscr();
	cleardevice();
	if(flag==1)
	{


		setcolor(RED);
		settextstyle(  SANS_SERIF_FONT,HORIZ_DIR,3);
	      //	settextstyle(2,0,10);
	       if(flag2==1)
	       {
		outtextxy(240,250,"YOU WIN");
		setbkcolor(BLACK);
		getch();
		return 0;
	       }
	       else
	       {
		outtextxy(240,250,"GAME OVER");
		setbkcolor(BLACK);
		getch();
		return 0;
	       }
	}

	getch();
	setbkcolor(BLACK);
	return 0;

}


void brick(x1,y1,x2,y2)
{
	int y3,i,j;
	setfillstyle(9,RED);
	setcolor(15);
     //	y3=y2-y1;
      //	j=y3/2;
	setcolor(WHITE);
	for(i=y1;i<=y2;i++)
		line(x1,i,x2,i);
	bar3d(x1,y1,x2,y2,0,0);
	setfillstyle(1,RED);
       //	bar3d(x1+3,y1+3,x2-3,y2-3,0,0);
	setcolor(1);
	line(x1+3,y1+3,x1+3,y2-3);
	line(x1+3,y1+3,x2-3,y1+3);
	line(x1+2,y1+2,x1+2,y2-2);
	line(x1+2,y1+2,x2-2,y1+2);
}


void rect(int x,int y)
{
	setfillstyle(1,BLUE);
	bar(x-5,y-5,x+5,y+5);
	//setcolor(BLACK);

	delay(30);
	setfillstyle(1,15);
	bar(x-5,y-5,x+5,y+5);

}

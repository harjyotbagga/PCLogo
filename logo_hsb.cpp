#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<process.h>
#include<alloc.h>
#include<dos.h>

 char tot[7];
 char com[4];
 char alphadig[3];
 int val, ang;
 int x,y,x1,y1;
 int maxx, maxy;
 int pen, setcol, st;
 int oldcol, erase;
 int homex, homey, oldx, oldy;
 int pic;
 int lstyle, lwidth;
 unsigned int size;
 void far *bmp1;
 double rad=0.017453292519943;
 void PROLOAD();
 void PU();
 void PD();
 void PE();
 void PEN();
 void HT();
 void ST();
 void COL();
 void FD();
 void BK();
 void RT();
 void LT();
 void LS();
 void LWID();
 void MARK();
 void POINT();
 void STAR();
 void SQ();
 void CIR();
 void TRI();
 void SEMI();
 void LS();
 void HOME();
 void SETH();
 void CLS();
 void CAPTURE();
 void TURTLE();
 void BYE();
 void OUT_SCOPE();
 void INVALID();
 void HELP();
void main()
{
 int gd,gm;
 gd=DETECT;
 initgraph(&gd,&gm,"..//bgi");
 PROLOAD();
 settextstyle(0,0,0);
 BASIC:
 CLS();
 x=getmaxx()/2;
 y=getmaxy()/2;
 size= imagesize(x-10,y-10,x+10,y+10);
 bmp1 = malloc(size);
 maxx=getmaxx();
 maxy=getmaxy();
 homex=x;
 homey=y;
 pen=1;
 erase=0;
 setcol=15;
 st=1;
 pic=0;
 lstyle=0;
 lwidth=1;
 ang=90;
 START:
 CAPTURE();
 tot[1];
 com[1];
 alphadig[0];
 char pcol[10];
 setcolor(15);
 gotoxy(1,25);

 cout<<"L.STYLE: "<<lstyle;
 cout<<endl;
 if (pen==1)
	cout<<"PEN: DOWN";
 else if (pen==0)
	cout<<"PEN: UP  ";
 cout<<endl;
 if (erase==1)
	cout<<"ERASER: TRUE ";
 else if (erase==0)
	cout<<"ERASER: FALSE";
 cout<<endl;
 if (st==1)
	cout<<"TURTLE: SHOW";
 else if (st==0)
	cout<<"TURTLE: HIDE";
 cout<<endl;
 if (setcol<10)
	cout<<"PEN COLOR: "<<setcol<<" ";
 else
	cout<<"PEN COLOR: "<<setcol-55;
 cout<<endl;
 if (ang<10)
	cout<<"ANGLE: "<<ang<<"  ";
 else if (ang<100)
	cout<<"ANGLE: "<<ang<<" ";
 else
	cout<<"ANGLE: "<<ang;

 outtextxy(1,1,"               ");
 outtextxy(1,1,"Enter COMMAND- ");
 gotoxy(1,2);
 cout<<"                  ";
 gotoxy(1,2);
 gets (tot);


 if (pen==1)
	setcolor(setcol);
 else if (pen==0)
	setcolor(0);
 int al = strlen(tot);
 int count=0;
 for (int i=0; i<=(al-1); i++)
 {
  if (tot[i]!=' ')
	count++;
  if (tot[i]==' ')
	break;
 }
 for (int j=0; j<=(count-1); j++)
 {
  com[j]=tot[j];
 }
 com[j]='\0';
 i=count+1;
 int c=0;
 alphadig[0];
 for (j=i; j<=(al-1); j++)
 {
  alphadig[c]=tot[j];
  c++;
 }
 alphadig[c]='\0';
 al=strlen(alphadig);
 char d;
 int dig=0;
 val=0;
 for (i=0; i<al; i++)
 {
  d = alphadig[i];
  if (d=='0')
	dig=0;
  else if (d=='1')
	dig=1;
  else if (d=='2')
	dig=2;
  else if (d=='3')
	dig=3;
  else if (d=='4')
	dig=4;
  else if (d=='5')
	dig=5;
  else if (d=='6')
	dig=6;
  else if (d=='7')
	dig=7;
  else if (d=='8')
	dig=8;
  else if (d=='9')
	dig=9;
     val=(val*10)+dig;
 }

 al=strlen(com);
 char ch;
 for (int uc=0; uc<al; uc++)
 {
  ch=com[uc];
  com[uc]=char(toupper(ch));
 }
 if (strcmp(com,"FD")==0)
	{
	 FD();
	 goto START;
	}
 else if (strcmp(com,"BK")==0)
	{
	 BK();
	 goto START;
	}
 else if (strcmp(com,"RT")==0)
	{
	 RT();
	 goto START;
	}
 else if (strcmp(com,"LT")==0)
	{
	 LT();
	 goto START;
	}
 else if (strcmp(com,"PT")==0)
	{
	 POINT();
	 goto START;
	}
 else if (strcmp(com,"MARK")==0)
	{
	 MARK();
	 goto START;
	}
 else if (strcmp(com,"STAR")==0)
	{
	 STAR();
	 goto START;
	}
 else if (strcmp(com,"SQ")==0)
	{
	 SQ();
	 goto START;
	}
 else if (strcmp(com,"CIR")==0)
	{
	 CIR();
	 goto START;
	}
 else if (strcmp(com,"TRI")==0)
	{
	 TRI();
	 goto START;
	}
 else if (strcmp(com,"SEM")==0)
	{
	 SEMI();
	 goto START;
	}
 else if (strcmp(com,"PU")==0)
	{
	 PU();
	 goto START;
	}
 else if (strcmp(com,"PD")==0)
	{
	 PD();
	 goto START;
	}
 else if (strcmp(com,"PE")==0)
	{
	 PE();
	 goto START;
	}
 else if (strcmp(com,"PEN")==0)
	{
	 PEN();
	 goto START;
	}
 else if (strcmp(com,"LS")==0)
	{
	 LS();
	 goto START;
	}
 else if (strcmp(com,"LWID")==0)
	{
	 LWID();
	 goto START;
	}
 else if (strcmp(com,"HT")==0)
	{
	 HT();
	 goto START;
	}
 else if (strcmp(com,"ST")==0)
	{
	 ST();
	 goto START;
	}
 else if (strcmp(com,"COL")==0)
	{
	 COL();
	 goto START;
	}
 else if (strcmp(com,"HOME")==0)
	{
	 HOME();
	 goto START;
	}
 else if (strcmp(com,"SETH")==0)
	{
	 SETH();
	 goto START;
	}
 else if (strcmp(com,"CLS")==0)
	{
	 CLS();
	 goto BASIC;
	}
else if (strcmp(com,"HELP")==0)
	{
	 HELP();
	 goto BASIC;
	}
 else if ((strcmp(com,"BYE")==0)||(strcmp(com,"EXIT")==0)||(strcmp(com,"END")==0))
	BYE();
 else
	{
	 INVALID();
	 goto START;
	}

 getch();


}

void PROLOAD()
{
rectangle(10,10,getmaxx()-10,getmaxy()-10);
settextstyle(1,0,4);
outtextxy(100,200,"LOADING...");
rectangle(90,240,510,310);
settextstyle(1,1,4);
outtextxy(15,22,"AN H.S.BAGGA PRODUCTION");
settextstyle(0,1,0);
outtextxy(23,12,"C");
circle(18,16,5);
settextstyle(1,0,4);
for(int x=100;x<=500;x++)
{
setlinestyle(4,0,15);
line(x,250,x,300);
setcolor(0);
outtextxy(getmaxx()/2-15,250,"P.C.LOGO");
setcolor(15);
delay(10);
}
delay(20);
outtextxy(170,350,"MADE BY- ");
outtextxy(180, 380,"HARJYOT .S. BAGGA");
getch();
cleardevice();
}


void FD()
{
	CAPTURE();

 if (pen==1)
	setcolor(setcol);

 setlinestyle(lstyle,0,lwidth);
 float a2=ang;
 float opp, adj, hypt;
 int sub;
 if (ang==90)
 {
   x1=x;
   y1=y-val;
   if (y1>=0)
	{
	if (pen==1)
	line(x,y,x1,y1);
	x=x1;
	y=y1;
	}
   else
	OUT_SCOPE();
 }
 else if (ang==270)
 {
	x1=x;
	y1=y+val;
	if (y1<=maxy)
	{
	if (pen==1)
	line(x,y,x1,y1);
	x=x1;
	y=y1;
       }
       else
       OUT_SCOPE();
 }
 if (ang==0)
 {
	x1=x+val;
	y1=y;
	if (x1<=maxx)
	{
	if (pen==1)
	line(x,y,x1,y1);
	x=x1;
	y=y1;
	}
	else
	 OUT_SCOPE();
 }
 else if (ang==180)
 {
  x1=x-val;
  y1=y;
  if (x1>=0)
	{
	if (pen==1)
	line(x,y,x1,y1);
	x=x1;
	y=y1;
       }
       else
       OUT_SCOPE();

 }
 else if ((ang<90)&&(ang>0))
 {
  hypt=val;
  a2=a2*0.017453292519943;
  adj=cos(a2)*hypt;
  opp=sin(a2)*hypt;
  x1=x+adj;
  y1=y-opp;
  if ((x1>maxx)||(y1<0))
	OUT_SCOPE();
  else
	{
	 if (pen==1)
	 line(x,y,x1,y1);
	 x=x1;
	 y=y1;
	}
 }
 else if ((ang>90)&&(ang<180))
 {
  hypt=val;
  a2=(a2-90)*0.017453292519943;
  adj=cos(a2)*hypt;
  opp=sin(a2)*hypt;
  x1=x-opp;
  y1=y-adj;
  if ((x1<0)||(y1<0))
  {
    OUT_SCOPE();
  }
  else
  {
  if (pen==1)
  line(x,y,x1,y1);
  x=x1;
  y=y1;
  }

 }
 else if ((ang>180)&&(ang<270))
 {
  hypt=val;
  a2=(a2-180)*0.017453292519943;
  adj=cos(a2)*hypt;
  opp=sin(a2)*hypt;

  x1=x-adj;
  y1=y+opp;
  if ((x1<0)||(y1>maxy))
  OUT_SCOPE();
  else
  {
  if (pen==1)
  line(x,y,x1,y1);
  x=x1;
  y=y1;
  }
 }
 else if ((ang>270)&&(ang<360))
 {
  hypt=val;
  a2=(a2-270)*0.017453292519943;
  adj=cos(a2)*hypt;
  opp=sin(a2)*hypt;
  x1=x+opp;
  y1=y+adj;
  if ((x1>maxx)||(y1>maxy))
  OUT_SCOPE();
  else
  {
  if (pen==1)
  line(x,y,x1,y1);
  x=x1;
  y=y1;
  }
 }

 if (pen==1)
	setcolor(setcol);
 else if (pen==0)
	setcolor(0);

}

void BK()
{
 CAPTURE();
 setlinestyle(lstyle,0,lwidth);
 float a2=ang;
 int hypt=val;
 int adj, opp;
 if (pen==1)
	setcolor(setcol);
 else if (pen==0)
	setcolor(0);

 if (ang==90)
 {
  int sub;
  x1=x;
  y1=y+val;
  if (y1>maxy)
	{
	OUT_SCOPE();
	}
 else
	{
	line(x,y,x1,y1);
	x=x1;
	y=y1;
       }
 }
 else if (ang==270)
 {
  int sub;
  x1=x;
  y1=y-val;
  if (y1<0)
	{
	OUT_SCOPE();
	}
  else
	{
	line(x,y,x1,y1);
	x=x1;
	y=y1;
	}
 }
 else if (ang==0)
 {
  int sub;
  x1=x-val;
  y1=y;
  if (x1<0)
	{
	OUT_SCOPE();
	}
  else
	{
	line(x,y,x1,y1);
	x=x1;
	y=y1;
       }
 }
 else if (ang==180)
 {
 x1=x+val;
 y1=y;
 int sub;
 if (x1>maxx)
	{
	OUT_SCOPE();
	}
 else
	{
	line(x,y,x1,y1);
	x=x1;
	y=y1;
	}
 }
 else if ((ang<270)&&(ang>180))
 {
  hypt=val;
  a2=(a2-180)*0.017453292519943;
  adj=cos(a2)*hypt;
  opp=sin(a2)*hypt;
  x1=x+adj;
  y1=y-opp;
  if ((x1>maxx)||(y1<0))
	OUT_SCOPE();
  else
	{
	if (pen==1)
	line(x,y,x1,y1);
	x=x1;
	y=y1;
	}
 }
 else if ((ang>270)&&(ang<360))
 {
  hypt=val;
  a2=(a2-270)*0.017453292519943;
  adj=cos(a2)*hypt;
  opp=sin(a2)*hypt;

  x1=x-opp;
  y1=y-adj;
  if ((x1<0)||(y1<0))
  OUT_SCOPE();
  else
  {
  if (pen==1)
  line(x,y,x1,y1);
  x=x1;
  y=y1;
  }
 }
 else if ((ang>0)&&(ang<90))
 {
  hypt=val;
  a2=(a2)*0.017453292519943;
  adj=cos(a2)*hypt;
  opp=sin(a2)*hypt;

  x1=x-adj;
  y1=y+opp;
  if ((x1<0)||(y1>maxy))
  OUT_SCOPE();
  else
  {
  if (pen==1)
  line(x,y,x1,y1);
  x=x1;
  y=y1;
  }
 }
 else if ((ang>90)&&(ang<180))
 {
  hypt=val;
  a2=(a2-90)*0.017453292519943;
  adj=cos(a2)*hypt;
  opp=sin(a2)*hypt;

  x1=x+opp;
  y1=y+adj;
  if ((x1>maxx)||(y1>maxy))
  OUT_SCOPE();
  else
  {
  if (pen==1)
  line(x,y,x1,y1);
  x=x1;
  y=y1;
  }
 }


 if (pen==1)
 setcolor(setcol);
 else if (pen==0)
 setcolor(0);

}

void RT()
{
 CAPTURE();
 if (ang==val)
	ang=0;
 else if (ang>val)
	ang=ang-val;
 else
	{
	 do
	 {
	 ang+=360;
	 ang-=val;
	 if (ang<0)
		ang=360+ang;
	 ang=(ang%360);
	 ang=abs(ang);
	 }while((ang<0)&&(ang>=360));
	}
}

void LT()
{
 CAPTURE();
 int chk;
 chk=ang+val;
 if (val==360)
	ang=ang;
 else if (chk<360)
	ang=chk;
 else if (chk>359)
	{
	 do
	 {
	  chk=360;
	  chk=ang+chk;
	  chk=chk+val;
	  chk=chk%360;
	  ang=abs(chk);
	 }while((ang<0)&&(ang>=360));
	}
}

void PU()
{
 CAPTURE();
 pen=0;
}

void PD()
{
 CAPTURE();
 pen=1;
}

void PE()
{
 CAPTURE();
 if (erase==1)
	{
	 setcolor(oldcol);
	 setcol=oldcol;
	 erase=0;
	}
 else if (erase==0)
	{
	 oldcol=setcol;
	 setcolor(0);
	 setcol=0;
	 erase=1;
	}
}

void PEN()
{
 CAPTURE();
 if (pen==1)
	pen=0;
 else if (pen==0)
	pen=1;
}

void HT()
{
 CAPTURE();
 st=0;
}

void ST()
{
 CAPTURE();
 st=1;
}

void COL()
{
  CAPTURE();
  val=val%16;
  if (val<=15)
  {
  if (val<=9)
	setcol=val;
  else if (val==10)
	setcol='A';
  else if (val==11)
	setcol='B';
  else if (val==12)
	setcol='C';
  else if (val==13)
	setcol='D';
  else if (val==14)
	setcol='E';
  else if (val==15)
	setcol='F';
  }
  else
	setcol=15;
 /*
Color Codes:
0 = Black
1 = Blue
2 = Green
3 = Aqua
4 = Red
5 = Purple
6 = Yellow
7 = White
8 = Gray
9 = Light Blue
A = Light Green
B = Light Aqua
C = Light Red
D = Light Purple
E = Light Yellow
F = Bright White
*/
}

void LS()
{
 CAPTURE();
 if ((val>=0)&&(val<=3))
	lstyle=val;
 else
	lstyle=0;
 setlinestyle(lstyle,0,lwidth);
}

void LWID()
{
 CAPTURE();
 if (lwidth==1)
	lwidth=3;
 else if (lwidth==3)
	lwidth=1;
 else
	lwidth=1;
}

void HOME()
{
 CAPTURE();
 x1=homex;
 y1=homey;
 setlinestyle(lstyle,0,lwidth);
 if (pen==1)
	line(x,y,x1,y1);
 x=x1;
 y=y1;
 ang=90;
}

void SETH()
{
 CAPTURE();
 homex=x;
 homey=y;
}

void MARK()
{
 CAPTURE();
 if (pen==1)
	{
	 setcolor(setcol);
	 line(x,y,x-3,y-3);
	 line(x,y,x+3,y+3);
	 line(x,y,x-3,y+3);
	 line(x,y,x+3,y-3);
	 line(x,y,x-3,y);
	 line(x,y,x+3,y);
	 line(x,y,x,y-3);
	 line(x,y,x,y+3);

	}
}

void POINT()
{
 CAPTURE();
 if (pen==1)
	putpixel(x,y,setcol);
}

void STAR()
{
 CAPTURE();
 if(pen==1)
 {
 setcolor(setcol);
 line(x,y-5,x-3,y+4);
 line(x,y-5,x+3,y+4);
 line(x-3,y+4,x+4,y-2);
 line(x+3,y+4,x-4,y-2);
 line(x+4,y-2,x-4,y-2);
 }
}

void SQ()
{
 CAPTURE();
 setcolor(setcol);
 setlinestyle(lstyle,0,lwidth);
 if (pen==1)
 rectangle(x-val,y-val,x+val,y+val);
}

void CIR()
{
 CAPTURE();
 setlinestyle(lstyle,0,lwidth);
 setcolor(setcol);
 if (pen==1)
 circle(x,y,val);
}

void TRI()
{
 CAPTURE();
 setlinestyle(lstyle,0,lwidth);
 if (pen==1)
 {
 setcolor(setcol);
 line(x,y-val,x+val,y+val);
 line(x,y-val,x-val,y+val);
 line(x+val,y+val,x-val,y+val);
 }
}

void SEMI()
{
 CAPTURE();
 setcolor(setcol);
 int a1, a2;
 a1=ang-90;
 if (a1<0)
	a1=360+a1;
 a2=ang+90;
 if (a2>359)
	a2=a2%360;
 arc(x,y,a1,a2,val);
}

void CLS()
{
 cleardevice();
}

void CAPTURE()
{
 if (pic==0)
	{
	 getimage(x-10,y-10,x+10,y+10,bmp1);
	 if (st==1)
		TURTLE();
	 oldx=x;
	 oldy=y;
	 pic=1;
	}
 else if (pic==1)
	{
	 putimage(oldx-10,oldy-10,bmp1,0);
	 if ((oldx!=x)&&(oldy!=y))
	 getimage(x-10,y-10,x+10,y+10,bmp1);
	 pic=0;
	}
}

void TURTLE()
{
 setcolor(15);
 setlinestyle(0,0,1);
 double ang1, ang2;
 ang1= (ang-45)*rad;
 ang2=(135-ang)*rad;
 line(x,y,x+9*sin(ang1),y+9*cos(ang1));
 line(x,y,x-9*sin(ang2),y+9*cos(ang2));
 line(x+9*sin(ang1),y+9*cos(ang1),x-9*sin(ang2),y+9*cos(ang2));
 setlinestyle(lstyle,0,lwidth);
 setcolor(setcol);
}


void BYE()
{
 exit(0);
}

void OUT_SCOPE()
{
 CAPTURE();
 gotoxy(1,2);
 cout<<"                  ";
 gotoxy(1,2);
 cout<<"OUTSIDE SCOPE !!!";
 delay(1000);
}

void INVALID()
{
  CAPTURE();
  gotoxy(1,2);
  cout<<"                  ";
  gotoxy(1,2);
  cout<<"INVALID COMMAND...";
  delay(1000);
}

void HELP()
{
cleardevice();
cout<<"FD: (FORWARD) Draws a line in the forward direction from the current position to 'x' no. of steps."<<endl;
cout<<"BK: (BACKWARD) Draws a line in the backward direction from the current position to 'x' no. of steps."<<endl;
cout<<"RT: (RIGHT) Turns the turtle by 'x' degrees towards the right side."<<endl;
cout<<"LT: (LEFT) Turns the turtle by 'x' degrees towards the left side."<<endl;
cout<<"HT: (HIDE TURTLE) Hides the turtle, present on the screen."<<endl;
cout<<"ST: (SHOW TURTLE) Shows the turtle which has been hidden."<<endl;
cout<<"PU: (PEN UP) Moves the turtle on the screen without drawing a line."<<endl;
cout<<"PD: (PEN DOWN) Moves the turtle on the screen drawing a line."<<endl;
cout<<"PE: (PEN ERASE) Converts the turtle into an eraser and erases the lines wherever it draws them."<<endl;
cout<<"CLS: (CLEAR SCREEN) Clears the screen."<<endl;
cout<<"HOME: (HOME) Goes to the Home position. "<<endl;
cout<<"*SETH: (SET HOME) Sets the current position as the Home position. By default the Home position lies in the centre of the screen."<<endl;
cout<<"*PEN: (PEN) It acts as a switcher from 'Pen Up' to 'Pen Down' and vice-versa."<<endl;
cout<<"*COL: (COLOR) It changes the pen colour."<<endl;
cout<<"*LS: (LINE STYLE) Changes the line style."<<endl;
cout<<"*LWID: (LINE WIDTH) Acts as a switcher between a thick and a normal line."<<endl;
cout<<"*MARK: (MARK) Marks the current position."<<endl;
cout<<"*PT: (POINT) Puts a point on the current position."<<endl;
cout<<"*STAR: (STAR) Draws a star on the current position."<<endl;
cout<<"*CIR: (CIRCLE) Draws a circle with radius 'x'. "<<endl;
cout<<"*SQ: (SQUARE) Draws a square with side 'x'."<<endl;
cout<<"*TRI: (TRIANGLE) Draws an equilateral triangle with centroid on the current position."<<endl;
cout<<"*SEMI: (SEMI-CIRCLE) Draws a semicircle upwards."<<endl;
cout<<""<<endl;
cout<<"NOTE: Functions- FD, BK, RT, LT, COL, LS, CIR, SQ, TRI and SEMI should have a numerical parameter. In these functions the command and the parameter should have a space between it."<<endl;
getch();
}
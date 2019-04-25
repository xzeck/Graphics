#include<stdio.h>
#include<graphics.h>
#include<math.h>
int graDriver=DETECT,graMode;
int n,xs[100],ys[100],i,xshift,yshift,xp,yp,degree;
int tempYaxis,tempXaxis;
float sfx,sfy;
float shearXfactor,shearYfactor;
float radian;
int choice;
void DrawFn();
void translate();
void scale();
void rotation();
void degToRad();
void FlipH();
void FlipV();
void shearAlongX();
void shearAlongY();
int main()
{
printf("enter the choce 1 for trnas 2nd for scailing 3rd for rotation 4th for reflection 5th for sheraing");
scanf("%d",&choice);
switch(choice)
{

case 1:
printf("Enter number of sides of polygon: ");
scanf("%d",&n);
printf("Enter co-rdinates: x,y for each vertex ");
for(i=0;i<n;i++)
 scanf("%d%d",&xs[i],&ys[i]);
printf("Enter distances for translation (in x and y directions): ");
scanf("%d%d",&xshift,&yshift);
initgraph(&graDriver,&graMode,"C:\\TURBOC3\\BGI\\");
cleardevice();
//drawing original polygon in RED color
setcolor(RED);
DrawFn();
//Doing translation
translate();
//drawing translated polygon in BLUE color
setcolor(BLUE);
DrawFn();

case 2:
    printf("Enter number of sides: ");
scanf("%d",&n);
printf("Enter co-rdinates: x,y for each point ");
for(i=0;i<n;i++)
 scanf("%d%d",&xs[i],&ys[i]);
printf("Enter scale factors: (xs,ys) ");
scanf("%f%f",&sfx,&sfy);
initgraph(&graDriver,&graMode,"C:\\TURBOC3\\BGI\\");
setcolor(RED);
DrawFn();//original
scale();//scaling
setcolor(BLUE);
DrawFn();

case 3:

printf("Enter number of sides: ");
scanf("%d",&n);
printf("Enter co-rdinates: x,y for each point ");
for(i=0;i<n;i++)
 scanf("%d%d",&xs[i],&ys[i]);
printf("\nenter pivot point co-ordinate");
scanf("%d%d",&xp,&yp);
printf("\nenter rotation angle");
scanf("%d",&degree);
degToRad();
initgraph(&graDriver,&graMode,"C:\\TURBOC3\\BGI\\");
cleardevice();
//Drawing original in RED color
setcolor(RED);
DrawFn();
//Doing rotation
rotation();
//Drawing rotated polygon in BLUE color
setcolor(BLUE);
DrawFn();

case 4:
printf("Enter number of sides: ");
scanf("%d",&n);
printf("Enter co-rdinates: x,y for each point ");
for(i=0;i<n;i++)
 scanf("%d%d",&xs[i],&ys[i]);

initgraph(&graDriver,&graMode,"C:\\TURBOC3\\BGI\\");
setcolor(RED);
DrawFn();//original
FlipV();
setcolor(BLUE);
DrawFn();//vertical flip
FlipH();
setcolor(GREEN);
DrawFn();

case 5:
    printf("Enter number of sides: ");
scanf("%d",&n);
printf("Enter co-rdinates: x,y for each point ");
for(i=0;i<n;i++)
 scanf("%d%d",&xs[i],&ys[i]);
printf("Enter x shear factor:");
scanf("%f",&shearXfactor);
printf("Enter y shear factor:");
scanf("%f",&shearYfactor);

initgraph(&graDriver,&graMode,"C:\\TURBOC3\\BGI\\");
setcolor(RED);
DrawFn();//original
shearAlongX();
setcolor(BLUE);
DrawFn();//Xshear
shearAlongY();
setcolor(GREEN);
DrawFn();
getch();
return 0;
}
}
void DrawFn()
{
for(i=0;i<n;i++)
 {
 line(xs[i],ys[i],xs[(i+1)%n],ys[(i+1)%n]);
 }
}

void scale()
{
for(i=0;i<n;i++)
 {
 xs[i]=xs[0]+(int)((float)(xs[i]-xs[0])*sfx);
 ys[i]=ys[0]+(int)((float)(ys[i]-ys[0])*sfy);
 }
}

void translate()
{
for(i=0;i<n;i++)
 {
 xs[i]+=xshift;
 ys[i]+=yshift;
 }

}
void degToRad()
{
radian=(float)degree*3.14f/180;
}

void rotation()
{
float t,v;
for(i=0;i<n;i++)
 {
 t=xs[i]-xp;
 v=ys[i]-yp;
 xs[i]=xp+floor(t*cos(radian)-v*sin(radian));
 ys[i]=yp+floor(v*cos(radian)+t*sin(radian));
 }
}

void FlipV()
{
tempXaxis=getmaxy()/2;
for(i=0;i<n;i++)
 ys[i]=tempXaxis+(tempXaxis-ys[i]);
//drawing horizontal axis to flip about

for(i=0;i<getmaxx();i++)
 putpixel(i,tempXaxis,WHITE);
}

void FlipH()
{
tempYaxis=getmaxx()/2;
for(i=0;i<n;i++)
 xs[i]=tempYaxis+(tempYaxis-xs[i]);
setcolor(WHITE);
//drawing vertical axis
for(i=0;i<getmaxy();i++)
 putpixel(tempYaxis,i,WHITE);

}

void shearAlongX()
{
for(i=0;i<n;i++)
 xs[i]=xs[i]+shearXfactor*ys[i];
}

void shearAlongY()
{
for(i=0;i<n;i++)
 ys[i]=ys[i]+shearYfactor*xs[i];
}
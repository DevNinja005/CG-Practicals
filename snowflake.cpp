#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;
void koch(int x1, int y1, int x2, int y2, int lvl)
{
float angle = 60*M_PI/180;
int x3 = (2*x1 + x2)/3;
int y3 = (2*y1 + y2)/3;
int x4 = (x1 + 2*x2)/3;
int y4 = (y1 + 2*y2)/3;
int x = x3 + (x4-x3)*cos(angle) + (y4-y3)*sin(angle);
int y = y3 - (x4-x3)*sin(angle) + (y4-y3)*cos(angle);
if (lvl > 0)
{
koch(x1,y1,x3,y3,lvl-1);
koch(x3,y3,x,y,lvl-1);
koch(x,y,x4,y4,lvl-1);
koch(x4,y4,x2,y2,lvl-1);
}
else
{
line(x1,y1,x3,y3);
line(x3,y3,x,y);
line(x,y,x4,y4);
line(x4,y4,x2,y2);
}
}
int main()
{
int gd = DETECT,gm;
initgraph(&gd, &gm, (char*)"");

int x1,y1,x2,y2,x3,y3,x4,y4,x,y,lvl;
cout<<"Enter values of x1,y1,x2,y2 : ";
cin>>x1>>y1>>x2>>y2;
cout<<"Enter the level of Koch Curve : ";
cin>>lvl;
float angle = 60*M_PI/180;
int x0 = x1 + (x2-x1)*cos(angle) + (y2-y1)*sin(angle);
int y0 = y1 - (x2-x1)*sin(angle) + (y2-y1)*cos(angle);

koch(x2,y2,x1,y1,lvl);
koch(x1,y1,x0,y0,lvl);
koch(x0,y0,x2,y2,lvl);

delay(100000);
closegraph();
return 0;
}

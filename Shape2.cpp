#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
void myline(float x1,float y1, float x2,float y2)
{
float x,y,len,dx,dy;
float xi,yi;
dx = x2-x1;
dy = y2-y1;
if(abs(dx)>=abs(dy)){
len = abs(dx);
}
else{
len = abs(dy);
}
xi = dx/len;
yi = dy/len;
x = x1+0.5;
y = y1+0.5;
int i=1;
while(i<=len){
putpixel( x,y,RED);
x = x+xi;
y = y+yi;
i++;
}
};
void mycircle(float cx,float cy,float rad)
{
float x,y,p;
x=0;
y=rad;
p = 3-(2*rad);
do{
putpixel(cx+x,cy-y,RED);
putpixel(cx-x,cy-y,RED);
putpixel(cx-x,cy+y,RED);
putpixel(cx+x,cy+y,RED);
putpixel(cx-y,cy+x,RED);
putpixel(cx+y,cy-x,RED);
putpixel(cx-y,cy-x,RED);
putpixel(cx+y,cy+x,RED);
if(p<0){
p=p+(4*x)+6;
}
else{
p=p+(4*(x-y))+10;
y=y-1;
}
x=x+1;
}while(x<y);  
}
int main()
{
float x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7,x8,y8,D,d,r,cx,cy;
cout<<"Enter x1:";
cin>>x1;
cout<<"Enter y1:";
cin>>y1;
cout<<"Enter x2:";
cin>>x2;
cout<<"Enter y2:";
cin>>y2;
int gd=DETECT , gm;
initgraph(&gd, &gm,(char*)"");
x3=x2;
y3=y1;
x4=x1;
y4=y2;
x5=(x1+x3)/2;
y5=y1;
x6=x2;
y6=(y3+y2)/2;
x7=x5;
y7=y2;
x8=x1;
y8=y6;
D=x3-x1;
d=y7-y5;
cx=x5;
cy=y6;
r=(D*d)/(2*(sqrt((d*d)+(D*D))));
mycircle(cx,cy,r);
myline(x1,y1,x4,y4);
myline(x4,y4,x2,y2);
myline(x2,y2,x3,y3);
myline(x3,y3,x1,y1);
myline(x8,y8,x5,y5);
myline(x5,y5,x6,y6);
myline(x6,y6,x7,y7);
myline(x7,y7,x8,y8);
delay(10000);
closegraph();
return(0);
}

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
putpixel(cy-y,cx+x,RED);
putpixel(cy-y,cx-x,RED);
putpixel(cy+y,cx-x,RED);
putpixel(cy+y,cx+x,RED);
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
float centx,centy,R,r,x1,y1,x2,y2,x3,y3;
cout<<"Enter centx:";
cin>>centx;
cout<<"Enter centy:";
cin>>centy;
cout<<"Enter radius:";
cin>>R;
int gd=DETECT , gm;
initgraph(&gd, &gm,(char*)"");
x1=centx;
y1=centy-R;
x2=centx-(0.866*R);
y2=centy+(R/2);
x3=centx+(0.866*R);
y3=centy+(R/2);
r=R/2;
mycircle(centx,centy,R);
mycircle(centx,centy,r);
myline(x1,y1,x2,y2);
myline(x2,y2,x3,y3);
myline(x3,y3,x1,y1);
delay(10000);
closegraph();
return(0);
}
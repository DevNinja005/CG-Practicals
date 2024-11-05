#include<iostream>
#include<math.h>
#include<graphics.h>
using namespace std;

void move(int j,int h, int &x, int &y)
{
    if (j==1)   //d
        y=y+h;
    else if (j==2)  //r
        x=x+h;
    else if (j==3)  //u
        y=y-h;
    else if (j==4)  //l
        x=x-h;
    lineto(x,y);
}

void hilbert( int u, int r, int d, int l, int n, int h, int &x, int &y)
{
    if(n>0)
    {
        n--;
        hilbert(r,u,l,d,n,h,x,y);
        move(u,h,x,y);
        hilbert(u,r,d,l,n,h,x,y);
        move(r,h,x,y);
        hilbert(u,r,d,l,n,h,x,y);
        move(d,h,x,y);
        hilbert(l,d,r,u,n,h,x,y);
    }
}

int main()
{
    int x=100 , y=200 , h=25 , d=1 , r=2 , u=3 , l=4 , n=3;
    cout<<"Enter the value of n";
    cin>>n;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");
    moveto(x,y);
    hilbert(u,r,d,l,n,h,x,y);
    getch();
    closegraph();
    return 0;
}
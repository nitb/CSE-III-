/*---------------------
| Author: switchkiller |
----------------------*/
#include<iostream>
#include <stdio.h>
#include <graphics.h>
#include <math.h>
using namespace std;
void circleMidpoint(int, int, int);
void circlePlotPoints(int, int, int, int );
int main(){
  int xc,yc,r;
  int gd = DETECT, gm;
  cout<<"Enter the center and the radius: ";
  cin>>xc>>yc>>r;
  initgraph(&gd, &gm, NULL);
  circleMidpoint(xc, yc, r);
  getch();
  closegraph();
  return 0;
}
void circleMidpoint(int xc, int yc, int radius){
  int x=0, y=radius, p=1-radius;
  circlePlotPoints(xc,yc,x,y);
  while(x < y){
    x++;
    if (p < 0)
      p += 2*x+1;
      else{
        y--;
        p += 2*(x-y)+1;
      }
      circlePlotPoints(xc,yc,x,y);
  }
}
// This is a simple flood fill technique
void circlePlotPoints(int xc, int yc, int x, int y){
  putpixel (xc+x,yc+y,WHITE);
  putpixel (xc-x,yc+y,WHITE);
  putpixel (xc+x,yc-y,WHITE);
  putpixel (xc-x,yc-y,WHITE);
  putpixel (xc+y,yc+x,WHITE);
  putpixel (xc-y,yc+x,WHITE);
  putpixel (xc+y,yc-x,WHITE);
  putpixel (xc-y,yc-x,WHITE);
}

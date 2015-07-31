/*---------------------
| Author: switchkiller |
----------------------*/
#include <stdio.h>
#include <graphics.h>
#include <math.h>
void lineBresenham(int, int, int, int);
int main(){
  int x1, y1, xn, yn;
  int gd = DETECT, gm;
  printf("Enter the starting coordinates of line: ");
  scanf("%d %d", &x1, &y1);
  printf("Enter the ending coordinates of line: ");
  scanf("%d %d", &xn, &yn);
  initgraph(&gd, &gm, NULL);
  lineBresenham(x1, y1, xn, yn);
  getch();
  closegraph();
  return 0;
}
void lineBresenham(int x1,int y1,int xn,int yn){
  int dx=abs(xn-x1), dy=abs(yn-y1);
  int p=2*dy-dx;
  int tdy=2*dy, tdyx=2*(dy-dx);
  int x,y,end;
  if (x1>xn){
    x=xn;
    y=yn;
    end=x1;
  }
  else{
    x=x1;
    y=yn;
    end=xn;
  }
  putpixel(x,y,WHITE);
  while (x<end){
    x++;
    if (p < 0)
      p += tdy;
    else{
      y++;
      p += tdyx;
    }
    putpixel(x,y,WHITE);
  }
}

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
void lineBresenham(x1,y1,xn,yn){
  int dx=abs(x2-x1), dy=abs(y2-y1);
  int p=2*dy-dx;
  int tdy=2*dy, tdyx=2*(dy-dx);
  int x,y,end;
  if (x1>x2){
    x=x2;
    y=y2;
    end=x1;
  }
  else{
    x=x1;
    y=y2;
    end=x2;
  }
  putpixel(x,y);
  while (x<end){
    x++;
    if (p < 0)
      p += tdy;
    else{
      y++;
      p += tdyx;
    }
    putpixel(x,y);
  }
}

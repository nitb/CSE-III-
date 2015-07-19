#include <stdio.h>
#include <graphics.h> //Make sure you add linker -lgraph when you compile
void lineDDA(int, int, int, int);
int main()
{
  int x1, y1, xn, yn;
  int gd = DETECT, gm;
  printf("Enter the starting coordinates of line: ");
  scanf("%d %d", &x1, &y1);
  printf("Enter the ending coordinates of line: ");
  scanf("%d %d", &xn, &yn);
  initgraph(&gd, &gm, NULL);          //Set you path variable accordingly
  lineDDA(x1, y1, xn, yn);
  getch();
  closegraph();
  return 0;
}
void lineDDA(int x1, int y1, int xn, int yn)
{
  int dx, dy, m, i;
  m = (yn-y1)/(xn-x1);
  for (i=x1; i<=xn; i++)
  {
    if (m <= 1)
    {
      dx = 1;
      dy = m * dx;
    }
    else
    {
      dy = 1;
      dx = dy / m;
    }
    x1 = x1 + dx;
    y1 = y1 + dy;
    putpixel(x1, y1, RED);
    delay(200);
  }
}

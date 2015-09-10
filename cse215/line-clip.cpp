#include<iostream>
#include<graphics.h>
using namespace std;
typedef struct coordinates{
  int x, y;
  char code[4];
}PT;
void drawwindow();
void drawline(PT p1, PT p2, int cl);
PT setcode(PT p);
int visibility(PT p1, PT p2);
PT resetendpt(PT p1, PT p2);


int main(){
  PT p1, p2;
  int gd = DETECT, gm, v;
  //Take two end points.
  cin >> p1.x >> p1.y;
  cin >> p2.x >> p2.y;
  // Draw window
  initgraph(&gd, &gm, NULL);
  drawwindow();
  p1 = setcode(p1);
  p2 = setcode(p2);
  v = visibility(p1, p2);
  switch(v){
    case 0 :
      // cleardevice();
      drawwindow();
      drawline(p1,p2,15);

  }
  getch();
  closegraph();
  return 0;
}

void drawwindow(){
  setcolor(RED);
  line(150, 100 , 450, 100);
  line(450, 100, 450, 350);
  line(450,350, 150, 350);
  line(150, 350, 150, 100);
}

void drawline(PT p1, PT p2, int cl){
  setcolor(cl);
  line(p1.x, p1.y, p2.x, p2.y);
}

PT setcode(PT p){
  PT ptemp;
  //Above.
  if (p.y < 100)
    ptemp.code[0] = '1';
  else
    ptemp.code[0] = '0';
  //Below.
  if (p.y > 350)
    ptemp.code[1] = '1';
  else
    ptemp.code[1] = '0';
  //Left.
  if (p.x < 150)
    ptemp.code[2] = '1';
  else
    ptemp.code[2] = '0';
  //Right.
  if (p.y > 450)
    ptemp.code[3] = '1';
  else
    ptemp.code[3] = '0';
  ptemp.x = p.x;
  ptemp.y = p.y;
  return (ptemp);
 }

 int visibility(PT p1, PT p2){
   int i, flag = 0;

   for (i = 0; i < 4; i++)
     if (p1.code[i] != '0' || (p2.code[i] != '0'))
      flag = 1;
   if (flag == 0)
    return 0;
  else{
   if (p1.code[i] == p2.code[i] && p1.code[i] == '1')
    flag = 0;
  }
  if (flag)
    return (1);
  return (2);
 }

 PT resetendpt(PT p1, PT p2){
   PT temp;
   int x, y, i;
   float m, k;
   if (p1.code[2] == '1') //Cut the left edge.
    x = 150;
   if (p1.code[3] == '1') //Cut the right edge.
    x = 450;
   if ((p1.code[2]) == '1' || (p1.code[3] == '1')){
     m = (float) (p2.y-p1.y)/(p2.x-p1.x);
     k = (float) (p1.y+(m*(x-p1.x)));
     temp.y = k;
     temp.x = x;
     for (i = 0; i < 4; i++)
      temp.code[i] = p1.code[i];
     if (temp.y <= 350 && temp.y >= 100)
      return (temp);
   }
   if (p1.code[0] == '1')
    y = 100;
   if (p1.code[1] == '1')
    y = 350;
   if ((p1.code[0] == '1') || (p1.code[1] == '1')){
     m = (float) (p2.y - p1.y)/(p2.x - p1.x);
     k = (float) (p1.x + (y - p1.y)/m);
     temp.x = k;
     temp.y = y;
     for (i = 0; i < 4; i++)
      temp.code[i] = p1.code[i];
    return temp;
  }
  else
    return (p1);
}

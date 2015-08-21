/*-------------------------
| Author: Barun Singhania |
-------------------------*/
//Draw a circle relative to windowX
#include<GL/glut.h>
class screenPoint
{
  private:
    GLint x,y;
  public:
    /* Defult constructor: initializes coordinates position to (0,0) */
    screenPoint()
    {
      x = 0;
      y = 0;
    }
    //Methods
    void setCoordinates(GLint xCoordinateValue, GLint yCoordinateValue)
    {
      x = xCoordinateValue;
      y = yCoordinateValue;
    }
    GLint getx () const
    {
      return x;
    }
    GLint gety () const
    {
      return y;
    }
    void incrementx ()
    {
      x++;
    }
    void decrementy ()
    {
      y--;
    }
};

void setPixel(GLint xCoordinate, GLint yCoordinate)
{
  glBegin(GL_POINTS);
  glVertex2i(xCoordinate, yCoordinate);
  glEnd();
  glFlush(); //process all OpenGL functions as quickly as possible
}
void circleMidPoint(GLint xc, GLint yc, GLint radius)
{
  screenPoint circlePoint;
  //initialize value for midpoint parameter
  GLint p = 1-radius;
  //set coordinates for top point of circle
  circlePoint.setCoordinates(0,radius);
  //function prototype
  void circlePlotPoints(GLint, GLint, screenPoint);
  //plot the initial point in each quadrant
  circlePlotPoints(xc, yc, circlePoint);
  //calculate the next point and plot in each octant
  while(circlePoint.getx() < circlePoint.gety())
  {
    circlePoint.incrementx();
    if(p<0)
      p += 2 * circlePoint.getx() + 1;
    else{
      circlePoint.decrementy ();
      p += 2 * (circlePoint.getx () - circlePoint.gety ()) + 1;
    }
    circlePlotPoints(xc, yc, circlePoint);
  }
}

void keyboard(unsigned char c, int x, int y)
{
  if (c == 27)  //ESC key
    exit(0);
}

void mouse(int button, int state, int x, int y)
{
  if (button == GLUT_RIGHT_BUTTON) {
            exit(0);
    }
}
void circlePlotPoints(GLint xc, GLint yc, screenPoint circPoint)
{
  setPixel(xc + circPoint.getx () , yc + circPoint.gety ());
  setPixel(xc - circPoint.getx () , yc + circPoint.gety ());
  setPixel(xc + circPoint.getx () , yc - circPoint.gety ());
  setPixel(xc - circPoint.getx () , yc - circPoint.gety ());
  setPixel(xc + circPoint.gety () , yc + circPoint.getx ());
  setPixel(xc - circPoint.gety () , yc + circPoint.getx ());
  setPixel(xc + circPoint.gety () , yc - circPoint.getx ());
  setPixel(xc - circPoint.gety () , yc - circPoint.getx ());
}

//Initialize OpenGL

void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0); //set display-window color to black
  glMatrixMode(GL_PROJECTION); //set projection parameters
  gluOrtho2D(0.0,300.0,0.0,300.0);
}

void drawMyCircle(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear display-window
  glColor3f(1.0,0.0,0.0); //set pixel color to red
  glPointSize(3.0);
  GLint xCenter = 150;
  GLint yCenter = 150;
  GLint raduis = 100;
  circleMidPoint(xCenter, yCenter, raduis);
}

int main(int argc, char**argv)
{
  glutInit(&argc, argv); //initialize GLUT
  glutInitWindowPosition(100,100); //set top-left display-window position
  glutInitWindowSize(640,480); //set display-window width and height
  glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGB); //set display mode

  //Now display the window with a title
  glutCreateWindow("Hello Computer Graphics :D ");
  init(); //execute initialization procedure of OpenGL
  glutDisplayFunc(drawMyCircle); //send graphics to display window
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
  glutMainLoop(); //display everything and wait

  return 0;
}

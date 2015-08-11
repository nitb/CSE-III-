
#include<GL/glut.h> //Make sure you have set up the opengl glut library before you compile the code.
#include<iostream>
using namespace std;
const float pi = 3.14159;

struct scrPt
{
	GLint x,y;
};

class screenPt
{
	private:
		GLint x,y;

	public:
		screenPt()
		{
			x = y = 0;}
		void setCoords(GLint xCoordValue, GLint yCoordValue)
		{
			x = xCoordValue;
			y = yCoordValue;}

		GLint getx() const
		{
			return x;}

		GLint gety() const
		{
			return y;}

		void incrementx()
		{
			x++;}

		void decrementy()
		{
			y--;}
};

void circlePlotPoints(GLint xc, GLint yc, screenPt circPt);
void circleMidPoint(scrPt circCtr, GLint radius);
void render();

void keyboard(unsigned char c, int x, int y);

void mouse(int button, int state, int x, int y);

void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0); //set display-window color to black
  glMatrixMode(GL_PROJECTION); //set projection parameters
  gluOrtho2D(0.0,300.0,0.0,300.0);
}

int main(int argc, char** argv)
{ glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(640, 480);
  glutCreateWindow("Hello Graphics World :D");
	init();
  //Register Callbacks
  glutDisplayFunc(render);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);

  glutMainLoop();
}

void keyboard(unsigned char c, int x, int y)
{
  if (c == 27)  //ESC key
    exit(0);
}

void mouse(int button, int state, int x, int y)
{

}
void PieChart()
{
  int winWidth = glutGet(GLUT_WINDOW_X);
  int winHeight = glutGet(GLUT_WINDOW_Y);
	scrPt circCtr;
	GLint radius = winWidth/4;
	circCtr.x = winWidth/2;
	circCtr.y = winHeight/2;
	circleMidPoint(circCtr,radius);
}
void render(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  PieChart();
  glutSwapBuffers();
  glFlush();
}

void circleMidPoint(scrPt circCtr, GLint radius)
{
	GLint xc = circCtr.x;
	GLint yc = circCtr.y;

	screenPt circPt;
	GLint p = 1 - radius;

	circPt.setCoords(0,radius);
	circlePlotPoints(xc,yc,circPt);
	while(circPt.getx() < circPt.gety())
	{
		circPt.incrementx();
		if(p < 0)
			p += 2 * circPt.getx();
		else
		{
			circPt.decrementy();
			p += 2 * (circPt.getx() - circPt.gety()) + 1;
		}
		circlePlotPoints(xc,yc,circPt);
	}
}


void setPixel(GLint xCoord, GLint yCoord)
{
	glBegin(GL_POINTS);
		glVertex2i (xCoord,yCoord);
	glEnd();
  glFlush();
}


void circlePlotPoints(GLint xc, GLint yc, screenPt circPt)
{
	setPixel(xc + circPt.getx(), yc + circPt.gety());
	setPixel(xc - circPt.getx(), yc + circPt.gety());
	setPixel(xc + circPt.getx(), yc - circPt.gety());
	setPixel(xc - circPt.getx(), yc - circPt.gety());
	setPixel(xc + circPt.getx(), yc + circPt.gety());
	setPixel(xc - circPt.getx(), yc + circPt.gety());
	setPixel(xc + circPt.getx(), yc - circPt.gety());
	setPixel(xc - circPt.getx(), yc - circPt.gety());
}

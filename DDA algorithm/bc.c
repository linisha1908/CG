#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

void BresenCircle(int x1, int y1, int r)
{
	int Xp,Yp;
	//Step 1
	int x0=0;
	int y0=r;

	//Step 2
	int d = 3-2r;

	glVertex2d(x0,y0);
	while(Xp>=Yp){
		if(x1==0 && y1==0){
			Xp=x0+x1;
			Yp=y0+y1;
			glVertex2d(Xp,Yp);
		}
		if(d<0){
			x1=x1+1;
			y1=y1;
			d=d+4*x1+6;
		}
		else{
			x1=x1+1;
                        y1=y1-1;
                        d=d+4*(x1-y1)+10;
		}
		glVertex2d(x1,y1);
	}
}

void draw()
{
	int x1,y1,r;
	cout<<"Type a Center point: \n";
	cin>>x1;
	cin>>y1;
	cout<<"Type Radius: \n";
        cin>>r;


	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);

	BresenCircle(x1,y1,r);
	glEnd();
	glFlush();
}

void init(){
	glClearColor(1.0,1.0,1.0,0);
        glColor3f(0.0, 1.0,0.0);
        gluOrtho2D(0,640,0,640);

}

int main(int argc,char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,640);
	glutInitWindowPosition(0,0);
	glutCreateWindow("H&M");
	init();

	glutDisplayFunc(draw);

	glutMainLoop();

	return 0;

}





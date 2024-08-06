#include <glut.h>

void display (void) {
	
	glclear (GL_COLOR_BUFFER_BIT);
	glbegin (GL_POLYGON);
	glvertex2f(-0,3, -0,3);
	glvertex2f(-0,3, 0,3);
	glvertex2f(0,3, 0,3);
	glvertex2f(0,3, -0,3);
	
	glEnd();
	glFlush();
	
}

int main (void){
	
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("olá mundo");
	glutDisplayFunc(display);
	glutMainLoop();
	
}

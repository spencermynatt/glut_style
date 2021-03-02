
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
void dont_draw_over() {
	glEnable(GL_DEPTH_TEST);
}
void window_resize(int w, int h) {
	glViewport(0, 0, w, h);
	//this converts from coordinates to pixel values


	glMatrixMode(GL_PROJECTION); //projection matrix
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
	//camera angle, width to height ratio, near z clip, far z clip
}
void draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clears pix info
	glMatrixMode(GL_MODELVIEW); //model matrix
	glBegin(GL_QUADS);
	glVertex3f(-0.7f, -1.5f, -5.0f);
	glVertex3f(0.7f, -1.5f, -5.0f);
	glVertex3f(0.4f, -0.5f, -5.0f);
	glVertex3f(-0.4f, -0.5f, -5.0f);
	glEnd();
	glutSwapBuffers(); //sends 3d scene to screen

}
int main(int argc, char** argument_vector) {
	glutInit(&argc, argument_vector);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutCreateWindow("hi");
	dont_draw_over();
	glutDisplayFunc(draw);
	glutReshapeFunc(window_resize);
	glutMainLoop();
	return 0;
}
/*

argv and argc are how command line arguments are passed to main() in C and C++.
rgc is the number of arguments being passed
into your program from the command line and argv is the array of arguments.


*/

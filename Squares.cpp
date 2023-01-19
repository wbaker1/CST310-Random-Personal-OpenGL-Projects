#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    for(int i = -5; i < 6; i++) {
        for(int j = -5; j < 6; j++) {
            glVertex2f(i, j);
            glVertex2f(i+1, j);
            glVertex2f(i+1, j+1);
            glVertex2f(i, j+1);
        }
    }
    glEnd();
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-6.0, 6.0, -6.0, 6.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Grid of Squares");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

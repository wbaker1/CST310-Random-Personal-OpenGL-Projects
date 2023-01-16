#include <iostream>
#include <glut.h>

void display() {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    // Set the camera position
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

    // Draw the head
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-0.5, 0.5, -2);
    glVertex3f(-0.5, 1, -2);
    glVertex3f(0.5, 1, -2);
    glVertex3f(0.5, 0.5, -2);
    glEnd();

    // Draw the body
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-0.4, 0, -2);
    glVertex3f(-0.4, 0.5, -2);
    glVertex3f(0.4, 0.5, -2);
    glVertex3f(0.4, 0, -2);
    glEnd();
    
    // Draw the legs
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-0.2, 0, -2);
    glVertex3f(-0.2, -0.5, -2);
    glVertex3f(0.2, -0.5, -2);
    glVertex3f(0.2, 0, -2);
    glEnd();
    
    // Draw the arms
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-0.5, 0.25, -2);
    glVertex3f(-0.5, 0.5, -2);
    glVertex3f(-0.4, 0.5, -2);
    glVertex3f(-0.4, 0.25, -2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(0.4, 0.25, -2);
    glVertex3f(0.4, 0.5, -2);
    glVertex3f(0.5, 0.5, -2);
    glVertex3f(0.5, 0.25, -2);
    glEnd();
    
    // Finish the drawing
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Nico Robin");
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 800.0 / 600, 1, 100);
    glMatrixMode(GL_MODELVIEW);
    glutMainLoop();
    return 0;
}

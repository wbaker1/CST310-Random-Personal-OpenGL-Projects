#include <iostream>
#include <glut.h>

void display() {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Set the camera position
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

    // Draw the living room floor
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-5, 0, -5);
    glVertex3f(-5, 0, 5);
    glVertex3f(5, 0, 5);
    glVertex3f(5, 0, -5);
    glEnd();

    // Draw the walls
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-5, 0, -5);
    glVertex3f(-5, 5, -5);
    glVertex3f(5, 5, -5);
    glVertex3f(5, 0, -5);

    glVertex3f(-5, 0, 5);
    glVertex3f(-5, 5, 5);
    glVertex3f(5, 5, 5);
    glVertex3f(5, 0, 5);

    glVertex3f(-5, 0, -5);
    glVertex3f(-5, 5, -5);
    glVertex3f(-5, 5, 5);
    glVertex3f(-5, 0, 5);

    glVertex3f(5, 0, -5);
    glVertex3f(5, 5, -5);
    glVertex3f(5, 5, 5);
    glVertex3f(5, 0, 5);
    glEnd();

    // Draw the couch
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-2, 0, -2);
    glVertex3f(-2, 1, -2);
    glVertex3f(2, 1, -2);
    glVertex3f(2, 0, -2);
    glEnd();

    // Draw the TV
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(3, 0, -3);
    glVertex3f(3, 2, -3);
    glVertex3f(4, 2, -3);
    glVertex3f(4, 0, -3);
    glEnd();
    
    // Draw the coffee table
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-1, 0, -1);
    glVertex3f(-1, 0.2, -1);
    glVertex3f(1, 0.2, -1);
    glVertex3f(1, 0, -1);
    glEnd();

    // Draw the picture frame
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(4, 2, -4);
    glVertex3f(4, 3, -4);
    glVertex3f(5, 3, -4);
    glVertex3f(5, 2, -4);
    glEnd();

    // Draw the picture frame border
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex3f(4, 2, -4);
    glVertex3f(4, 3, -4);
    glVertex3f(5, 3, -4);
    glVertex3f(5, 2, -4);
    glEnd();

    // Draw the table lamp
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(1.5, 0, 1);
    glVertex3f(1.5, 2, 1);
    glVertex3f(1.6, 2, 1);
    glVertex3f(1.6, 0, 1);
    glEnd();

    // Draw the table lamp shade
    glBegin(GL_TRIANGLES);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(1.55, 2, 1);
    glVertex3f(1.55, 3, 1);
    glVertex3f(1.65, 2.5, 1);
    glEnd();

    // Draw the picture in the frame
    // (This can be done using a texture, but for simplicity's sake, we'll just use a solid color)
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(4.1, 2.1, -3.9);
    glVertex3f(4.1, 2.9, -3.9);
    glVertex3f(4.9, 2.9, -3.9);
    glVertex3f(4.9, 2.1, -3.9);
    glEnd();

    // Finish the drawing
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("The Simpsons Living Room");
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 800.0 / 600, 1, 100);
    glMatrixMode(GL_MODELVIEW);
    glutMainLoop();
    return 0;
}

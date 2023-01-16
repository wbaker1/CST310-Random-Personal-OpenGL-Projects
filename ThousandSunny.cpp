#include <iostream>
#include <glut.h>
#include <SOIL.h>

// Variables for the ship's texture
GLuint shipTexture;

void display() {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Set the camera position
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

    // Enable texturing
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, shipTexture);

    // Draw the ship's hull
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(-1, 0, -2);
    glTexCoord2f(1, 0); glVertex3f(-1, 1, -2);
    glTexCoord2f(1, 1); glVertex3f(1, 1, -2);
    glTexCoord2f(0, 1); glVertex3f(1, 0, -2);
    glEnd();

    // Disable texturing
    glDisable(GL_TEXTURE_2D);

    // Draw the ship's deck
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-0.5, 1, -1.5);
    glVertex3f(-0.5, 1.5, -1.5);
    glVertex3f(0.5, 1.5, -1.5);
    glVertex3f(0.5, 1, -1.5);
    glEnd();

    // Draw the ship's mast
    glBegin(GL_TRIANGLES);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(0, 1.5, -1.5);
    glVertex3f(0, 2.5, -1.5);
    glVertex3f(0.1, 2, -1.5);
    glEnd();

    // Draw the ship's sails
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-0.4, 2, -1.5);
    glVertex3f(-0.4, 2.5, -1.5);
    glVertex3f(0.4, 2.5, -1.5);
    glVertex3f(0.4, 2, -1.5);
    glEnd();

    // Draw the ship's flag
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex3f(-0.1, 2.5, -1.5);
    glVertex3f(-0.1, 2.8, -1.5);
    glVertex3f(0.1, 2.8, -1.5);
     glVertex3f(0.1, 2.5, -1.5);
    glEnd();

    // Finish the drawing
    glFlush();
    glutSwapBuffers();
}

void init() {
    // Load the ship's texture
    shipTexture = SOIL_load_OGL_texture("thousand_sunny.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);

    // Set the texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("The Thousand Sunny");
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 800.0 / 600, 1, 100);
    glMatrixMode(GL_MODELVIEW);
    init();
    glutMainLoop();
    return 0;
}

/*
This is an example of how you could create a more advanced version of the code for creating a 3D model of The Thousand Sunny using OpenGL and C++. The key differences from the previous example is the addition of the SOIL library to load textures and the use of the SOIL_load_OGL_texture() function to load an image file as the ship's texture. The ship's hull is then drawn with texture coordinates to apply the texture to the ship's hull.
Please note that this is still a simplified version of the code, and a more accurate and detailed 3D model of the Thousand Sunny would require a lot more work, including creating the model in a 3D modeling software,animation, lighting and other advanced techniques. Also, this program is not complete and would need some modifications to run such as including the SOIL library and defining the path of the image file.
*/

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//#import <time.h>

#include "formes.h"

void drawSquare(int full) {
    /*
    Fonction qui dessine un carré canonique de côté 1, centré sur l'origine.
    */
    if (full == 0) {
        glBegin(GL_LINE_LOOP);
    }
    else {
        glBegin(GL_TRIANGLE_FAN);
    }
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(-0.5f, -0.5f);
    glEnd();
}

unsigned int CIRCLE_SUBDIVISIONS = 100;
void drawCircle(int full) {
    /*
    Fonction qui dessine un cercle de diamètre 1, centré sur l'origine.
    */
    if (full == 0) {
        glBegin(GL_LINE_LOOP);
    }
    else {
        glBegin(GL_TRIANGLE_FAN);
    }
    float deltaAngle = 2.0 * M_PI / (float)CIRCLE_SUBDIVISIONS;
    for (int i = 0; i < CIRCLE_SUBDIVISIONS; ++i) {
        float angle = i * deltaAngle;
        float x = 0.5 * cos(angle); // on multiplie par 0.5 pour avoir un diamètre de 1
        float y = 0.5 * sin(angle); // on multiplie par 0.5 pour avoir un diamètre de 1
        glVertex2f(x, y);
    }
    glEnd();
}
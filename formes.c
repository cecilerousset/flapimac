#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//#import <time.h>

#include "formes.h"

//Dessine un carré plein
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

//Dessine un carré avec une texture passée en paramètre
void drawSquareTextureJpg(int full, char* filename) {

    SDL_Surface* surface = IMG_Load(filename);
    if(!surface) {
        printf("IMG_Load: %s\n", IMG_GetError());
    }
    
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB, GL_UNSIGNED_BYTE, surface->pixels);
    glBindTexture(GL_TEXTURE_2D, 0);

    /*
    Fonction qui dessine un carré canonique de côté 1, centré sur l'origine.
    */

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);

    if (full == 0) {
        glBegin(GL_LINE_LOOP);
    }
    else {
        glBegin(GL_TRIANGLE_FAN);
    }
            glTexCoord2f(0.f, 0.f);
            glVertex2f(-0.5f, 0.5f);

            glTexCoord2f(1.f, 0.f);
            glVertex2f(0.5f, 0.5f);

            glTexCoord2f(1.f, 1.f);
            glVertex2f(0.5f, -0.5f);

            glTexCoord2f(0.f, 1.f);
            glVertex2f(-0.5f, -0.5f);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    glDeleteTextures(1,&textureID);
}

void drawFullScreenJpg(int full, char* filename) {

    SDL_Surface* surface = IMG_Load(filename);
    if(!surface) {
        printf("IMG_Load: %s\n", IMG_GetError());
    }
    
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB, GL_UNSIGNED_BYTE, surface->pixels);
    glBindTexture(GL_TEXTURE_2D, 0);

    /*
    Fonction qui dessine un carré canonique de côté 1, centré sur l'origine.
    */

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);

    if (full == 0) {
        glBegin(GL_LINE_LOOP);
    }
    else {
        glBegin(GL_TRIANGLE_FAN);
    }

            glTexCoord2f(0.f, 0.f);
            glVertex2f(-1.f, 1.f);

            glTexCoord2f(1.f, 0.f);
            glVertex2f(1.f, 1.f);

            glTexCoord2f(1.f, 1.f);
            glVertex2f(1.f, -1.f);

            glTexCoord2f(0.f, 1.f);
            glVertex2f(-1.f, -1.f);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    glDeleteTextures(1,&textureID);
}

void drawSquareTexturePng(int full, char* filename) {

    SDL_Surface* surface = IMG_Load(filename);
    if(!surface) {
        printf("IMG_Load: %s\n", IMG_GetError());
    }
    
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);
    glBindTexture(GL_TEXTURE_2D, 0);

    /*
    Fonction qui dessine un carré canonique de côté 1, centré sur l'origine.
    */

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);

    if (full == 0) {
        glBegin(GL_LINE_LOOP);
    }
    else {
        glBegin(GL_TRIANGLE_FAN);
    }
            glTexCoord2f(0.f, 0.f);
            glVertex2f(-0.5f, 0.5f);

            glTexCoord2f(1.f, 0.f);
            glVertex2f(0.5f, 0.5f);

            glTexCoord2f(1.f, 1.f);
            glVertex2f(0.5f, -0.5f);

            glTexCoord2f(0.f, 1.f);
            glVertex2f(-0.5f, -0.5f);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    glDeleteTextures(1,&textureID);
}

//Dessine un disque
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
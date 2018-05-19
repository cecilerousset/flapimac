#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "formes.h"


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

//Affiche l'image passée en paramètre sur tout l'écran
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

//Dessine un carré avec une texture passée en paramètre
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
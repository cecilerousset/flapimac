#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#import <time.h>

#include "vaisseau.h"
#include "formes.h"

//Initialise le vaisseau
Vaisseau creerVaisseau(float x, float y, float taille){
    Vaisseau temp = (Vaisseau) malloc(sizeof(Objet));
    if (!temp){
        printf("Erreur d'allocation\n");
        exit(0);
    }

    temp->posx = x;
    temp->posy = y;
    temp->taille = taille;
    temp->vitesse = 0;
    temp->vie = 10;
    /* Bounding box */
    /* 3/4 permet de faire une bounding box qui arrive pile aux bords du losange (vaisseau) */
    temp->boundingbox.pminx = temp->posx - taille*3/4;
    temp->boundingbox.pmaxx = temp->posx + taille*3/4;
    temp->boundingbox.pminy = temp->posy - taille*3/4;
    temp->boundingbox.pmaxy = temp->posy + taille*3/4;

    return temp;
}

//Dessine le vaisseau
void drawVaisseau(Vaisseau vaisseau){
    glPushMatrix();
    glTranslatef(vaisseau->posx, vaisseau->posy, 0);
    glScalef(vaisseau->taille, vaisseau->taille, 1);
    drawSquareTexturePng(1, "superman.png");
    glPopMatrix();
}

//Fait avancer la caméra
void resizeViewportVaisseau(Vaisseau vaisseau) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-3. + vaisseau->posx, 17. + vaisseau->posx, -10., 10.);
}

//Fait avancer le vaisseau
void avanceeVaisseau(Vaisseau vaisseau){
    vaisseau->posx +=0.08;
    vaisseau->boundingbox.pminx += 0.08;
    vaisseau->boundingbox.pmaxx += 0.08;
}

//Fait monter le vaisseau
void vaisseauMonte(Vaisseau vaisseau){
    if (!vaisseau){
        printf("Le vaisseau n'existe pas\n");
        return;
    }
    vaisseau->posy +=0.3;
    vaisseau->boundingbox.pminy += 0.3;
    vaisseau->boundingbox.pmaxy += 0.3;
}

//Fait descendre le vaisseau
void vaisseauDescend(Vaisseau vaisseau){
    if (!vaisseau){
        printf("Le vaisseau n'existe pas\n");
        return;
    }
    vaisseau->posy -=0.3;
    vaisseau->boundingbox.pminy -= 0.3;
    vaisseau->boundingbox.pmaxy -= 0.3;
}
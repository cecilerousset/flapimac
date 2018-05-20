#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

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
    temp->vitesse = 0.15;
    temp->vie = 10;
    /* Bounding box */
    /* 1/2 permet de faire une bounding box qui arrive aux bords du personnage */
    temp->boundingbox.pminx = temp->posx - taille/2;
    temp->boundingbox.pmaxx = temp->posx + taille/2;
    temp->boundingbox.pminy = temp->posy - taille/2;
    temp->boundingbox.pmaxy = temp->posy + taille/2;

    return temp;
}

//Dessine le vaisseau avec une texture
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
    vaisseau->posx += vaisseau->vitesse;
    vaisseau->boundingbox.pminx += vaisseau->vitesse;
    vaisseau->boundingbox.pmaxx += vaisseau->vitesse;
}

//Fait monter le vaisseau
void vaisseauMonte(Vaisseau vaisseau){
    if (!vaisseau){
        printf("Le vaisseau n'existe pas\n");
        return;
    }
    /* On vérifie qu'il ne sorte pas de la fenêtre */
    if (vaisseau->posy < 9.5){
        vaisseau->posy +=0.3;
        vaisseau->boundingbox.pminy += 0.3;
        vaisseau->boundingbox.pmaxy += 0.3;
    } 
}

//Fait descendre le vaisseau
void vaisseauDescend(Vaisseau vaisseau){
    if (!vaisseau){
        printf("Le vaisseau n'existe pas\n");
        return;
    }
    /* On vérifie qu'il ne sorte pas de la fenêtre */
    if (vaisseau->posy > -9.5){
        vaisseau->posy -=0.3;
        vaisseau->boundingbox.pminy -= 0.3;
        vaisseau->boundingbox.pmaxy -= 0.3;
    } 
}
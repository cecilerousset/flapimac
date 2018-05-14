#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include "arrivee.h"
#include "formes.h"
#include "vaisseau.h"

//Initialise la ligne d'arrivee
Arrivee creerArrivee(Arrivee arrivlist, float x, float y, float taille){
    Objet *arriv;
    if((arriv = malloc(sizeof(Objet))) == NULL){
        printf("Erreur d'allocation\n");
        exit(0);
    }
    arriv->posx = x;
    arriv->posy = y;
    arriv->taille = taille;
    arriv->vitesse = 0;
    arriv->suiv = arrivlist;

    /* Bounding box */
    /* 1/2 permet de faire une bounding box qui arrive pile aux bords du carré*/
    arriv->boundingbox.pminx = arriv->posx - taille/2;
    arriv->boundingbox.pmaxx = arriv->posx + taille/2;
    arriv->boundingbox.pminy = arriv->posy - taille/2;
    arriv->boundingbox.pmaxy = arriv->posy + taille/2;

    return arriv;
}

//Dessine la ligne d'arrivée
void drawArrivee(Arrivee arrivlist){
    while(arrivlist != NULL){
        glPushMatrix();
        glColor3f(255, 255, 255);
        glTranslatef(arrivlist->posx, arrivlist->posy, 0);
        glScalef(arrivlist->taille, arrivlist->taille, 1);
        drawSquare(1);
        glPopMatrix();
        
        arrivlist = arrivlist->suiv;
    }
}
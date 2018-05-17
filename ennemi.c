#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include "projectile.h"
#include "vaisseau.h"
#include "formes.h"

//Initialise le vaisseau
Ennemi creerEnnemi(Ennemi enlist, float x, float y, float taille){
    Objet *ennemi;
    if((ennemi = malloc(sizeof(Objet))) == NULL){
        printf("Erreur d'allocation\n");
        exit(0);
    }
    ennemi->posx = x;
    ennemi->posy = y;
    ennemi->taille = taille;
    ennemi->vitesse = 0.08;
    ennemi->suiv = enlist;

    /* Bounding box */
    /* 1/2 permet de faire une bounding box qui arrive pile aux bords du carré*/
    ennemi->boundingbox.pminx = ennemi->posx - taille/2;
    ennemi->boundingbox.pmaxx = ennemi->posx + taille/2;
    ennemi->boundingbox.pminy = ennemi->posy - taille/2;
    ennemi->boundingbox.pmaxy = ennemi->posy + taille/2;

    return ennemi;
}

//Dessine tous les ennemis
void drawEnnemi(Ennemi enlist){
    while (enlist != NULL){
        glPushMatrix();
        glColor3f(240, 195, 50);
        glTranslatef(enlist->posx, enlist->posy, 0);
        glScalef((enlist->taille)*1.5, (enlist->taille)*1.5, 1);
        drawSquareTexturePng(1, "spaceship.png");
        glPopMatrix();
        enlist = enlist->suiv;
    }  
}


//Fait bouger l'ennemi de haut en bas
void mouvementEnnemi(Ennemi enlist){
    while(enlist != NULL){
        if(enlist->boundingbox.pminy + enlist->vitesse <= -10. || enlist->boundingbox.pmaxy + enlist->vitesse >= 10.){
            enlist->vitesse = - enlist->vitesse;
        }
        enlist->boundingbox.pminy += enlist->vitesse;
        enlist->boundingbox.pmaxy += enlist->vitesse;
        enlist->posy += enlist->vitesse;
        

        enlist = enlist->suiv;
    }
}


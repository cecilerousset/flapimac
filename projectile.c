#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include "projectile.h"
#include "formes.h"
#include "vaisseau.h"

//Initialise les projectiles du vaisseau
Projectile creerProjectile(Projectile projlist, float x, float y, float taille){
    Objet *proj;
    if((proj = malloc(sizeof(Objet))) == NULL){
        printf("Erreur d'allocation\n");
        exit(0);
    }
    
    proj->posx = x;
    proj->posy = y;
    proj->taille = taille;
    proj->vie = 5;
    proj->vitesse = 0.5;
    proj->suiv = projlist;

    /* Bounding box */
    /* 1/2 et 1/8 permettent de faire une bounding box qui arrive pile aux bords du rectangle*/
    proj->boundingbox.pminx = proj->posx - taille/2;
    proj->boundingbox.pmaxx = proj->posx + taille/2;
    proj->boundingbox.pminy = proj->posy - taille/8;
    proj->boundingbox.pmaxy = proj->posy + taille/8;

    return proj;
}

//Dessine tous les projectiles n'ayant pas rencontré d'obstacle
void drawProjectile(Projectile projlist){
    while (projlist != NULL){
        if(projlist->vie != 0){
            glPushMatrix();
            glColor3f(240, 195, 0);
            glTranslatef(projlist->posx, projlist->posy, 0);
            glScalef(projlist->taille, projlist->taille/4, 1);
            drawSquare(1);
            glPopMatrix();
        }
        projlist = projlist->suiv;
    }  
}

//Fait avancer les projectiles
void avanceeProjectile(Projectile projlist){
    while(projlist != NULL){
        if (projlist->vie !=0){
            projlist->posx +=0.5;
            projlist->boundingbox.pminx += 0.5;
            projlist->boundingbox.pmaxx += 0.5;
        }
        projlist = projlist->suiv;
    }
}
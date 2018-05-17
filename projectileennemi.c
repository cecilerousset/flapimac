#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include "projectileennemi.h"
#include "ennemi.h"
#include "formes.h"
#include "vaisseau.h"


//Initialise les projectiles ennemis
ProjectileEnnemi creerProjectileEnnemi(ProjectileEnnemi projlistennemi, float x, float y, float taille){
    Objet *proj;
    if((proj = malloc(sizeof(Objet))) == NULL){
        printf("Erreur d'allocation\n");
        exit(0);
    }
    
    proj->posx = x;
    proj->posy = y;
    proj->taille = taille;
    proj->vie = 5;
    proj->vitesse = -1;
    proj->suiv = projlistennemi;

    /* Bounding box */
    /* 1/2 et 1/8 permettent de faire une bounding box qui arrive pile aux bords du rectangle*/
    proj->boundingbox.pminx = proj->posx - taille/2;
    proj->boundingbox.pmaxx = proj->posx + taille/2;
    proj->boundingbox.pminy = proj->posy - taille/8;
    proj->boundingbox.pmaxy = proj->posy + taille/8;

    return proj;
}

//Dessine tous les projectiles n'ayant pas rencontré d'obstacle
void drawProjectileEnnemi(ProjectileEnnemi projlistennemi){
    while (projlistennemi != NULL){
        if(projlistennemi->vie != 0){
            glPushMatrix();
            glColor3f(240, 195, 0);
            glTranslatef(projlistennemi->posx, projlistennemi->posy, 0);
            glScalef(projlistennemi->taille, projlistennemi->taille/4, 1);
            drawSquareTexturePng(1, "laser_r.png");
            glPopMatrix();
        }
        projlistennemi = projlistennemi->suiv;
    }  
}

//Fait avancer les projectiles
void avanceeProjectileEnnemi(ProjectileEnnemi projlistennemi){
    while(projlistennemi != NULL){
        if (projlistennemi->vie !=0){
            projlistennemi->posx += projlistennemi->vitesse;
            projlistennemi->boundingbox.pminx += projlistennemi->vitesse;
            projlistennemi->boundingbox.pmaxx += projlistennemi->vitesse;
        }
        projlistennemi = projlistennemi->suiv;
    }
}

ProjectileEnnemi tirEnnemi(ProjectileEnnemi projlistennemi, Ennemi enlist){
    while(enlist != NULL){
        projlistennemi = creerProjectileEnnemi(projlistennemi, enlist->posx, enlist->posy, 1);

        enlist = enlist->suiv;
    }
    return projlistennemi;
}

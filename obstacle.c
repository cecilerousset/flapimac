#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "obstacle.h"
#include "formes.h"
#include "vaisseau.h"

//Initialise les obstacles
Obstacle creerObstacle(Obstacle oblist, float x, float y, float taille){
    Objet *obst;
    if((obst = malloc(sizeof(Objet))) == NULL){
        printf("Erreur d'allocation\n");
        exit(0);
    }
    obst->posx = x;
    obst->posy = y;
    obst->taille = taille;
    obst->vitesse = 0;
    obst->suiv = oblist;

    /* Bounding box */
    /* 1/2 permet de faire une bounding box qui arrive pile aux bords du carré*/
    obst->boundingbox.pminx = obst->posx - taille/2;
    obst->boundingbox.pmaxx = obst->posx + taille/2;
    obst->boundingbox.pminy = obst->posy - taille/2;
    obst->boundingbox.pmaxy = obst->posy + taille/2;

    return obst;
}

//Dessine tous les obstacles
void drawObstacles(Obstacle oblist){
    while(oblist != NULL){
        glPushMatrix();
        //glColor3f(255, 0, 0);
        glTranslatef(oblist->posx, oblist->posy, 0);
        glScalef(oblist->taille, oblist->taille, 1);
        drawSquareTextureJpg(1, "wall.jpg");
        glPopMatrix();
        
        oblist = oblist->suiv;
    }
}
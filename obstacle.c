#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#import <time.h>

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
        glColor3f(0, 0, 0);
        glTranslatef(oblist->posx, oblist->posy, 0);
        glScalef(oblist->taille, oblist->taille, 1);
        drawSquare(1);
        glPopMatrix();
        
        oblist = oblist->suiv;
    }
}


/*Obstacle creerObstacle(float x, float y, float taille){
    Obstacle temp = (Obstacle) malloc(sizeof(Objet));
    if (!temp){
        printf("Erreur d'allocation\n");
        exit(0);
    }

    temp->posx = x;
    temp->posy = y;
    temp->taille = taille;
    temp->vitesse = 0;

    /* Bounding box */
    /* 1/2 permet de faire une bounding box qui arrive pile aux bords du carré
    temp->boundingbox.pminx = temp->posx - taille/2;
    temp->boundingbox.pmaxx = temp->posx + taille/2;
    temp->boundingbox.pminy = temp->posy - taille/2;
    temp->boundingbox.pmaxy = temp->posy + taille/2;
	
    return temp;
}

void drawObstacle(Obstacle obstacle){
    glPushMatrix();
    glColor3f(0, 205, 0);
    glTranslatef(obstacle->posx, obstacle->posy, 0);
    glScalef(obstacle->taille, obstacle->taille, 1);
    drawSquare(1);
    glPopMatrix();
}*/
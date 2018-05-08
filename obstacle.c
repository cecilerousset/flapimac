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


Obstacle creerObstacle(float x, float y, float taille){
    Obstacle temp = (Obstacle) malloc(sizeof(Objet));
    if (!temp){
        printf("Erreur d'allocation\n");
        exit(0);
    }

    temp->posx = x;
    temp->posy = y;
    temp->taille = taille;
    temp->vitesse = 0;
    temp->boundingbox.pminx = temp->posx - taille;
    temp->boundingbox.pmaxx = temp->posx + taille;
    temp->boundingbox.pminy = temp->posy - taille;
    temp->boundingbox.pmaxy = temp->posy + taille;
	
    return temp;
}

void drawObstacle(Obstacle obstacle){
    glPushMatrix();
    glColor3f(0, 205, 0);
    glTranslatef(obstacle->posx, obstacle->posy, 0);
    glScalef(obstacle->taille, obstacle->taille, 1);
    drawSquare(1);
    glPopMatrix();
}
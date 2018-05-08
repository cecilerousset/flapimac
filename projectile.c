#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#import <time.h>

#include "projectile.h"
#include "formes.h"
#include "vaisseau.h"

Projectile creerProjectile(float x, float y, float taille){
    Projectile temp = (Projectile) malloc(sizeof(Projectile));
    if (!temp){
        printf("Erreur d'allocation\n");
        exit(0);
    }

    temp->posx = x;
    temp->posy = y;
    temp->taille = taille;
    temp->vitesse = 0.5;

    return temp;
}

Projectile drawProjectile(Projectile projectile){
    glPushMatrix();
    glColor3f(240, 195, 0);
    glTranslatef(projectile->posx, projectile->posy, 0);
    glScalef(projectile->taille, projectile->taille/4, 1);
    drawSquare(1);
    glPopMatrix();
}

void tir(Vaisseau vaisseau){
    Projectile projectile = creerProjectile(vaisseau->posx+0.5, vaisseau->posy, 1);
}
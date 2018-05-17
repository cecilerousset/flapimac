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
        glColor3f(255, 0, 0);
        glTranslatef(oblist->posx, oblist->posy, 0);
        glScalef(oblist->taille, oblist->taille, 1);
        drawSquareTextureJpg(1, "wall.jpg");
        glPopMatrix();
        
        oblist = oblist->suiv;
    }
}


/*Obstacle creerObstacle(float x, float y, float taille){
=======
    obst->boundingbox.pminx = obst->posx - taille;
    obst->boundingbox.pmaxx = obst->posx + taille;
    obst->boundingbox.pminy = obst->posy - taille;
    obst->boundingbox.pmaxy = obst->posy + taille;

    return obst;
}

void drawObstacles(Obstacle oblist){
    while(oblist != NULL){
        glPushMatrix();
        glColor3f(0, 205, 0);
        glTranslatef(oblist->posx, oblist->posy, 0);
        glScalef(oblist->taille, oblist->taille, 1);
        drawSquare(1);
        glPopMatrix();
        
        oblist = oblist->suiv;
    }
}

// CODE A CECILE
Obstacle creerObstacle(float x, float y, float taille){
>>>>>>> 9c4695b81e6dc7861ae866b564e07d2b27aa1ff4
    Obstacle temp = (Obstacle) malloc(sizeof(Objet));
    if (!temp){
        printf("Erreur d'allocation\n");
        exit(0);
    }

    temp->posx = x;
    temp->posy = y;
    temp->taille = taille;
    temp->vitesse = 0;
<<<<<<< HEAD

    // Bounding box
     1/2 permet de faire une bounding box qui arrive pile aux bords du carré
    temp->boundingbox.pminx = temp->posx - taille/2;
    temp->boundingbox.pmaxx = temp->posx + taille/2;
    temp->boundingbox.pminy = temp->posy - taille/2;
    temp->boundingbox.pmaxy = temp->posy + taille/2;
	
=======
    temp->boundingbox.pminx = temp->posx - taille;
    temp->boundingbox.pmaxx = temp->posx + taille;
    temp->boundingbox.pminy = temp->posy - taille;
    temp->boundingbox.pmaxy = temp->posy + taille;
    
>>>>>>> 9c4695b81e6dc7861ae866b564e07d2b27aa1ff4
    return temp;
}

void drawObstacle(Obstacle oblist){
    glPushMatrix();
    glColor3f(0, 205, 0);
    glTranslatef(oblist->posx, oblist->posy, 0);
    glScalef(oblist->taille, oblist->taille, 1);
    drawSquare(1);
    glPopMatrix();
}

*/

/*void drawObstacle(Objet o);
void drawAllObstacles(Obstacle oblist);
void creerObstacle(Obstacle *list, float x, float y, float taille);
void drawObstacle(Obstacle *oblist)

void drawObstacle(Objet o){
    glPushMatrix();
    glColor3f(0, 205, 0);
    glTranslatef(o.posx, o.posy, 0);
    glScalef(o.taille, o.taille, 1);
    drawSquare(1);
    glPopMatrix();
<<<<<<< HEAD
=======
}
*/
/*void drawAllObstacles(Obstacle oblist){
    while(oblist != NULL){
        drawObstacle(*oblist);
        drawAllObstacles(oblist->suiv);
    }
}

void creerObstacle(Obstacle *list, float x, float y, float taille){
    if(*list == NULL){
        *list = (Obstacle) malloc(sizeof(Objet));
        if (!list){
            printf("Erreur d'allocation\n");
            exit(0);
        }

        &(*list)->posx = x;
        &(*list)->posy = y;
        &(*list)->taille = taille;
        &(*list)->vitesse = 0;
        &(*list)->suiv = NULL;
        &(*list)->boundingbox.pminx = *(&(*list)->posx) - taille;
        &(*list)->boundingbox.pmaxx = *(&(*list)->posx) + taille;
        &(*list)->boundingbox.pminy = *(&(*list)->posy) - taille;
        &(*list)->boundingbox.pmaxy = *(&(*list)->posy) + taille;
    }

    else {
        creerObstacle(&(*list)->suiv, x, y, taille);
    }
}

void drawObstacle(Obstacle *oblist){
    while(oblist != NULL){
        float *x = &(*oblist)->posx;
        float *y = &(*oblist)->posy;
        float *taille = &(*oblist)->taille;

        glPushMatrix();
        glColor3f(0, 205, 0);
        glTranslatef(*x, *y, 0);
        glScalef(*taille, *taille, 1);
        drawSquare(1);
        glPopMatrix();
        oblist = &(*oblist)->suiv;
    }
>>>>>>> 9c4695b81e6dc7861ae866b564e07d2b27aa1ff4
}*/
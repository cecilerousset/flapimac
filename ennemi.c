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
    ennemi->vitesse = 0;
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
        glScalef(enlist->taille, enlist->taille, 1);
        drawCircle(1);
        glPopMatrix();
        enlist = enlist->suiv;
    }  
}

int aleatoire(int min, int max){
    return (min + (rand () % (max-min+1)));
}


//Fait avancer le vaisseau
void ennemiMonte(Ennemi enlist){
    while(enlist != NULL){
        if (enlist->posy != 10.){
            if (enlist->posy != -10.){
                int ajout = aleatoire(-10, 10);
                enlist->posy += (ajout*0.01);
                //printf("%d\n",ajout);
                //printf("%f\n", enlist->posy);
            }
            
        }
        enlist = enlist->suiv;
    }
    /*vaisseau->posx +=0.08;
    vaisseau->boundingbox.pminx += 0.08;
    vaisseau->boundingbox.pmaxx += 0.08;*/
}

void mouvementEnnemi(Ennemi enlist){
    while(enlist != NULL){
        while(enlist->posy != 10.){
            enlist->posy +=0.1;
        }
        while(enlist->posy != -10.){
            enlist->posy -=0.1;
        }
        enlist = enlist->suiv;
    }
}

void ennemiDescend(Ennemi enlist){
    while(enlist != NULL){
        while (enlist->posy != -10.){
            enlist->posy -= 0.5;
        }
        enlist = enlist->suiv;
    }
    /*vaisseau->posx +=0.08;
    vaisseau->boundingbox.pminx += 0.08;
    vaisseau->boundingbox.pmaxx += 0.08;*/
}

/*//Fait monter le vaisseau
void vaisseauMonte(Vaisseau vaisseau){
    if (!vaisseau){
        printf("Le vaisseau n'existe pas\n");
        return;
    }
    vaisseau->posy +=0.5;
    vaisseau->boundingbox.pminy += 0.5;
    vaisseau->boundingbox.pmaxy += 0.5;
}

//Fait descendre le vaisseau
void vaisseauDescend(Vaisseau vaisseau){
    if (!vaisseau){
        printf("Le vaisseau n'existe pas\n");
        return;
    }
    vaisseau->posy -=0.5;
    vaisseau->boundingbox.pminy -= 0.5;
    vaisseau->boundingbox.pmaxy -= 0.5;
}*/
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#import <time.h>

#include "vaisseau.h"
#include "formes.h"


Vaisseau creerVaisseau(float x, float y, float taille){
    Vaisseau temp = (Vaisseau) malloc(sizeof(Objet));
    if (!temp){
        printf("Erreur d'allocation\n");
        exit(0);
    }

    temp->posx = x;
    temp->posy = y;
    temp->taille = taille;
    temp->vitesse = 0;
    temp->vie = 10;
    temp->boundingbox.pminx = temp->posx - taille;
    temp->boundingbox.pmaxx = temp->posx + taille;
    temp->boundingbox.pminy = temp->posy - taille;
    temp->boundingbox.pmaxy = temp->posy + taille;

    return temp;
}

void drawVaisseau(Vaisseau vaisseau){
    glPushMatrix();
    glColor3f(0, 205, 0);
    glTranslatef(vaisseau->posx, vaisseau->posy, 0);
    glRotatef(45, 0, 0, 1);
    glScalef(vaisseau->taille, vaisseau->taille, 1);
    drawSquare(1);
    glPopMatrix();
}

void resizeViewportVaisseau(Vaisseau vaisseau) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5. + vaisseau->posx, 15. + vaisseau->posx, -10., 10.); // On modifie la matrice de projection en lui disant de projeter à l'écran tous les objets se trouvant entre les bornes -4/4 (x) et -3/3 (y)
    //printf("%f %f\n", -5. + vaisseau->posx, 15. + vaisseau->posx);
}

void avanceeVaisseau(Vaisseau vaisseau){
    vaisseau->posx +=0.05;
    vaisseau->boundingbox.pminx += 0.05;
    vaisseau->boundingbox.pmaxx += 0.05;
}

void vaisseauMonte(Vaisseau vaisseau){
    if (!vaisseau){
        printf("Le vaisseau n'existe pas\n");
        return;
    }
    vaisseau->posy +=0.5;
    vaisseau->boundingbox.pminy += 0.5;
    vaisseau->boundingbox.pmaxy += 0.5;
}

void vaisseauDescend(Vaisseau vaisseau){
    if (!vaisseau){
        printf("Le vaisseau n'existe pas\n");
        return;
    }
    vaisseau->posy -=0.5;
}
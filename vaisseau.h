#ifndef VAISSEAU_H
#define VAISSEAU_H

#include "bbox.h"

typedef struct objet {
    float posx, posy;
    float taille;
    float vitesse;
    float vie;
    float espacetir;
    float momenttir;
    struct objet *suiv;
    BBOX boundingbox;
} Objet, *Vaisseau, *Obstacle, *Projectile, *Ennemi, *ProjectileEnnemi, *Arrivee;

Vaisseau creerVaisseau(float x, float y, float taille);
void drawVaisseau(Vaisseau vaisseau);
void resizeViewportVaisseau(Vaisseau vaisseau);
void avanceeVaisseau(Vaisseau vaisseau);
void vaisseauMonte(Vaisseau vaisseau);
void vaisseauDescend(Vaisseau vaisseau);

#endif
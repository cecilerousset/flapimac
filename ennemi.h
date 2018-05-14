#ifndef ENNEMI_H
#define ENNEMI_H

#include "vaisseau.h"

Ennemi creerEnnemi(Ennemi enlist, float x, float y, float taille);
void drawEnnemi(Ennemi enlist);
void mouvementEnnemi(Ennemi enlist);

#endif
#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "vaisseau.h"

Projectile creerProjectile(Projectile projlist, float x, float y, float taille);
void drawProjectile(Projectile projlist);
void avanceeProjectile(Projectile projlist);

#endif
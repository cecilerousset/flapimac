#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "vaisseau.h"

Projectile creerProjectile(float x, float y, float taille);
Projectile drawProjectile(Projectile projectile);
void tir(Vaisseau vaisseau);

#endif
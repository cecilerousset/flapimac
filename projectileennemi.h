#ifndef PROJECTILEENNEMI_H
#define PROJECTILEENNEMI_H

#include "vaisseau.h"

ProjectileEnnemi creerProjectileEnnemi(ProjectileEnnemi projlistennemi, float x, float y, float taille);
void drawProjectileEnnemi(ProjectileEnnemi projlistennemi);
void avanceeProjectileEnnemi(ProjectileEnnemi projlistennemi);
ProjectileEnnemi tirEnnemi(ProjectileEnnemi projlistennemi, Ennemi enlist);
ProjectileEnnemi tir(Ennemi enlist, ProjectileEnnemi projlistennemi, float time);

#endif
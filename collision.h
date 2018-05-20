#ifndef COLLISION_H
#define COLLISION_H

void collisionObstacle(Vaisseau vaisseau, Obstacle obstacle);
void collisionProjectile(Projectile projlist, Obstacle oblist);
void collisionProjectileEnnemi(Vaisseau vaisseau, ProjectileEnnemi projlistennemi);
void collisionEnnemi(Projectile projlist, Ennemi enlist);
void collisionVaisseauEnnemi(Vaisseau vaisseau, Ennemi enlist);
int collisionArrivee(Vaisseau vaisseau, Arrivee arrivlist);


#endif
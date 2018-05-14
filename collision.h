#ifndef COLLISION_H
#define COLLISION_H

void collisionObstacle(Vaisseau vaisseau, Obstacle obstacle);
void collisionProjectile(Projectile projlist, Obstacle oblist);
void collisionProjectileEnnemi(Vaisseau vaisseau, ProjectileEnnemi projlistennemi);
int collisionArrivee(Vaisseau vaisseau, Arrivee arrivlist);


#endif
#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "vaisseau.h"

Obstacle creerObstacle(Obstacle oblist, float x, float y, float taille);
void drawObstacles(Obstacle oblist);

/*Obstacle creerObstacle(float x, float y, float taille);
void drawObstacle(Obstacle obstacle);*/

#endif
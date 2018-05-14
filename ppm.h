#ifndef PPM_H
#define PPM_H

#include "vaisseau.h"

void creeMap(char *filename, Obstacle oblist, Vaisseau vaisseau, Projectile projlist);
float resizeY(float value, float istart, float istop, float ostart, float ostop);

#endif
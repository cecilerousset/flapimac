#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#import <time.h>

#include "bbox.h"
#include "vaisseau.h"

void collisionObstacle(Vaisseau vaisseau, Obstacle obstacle){
	//le vaisseau arrive par la gauche en x
    if(vaisseau->boundingbox.pmaxx >= obstacle->boundingbox.pminx && vaisseau->boundingbox.pminx <= obstacle->boundingbox.pmaxx){ 
        vaisseau->vie = 0;
        printf("coucou");
    }
    printf ("%f\n", vaisseau->vie);
}

void collisionProjectile(Vaisseau vaisseau, Projectile projectile){

}
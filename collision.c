#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include "bbox.h"
#include "vaisseau.h"

//Analyse si le vaisseau rencontre un obstacle
void collisionObstacle(Vaisseau vaisseau, Obstacle oblist){
	while (oblist != NULL){
		//collision en x
    	if(vaisseau->boundingbox.pmaxx >= oblist->boundingbox.pminx && vaisseau->boundingbox.pminx <= oblist->boundingbox.pmaxx){ 
        	//collision en y
        	if(vaisseau->boundingbox.pmaxy >= oblist->boundingbox.pminy && vaisseau->boundingbox.pminy <= oblist->boundingbox.pmaxy){
        		vaisseau->vie = 0;
        	}
    	}
    	oblist = oblist->suiv;
	}
}

//Analyse si le vaisseau rencontre un obstacle
void collisionProjectile(Projectile projlist, Obstacle oblist){
	while(projlist != NULL){
		while(oblist != NULL){
			//collision en x
    		if(projlist->boundingbox.pmaxx >= oblist->boundingbox.pminx && projlist->boundingbox.pminx <= oblist->boundingbox.pmaxx){ 
        		//collision en y
        		if(projlist->boundingbox.pmaxy >= oblist->boundingbox.pminy && projlist->boundingbox.pminy <= oblist->boundingbox.pmaxy){
        			projlist->vie = 0;
        		}
    		}
    		oblist = oblist->suiv;
		}
		projlist = projlist->suiv;
	}

}
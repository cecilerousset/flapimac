#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <strings.h>

#include "obstacle.h"
#include "vaisseau.h"
#include "ppm.h"

//Dessine les objets sur la map
void creeMap(char *filename, Obstacle oblist, Vaisseau vaisseau, Projectile projlist) {  
  
	FILE *ppmFile;
	char line[64];
	int w, h, i, j, r, g, b, max;
	float x, y;
  
  
	//On ouvre la map
	ppmFile = fopen(filename, "r");  
	if ( ppmFile == NULL ) {
		printf("Error opening the file\n");
    	exit(0);
  	}
  
	//La premiere ligne contient "P3"
	fgets(line, 64, ppmFile);
  
	
	//La deuxieme ligne contient la longueur(width) et hauteur (height)
	fgets(line, 64, ppmFile);
	sscanf(line, "%d %d", &w, &h);
    
 
	//La troisème ligne contient la valeur maximale pour la couleur
	fgets(line, 64, ppmFile);
	sscanf(line, "%d", &max);
    

	//On scanne la couleur du pixel
	//En fonction de la couleur, on cree l'élément correspondant
	for( i=0; i<h; i+=1) {
    	for( j=0; j<w; j+=1) {
    		fgets(line, 64, ppmFile);
    		sscanf(line, "%d", &r);
    		fgets(line, 64, ppmFile);
    		sscanf(line, "%d", &g);
    		fgets(line, 64, ppmFile);
    		sscanf(line, "%d", &b);
      
    		if ( r!=255 || g!=255 || b!=255 ) {
    			x = 1.0 * j;
    			y = resizeY((float) i, 0, h, 10 - 0.5, -10 - 0.5);
      
    			//Rouge = Obstacle
        		if ( r==max && g==0 && b==0 ) {
          			oblist = creerObstacle(oblist, x, y, 1);
        		}
        		//Bleu = 
        		if ( r==0 && g==0 && b==max ) {
        	
    	    	}
        		//Vert =
        		if ( r==0 && g==max && b==0 ) {
        	
        		}
    		}
    	}
  	}
    drawObstacles(oblist);
    collisionObstacle(vaisseau, oblist);

    collisionProjectile(projlist, oblist);
}

//Redimensionne Y pour qu'il corresponde à l'affichage voulu
float resizeY(float ligne, float ppmdebut, float ppmfin, float fenetredebut, float fenetrefin) {
  return fenetredebut + (fenetrefin - fenetredebut) * ((ligne - ppmdebut) / (ppmfin - ppmdebut));
}


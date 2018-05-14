#include <SDL/SDL.h>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <strings.h>

#include "vaisseau.h"
#include "level.h"

#define WINDOW_SCALE 800

void levelPPM(char *filename, Obstacle obsts) {  
  FILE *file;
  char line[64];
  int width, height, i, j, r, g, b, max;
  float x, y;
  
  file = fopen(filename, "r");  
  if(file == NULL) {
    printf("Error opening the file\n");
    exit(0);
  }
  
  sscanf(line, "%d %d", &width, &height);
  sscanf(line, "%d", &max);

  for( i=0; i<height; i+=1) {
    for( j=0; j<width; j+=1) {
      sscanf(line, "%d", &r);
      sscanf(line, "%d", &g);
      sscanf(line, "%d", &b);
      
      if ( r!=0 || g!=0 || b!=0 ) {
        x = 1.0 * j;
        y = 1.0 * i;
        fmap((float) i, 0, height, WINDOW_SCALE/2 - 0.5, -WINDOW_SCALE/2 - 0.5);
      
        if (r==max && g==0 && b==0) {
          obsts = creerObstacle(obsts, x, y, 1);
        }
      }
    }
  }
}
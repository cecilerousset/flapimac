#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include "formes.h"
#include "vaisseau.h"
#include "projectile.h"
#include "obstacle.h"
#include "bbox.h"
#include "collision.h"

int levelPPM(char *filename) {
	FILE *file = fopen(filename, "r");

	if(file != NULL) {
		fclose(file);
	}
	else {
		printf("Error levelPPM\n");
		return 0;
	}
	return 1;
}
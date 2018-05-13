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

/* Dimensions de la fenêtre */
static unsigned int WINDOW_WIDTH = 800;
static unsigned int WINDOW_HEIGHT = 800;

/* Nombre de bits par pixel de la fenêtre */
static const unsigned int BIT_PER_PIXEL = 32;

/* Nombre minimal de millisecondes separant le rendu de deux images */
static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;

void resizeViewport() {
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10., 10., -10., 10.); // On modifie la matrice de projection en lui disant de projeter à l'écran tous les objets se trouvant entre les bornes -4/4 (x) et -3/3 (y)
    SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BIT_PER_PIXEL, SDL_OPENGL | SDL_RESIZABLE);
}



int main(int argc, char** argv) {

    // Initialisation de la SDL
    if(-1 == SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "Impossible d'initialiser la SDL. Fin du programme.\n");
        return EXIT_FAILURE;
    }

    SDL_EnableKeyRepeat(40,40);
    
    // Ouverture d'une fenêtre et création d'un contexte OpenGL
    if(NULL == SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BIT_PER_PIXEL, SDL_OPENGL | SDL_RESIZABLE)) {
        fprintf(stderr, "Impossible d'ouvrir la fenetre. Fin du programme.\n");
        return EXIT_FAILURE;
    }

    SDL_WM_SetCaption("FLAPIMAC", NULL);
    resizeViewport();

    glClearColor(0.1, 0.1, 0.1, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); // On active la matrice MODELVIEW, celle chargée de la transformation des objets dans l'espace

    int loop = 1;
    Vaisseau vaisseau = creerVaisseau(-8,0,1);


        // Boucle d'affichage
    while(loop) {

        Uint32 startTime = SDL_GetTicks();

        // Code de dessin
        glClear(GL_COLOR_BUFFER_BIT); // Toujours commencer par clear le buffer

        
        //glLoadIdentity(); // On réinitialise la matric MODELVIEW à Identité, annulant ainsi toutes les transformations précédentes
        
        avanceeVaisseau(vaisseau);

        glPushMatrix();
        drawVaisseau(vaisseau);
        //drawProjectile(projectile);
        glPopMatrix();

        Obstacle oblist = NULL;

        //oblist = creerObstacle(oblist, 10, 5, 1);
        //oblist = creerObstacle(oblist, 10, 3, 1);
        
        levelPPM("map.ppm", oblist);
        drawObstacles(oblist);

        collisionObstacle(vaisseau, oblist);

        resizeViewportVaisseau(vaisseau);
        
        /* Vérifie que le vaisseau a encore de la vie, sinon arrete le jeu */
        if (vaisseau->vie <= 0){
            printf("Fin de partie\n\n");
            loop = 0;
        }

        // Boucle traitant les evenements
        SDL_Event e;
        while(SDL_PollEvent(&e)) {

            if(e.type == SDL_QUIT) {
                loop = 0;
                break;
            }

            switch(e.type) {
                case SDL_KEYDOWN:

                    switch(e.key.keysym.sym) {

                        case SDLK_q:
                            loop = 0;

                        break;

                        case SDLK_UP:
                            glPushMatrix();
                            vaisseauMonte(vaisseau);
                            drawVaisseau(vaisseau);
                        break;

                        case SDLK_DOWN:
                            glPushMatrix();
                            vaisseauDescend(vaisseau);
                            drawVaisseau(vaisseau);
                            glPopMatrix();
                        break;

                        case SDLK_SPACE:
                            glPushMatrix();
                            Projectile projectile = creerProjectile(vaisseau->posx+0.5, vaisseau->posy, 1);
                            drawProjectile(projectile);
                            glPopMatrix();
                        break;

                        default:
                            break;
                    }

                    break;


                case SDL_VIDEORESIZE:
                    WINDOW_WIDTH = e.resize.w;
                    WINDOW_HEIGHT = e.resize.h;
                    resizeViewport();

                default:
                    break;
            }
        }

        SDL_GL_SwapBuffers();
        Uint32 elapsedTime = SDL_GetTicks() - startTime;
        if(elapsedTime < FRAMERATE_MILLISECONDS) {
            SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
        }
    }

    // Liberation des ressources associées à la SDL
    SDL_Quit();

    return EXIT_SUCCESS;
}

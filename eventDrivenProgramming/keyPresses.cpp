#include <SDL2/SDL.h>
#include <stdio.h>
#include "../common/includes/basic_sdl_functions.h"

//Key press surfaces constants
enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};


//The window we'll be rendering to
SDL_Window** pWindow = new SDL_Window*;

//The surface contained by the window
SDL_Surface** pScreenSurface = new SDL_Surface*;

//The image we will load and show on the screen
SDL_Surface** pkeyPressSurfaces = new SDL_Surface*[KEY_PRESS_SURFACE_TOTAL];

//The current displayed image
SDL_Surface** pCurrentSurface = new SDL_Surface*;


//Window Dimensions
int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;

void terminate() {
	close(pWindow);
	delete pWindow;
	delete pScreenSurface;
    pWindow = NULL;
    pScreenSurface = NULL;

	closeAllSurfaces(pkeyPressSurfaces, KEY_PRESS_SURFACE_TOTAL);
    delete[] pkeyPressSurfaces;
    pkeyPressSurfaces = NULL;
    
    SDL_Quit();
}


int main(int argc, char* args[])
{
    //Define file paths
    std::string paths[KEY_PRESS_SURFACE_TOTAL];
    paths[KEY_PRESS_SURFACE_DEFAULT] = "media/default.bmp";
    paths[KEY_PRESS_SURFACE_UP] = "media/up.bmp";
    paths[KEY_PRESS_SURFACE_DOWN] = "media/down.bmp";
    paths[KEY_PRESS_SURFACE_LEFT] = "media/left.bmp";
    paths[KEY_PRESS_SURFACE_RIGHT] = "media/right.bmp";

    if(!init(pWindow, pScreenSurface)) {
        printf("Failed to initialize! Terminating Program.\n");
    } 
    else
    {
        if(!loadMedia(pkeyPressSurfaces, paths, KEY_PRESS_SURFACE_TOTAL)) {
            printf("Failed to load media! Terminating Program.\n");
        } 
        else
        {
            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            //Set default current surface
            *pCurrentSurface = pkeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

            //While application is running
            while(!quit)
            {
                //Handle events on queue
                while(SDL_PollEvent(&e) != 0)
                {
                    //User requests quit
                    if(e.type == SDL_QUIT) {
                        quit = true;
                    }
                    //User Presses a Key
                    else if (e.type == SDL_KEYDOWN)
                    {
                        //Select surfaces based on key press
                        switch(e.key.keysym.sym)
                        {
                            case SDLK_UP:
                            *pCurrentSurface = pkeyPressSurfaces[KEY_PRESS_SURFACE_UP];
                            break;

                            case SDLK_DOWN:
                            *pCurrentSurface = pkeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
                            break;

                            case SDLK_LEFT:
                            *pCurrentSurface = pkeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
                            break;

                            case SDLK_RIGHT:
                            *pCurrentSurface = pkeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
                            break;

                            default:
                            *pCurrentSurface = pkeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
                            break;
                        }
                    }
                }

                //Apply the current Image
                SDL_BlitSurface(*pCurrentSurface, NULL, *pScreenSurface, NULL);

                //Update the Surface
                SDL_UpdateWindowSurface(*pWindow);
            }
        }
    }


    //Frees resources and close SDL
    terminate();
}
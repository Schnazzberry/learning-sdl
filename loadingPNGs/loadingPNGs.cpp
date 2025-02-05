//Using SDL, SDL_image, standard IO, and strings
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "../common/includes/basic_sdl_functions.h"


//The window we'll be rendering to
SDL_Window** pWindow = new SDL_Window*;

//The surface contained by the window
SDL_Surface** pScreenSurface = new SDL_Surface*;

//The current displayed image
SDL_Surface** pIMGSurface = new SDL_Surface*;

void terminate() {
	close(pWindow);
	delete pWindow;
	delete pScreenSurface;
    pWindow = NULL;
    pScreenSurface = NULL;

    close(pIMGSurface);
    delete pIMGSurface;
    pIMGSurface = NULL;
    
    SDL_Quit();
}


int main(int argc, char* args[])
{
    std::string imgPath = "media/loaded.png";

    if(!init(pWindow, pScreenSurface)) {
        printf("Failed to initilize. Terminating Program.");
    }
    else if (!loadMedia(pIMGSurface, imgPath, pScreenSurface)) {
        printf("Failed to load media. Terminating Program.");
    }
    else {
        //Set image to screen
        if( SDL_BlitSurface(*pIMGSurface, NULL, *pScreenSurface, NULL) == -1) {
            printf("Error Blitting Surface!/n");
        }

        //Hack to get window to stay up
        SDL_Event e;
		bool quit = false;
		while(!quit)
        { 
			while(SDL_PollEvent(&e) != 0)
            {
				if(e.type == SDL_QUIT) 
					quit = true; 
			} 
		}
    }

    return 0;
}
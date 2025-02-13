#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "../common/includes/basic_sdl_functions.h"

//Key Image Surface Constants
enum ImageSurfaces
{
    IMAGE_SURFACE_DEFAULT,
    IMAGE_SURFACE_COUNT
};

//The window we'll be rendering to
SDL_Window** gWindow = new SDL_Window*;

//The surface contained by the window
SDL_Surface** gScreenSurface = new SDL_Surface*;

//The image we will load and show on the screen
SDL_Surface** imgSurface = new SDL_Surface*;

//Window Dimensions
int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;

void terminate() {
	close(gWindow);
	delete gWindow;
	delete gScreenSurface;

	close(imgSurface);
	delete[] imgSurface;

	SDL_Quit();
}

int main(int argc, char* args[])
{
	//path to image associated with imgSurfaces
    std::string filename = "media/helloworld.bmp";
	
	//Start up SDL and create window
	if (!initOLD(gWindow, gScreenSurface, SCREEN_WIDTH, SCREEN_HEIGHT))
    {
		printf("Failed to initialize!\n");
	}
	else
    { 
		// Load media
		if (!loadMedia(imgSurface, filename, gScreenSurface))
        {
			printf("Failed to load media!\n");
		}
		else
        {
			//Apply the image
			//printf("image.w = %d image.h = %d\nscreen.w = %d screen.h = %d\n", SDL_GetWindowSurface(gWindow)->w,1,1,1);

			if (SDL_BlitSurface(*imgSurface, NULL, *gScreenSurface, NULL) == -1) {
				printf("ERROR!\n");
			}

			//Update the surface
			SDL_UpdateWindowSurface(*gWindow);

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
	}
	

	//Free resources and close SDL
	terminate();

	return 0;
}

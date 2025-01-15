#include <SDL2/SDL.h>
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
SDL_Surface** imgSurfaces = new SDL_Surface*[IMAGE_SURFACE_COUNT];

//Window Dimensions
int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;

void terminate() {
	close(gWindow);
	delete gWindow;
	delete gScreenSurface;

	closeAllSurfaces(imgSurfaces, IMAGE_SURFACE_COUNT);
	delete[] imgSurfaces;

	SDL_Quit();
}

int main(int argc, char* args[])
{
	//path to image associated with imgSurfaces
    std::string filenames[IMAGE_SURFACE_COUNT] = {"media/helloworld.bmp"};
	
	//Start up SDL and create window
	if (!init(gWindow, gScreenSurface, SCREEN_WIDTH, SCREEN_HEIGHT))
    {
		printf("Failed to initialize!\n");
	}
	else
    { 
		// Load media
		if (!loadMedia(imgSurfaces, filenames, IMAGE_SURFACE_COUNT))
        {
			printf("Failed to load media!\n");
		}
		else
        {
			//Apply the image
			//printf("image.w = %d image.h = %d\nscreen.w = %d screen.h = %d\n", SDL_GetWindowSurface(gWindow)->w,1,1,1);

			if (SDL_BlitSurface(imgSurfaces[IMAGE_SURFACE_DEFAULT], NULL, *gScreenSurface, NULL) == -1) {
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

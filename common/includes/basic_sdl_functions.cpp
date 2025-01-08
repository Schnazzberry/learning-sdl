#include <SDL2/SDL.h>
#include <stdio.h>

//Starts up SDL and creates window
bool init(SDL_Window** windowS, SDL_Surface** screenSurfaceS, const int SCREEN_WIDTH=640, const int SCREEN_HEIGHT=480) {
    SDL_Window* window;
    SDL_Surface* screenSurface;
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else {
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		
		if(window == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else {
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);
		}
	}

    *windowS = window;
    *screenSurfaceS = screenSurface;

	return success;
}


//Loads media
bool loadMedia(SDL_Surface** imgSurfaceS, char filename[]) {
    SDL_Surface* imgSurface;
	//Loading success flag
	bool success = true;

	//Load splash image
	imgSurface = SDL_LoadBMP(filename);
	if (imgSurface == NULL) {
		printf("Unable to load image %s! SDL_Error: %s\n", filename, SDL_GetError());
	       success = false;
	}

    *imgSurfaceS = imgSurface;

	return success;	
}


//Frees Surface and sets to NULL
void close(SDL_Surface** surface) {
	//Deallocate surface
	SDL_FreeSurface(*surface);
	*surface = NULL;
    surface = NULL;
}

//Frees window and sets to NULL
void close(SDL_Window** window) {
	//Deallocate window
	SDL_DestroyWindow(*window);
	*window = NULL;
    window = NULL;
}

#include <SDL2/SDL.h>
#include <stdio.h>
#include <vector>

//Starts up SDL and creates window
bool init(SDL_Window** pWindow, SDL_Surface** pScreenSurface, const int SCREEN_WIDTH=640, const int SCREEN_HEIGHT=480) {
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

    *pWindow = window;
    *pScreenSurface = screenSurface;

	return success;
}


//Loads media
bool loadMedia(SDL_Surface** pMediaSurface, char filename[]) {
    SDL_Surface* mediaSurface;
	//Loading success flag
	bool success = true;

	//Load splash image
	mediaSurface = SDL_LoadBMP(filename);
	if (mediaSurface == NULL) {
		printf("Unable to load image %s! SDL_Error: %s\n", filename, SDL_GetError());
	       success = false;
	}

    *pMediaSurface = mediaSurface;

	return success;	
}


//Frees Surface and sets to NULL
void close(SDL_Surface** pSurface) {
	//Deallocate surface
	SDL_FreeSurface(*pSurface);
	*pSurface = NULL;
    pSurface = NULL;
}

//Frees window and sets to NULL
void close(SDL_Window** pWindow) {
	//Deallocate window
	SDL_DestroyWindow(*pWindow);
	*pWindow = NULL;
    pWindow = NULL;
}


// Frees all the surfaces and windows in a list and deletes (pointer to pointer)
void closeAll(std::vector<SDL_Surface**> pSurfaces = {}, std::vector<SDL_Window**> pWindows = {}) {
    for (int i = pWindows.size()-1; i >= 0; i--) {
		if(pWindows.at(i) != NULL) {
			close(pWindows.at(i));
			delete pWindows.at(i);
		}
	}
	pWindows.clear();
	
	for (int i = pSurfaces.size()-1; i >= 0; i--) {
		if (pSurfaces.at(i) != NULL) {
			close(pSurfaces.at(i));
			delete pSurfaces.at(i);
		}
    }
    pSurfaces.clear();

}



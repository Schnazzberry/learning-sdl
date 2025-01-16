#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>


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

//Loads media into a surface
SDL_Surface* loadSurface(const std::string path, const SDL_PixelFormat* screenPixelFormat) {
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

    SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
    if(loadedSurface == NULL) {
        printf("Unable to load image %s! SDL_Error: %s\n", path.c_str(), SDL_GetError());
    }
	else
	{
		//convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, screenPixelFormat, 0);
		if(optimizedSurface == NULL) {
			printf("Unable to optimize image %s! SDL_Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

    return optimizedSurface;
}

//Loads list of media into list of surfaces
bool loadMedia(SDL_Surface* pMediaSurfaces[], const std::string paths[], const int numSurfaces, const SDL_PixelFormat* screenPixelFormat) {
    //Loading success flag
	bool success = true;

	//Load splash image
    for(int i = 0; i < numSurfaces; i++) {
        pMediaSurfaces[i]=loadSurface(paths[i], screenPixelFormat);
       if (pMediaSurfaces[i] == NULL) {
           printf("Failed to load image %s! SDL_Error: %s\n", paths[i].c_str(), SDL_GetError()); 
           success = false;
       }
    }

	return success;	
}


//Frees window and sets to NULL
void close(SDL_Window** pWindow) {
	//Deallocate window
	SDL_DestroyWindow(*pWindow);
	*pWindow = NULL;
}

//Frees all the windows in a list (does not call delete[])
void closeAllWindows(SDL_Window* pWindows[], int numWindows) {
	for (int i = numWindows-1; i >= 0; i--) {
		if(pWindows[i] != NULL) {
			SDL_DestroyWindow(pWindows[i]);
			pWindows[i] = NULL;
		}
	}
} // Might have memory leak with assigned surface. Haven't tested.


//Frees Surface and sets to NULL
void close(SDL_Surface** pSurface) {
	//Deallocate surface
	SDL_FreeSurface(*pSurface);
    *pSurface = NULL;
}

//Frees all the surfaces in a list (does not call delete[])
void closeAllSurfaces(SDL_Surface* pSurfaces[], int numSurfaces) {
	for (int i = numSurfaces-1; i >= 0; i--) {
		if (pSurfaces[i] != NULL) {
			SDL_FreeSurface(pSurfaces[i]);
			pSurfaces[i] = NULL;
		}
    }
}


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>


//Starts up SDL and creates window SDL_INIT_VIDEO & IMG_INIT & SDL_WINDOW_OPENGL
bool init(SDL_Window** pWindow, SDL_Surface** pScreenSurface, SDL_GLContext* pOpenGlContext, const int SCREEN_WIDTH=640, const int SCREEN_HEIGHT=480) {
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
		//Set GL Attributes
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
		
		//Create window with SDL_WINDOW_OPENGL
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
		
		if(window == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else {
			//Initialize OpenGLContext
			*pOpenGlContext = SDL_GL_CreateContext(window);
			if (pOpenGlContext = NULL) {
				printf("SDL_GLContext could not initialize! SDL_Error: %s\n", SDL_GetError());
				success = false;
			}
			//Initialize PNG Loading
			int imgFlags = IMG_INIT_PNG;
			if ( !(IMG_Init(imgFlags) & imgFlags) ) {
				printf("SDL_image could not initialize! SDL_image Error: %s/n", SDL_GetError());
				success = false;
			}
			else {
				//Get window surface
				screenSurface = SDL_GetWindowSurface(window);
			}
		}
	}

    *pWindow = window;
    *pScreenSurface = screenSurface;

	return success;
}

//Loads media into a surface using IMG_Load()
SDL_Surface* loadSurface(const std::string path, const SDL_PixelFormat* screenPixelFormat) {
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
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
bool loadAllMedia(SDL_Surface* pMediaSurfaces[], const std::string paths[], const int numSurfaces, SDL_Surface** pScreenSurface) {
    //Loading success flag
	bool success = true;

	//Load splash image
    for(int i = 0; i < numSurfaces; i++) {
        pMediaSurfaces[i]=loadSurface(paths[i], (*pScreenSurface)->format);
       if (pMediaSurfaces[i] == NULL) {
           printf("Failed to load image %s! SDL_Error: %s\n", paths[i].c_str(), SDL_GetError()); 
           success = false;
       }
    }

	return success;	
}

bool loadMedia(SDL_Surface** pMediaSurface, const std::string path, SDL_Surface** pScreenSurface) {
	// Loading Success flag
	bool success = true;

	//Load splash image
	*pMediaSurface = loadSurface(path, (*pScreenSurface)->format);
	if (*pMediaSurface == NULL) {
		printf("Failed to load image %s! SDL_Error: %s\n", path.c_str(), SDL_GetError());
		success = false;
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






//Starts up SDL and creates window SDL_INIT_VIDEO & IMG_INIT
bool initOLD(SDL_Window** pWindow, SDL_Surface** pScreenSurface, const int SCREEN_WIDTH=640, const int SCREEN_HEIGHT=480) {
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
			//Initialize PNG Loading
			int imgFlags = IMG_INIT_PNG;
			if ( !(IMG_Init(imgFlags) & imgFlags) ) {
				printf("SDL_image could not initialize! SDL_image Error: %s/n", SDL_GetError());
				success = false;
			}
			else {
				//Get window surface
				screenSurface = SDL_GetWindowSurface(window);
			}
		}
	}

    *pWindow = window;
    *pScreenSurface = screenSurface;

	return success;
}
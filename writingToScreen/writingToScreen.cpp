#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>


//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

//Window Dimensions
int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;


//Starts up SDL and creates window
bool init() {
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else {
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		
		if(gWindow == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else {
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

//Loads media
bool loadMedia(char filename[]) {
	//Loading success flag
	bool success = true;

	//Load splash image
	gHelloWorld = SDL_LoadBMP(filename);
	if (gHelloWorld == NULL) {
		printf("Unable to load image %s! SDL_Error: %s\n", filename, SDL_GetError());
	       success = false;
	}

	return success;	
}

//Frees media and shuts down SDL
void close() {
	//Deallocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main(int argc, char* args[])
{
	char filename[] = "./media/helloworld.bmp";	
	//Start up SDL and create window
	if (!init()) {
		printf("Failed to initialize!\n");
	}
	else { 
		// Load media
		if (!loadMedia(filename)) {
			printf("Failed to load media!\n");
		}
		else {
			//Apply the image
			SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

			//Update the surface
			SDL_UpdateWindowSurface(gWindow);

			//Hack to get window to stay up
           		SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ 				if( e.type == SDL_QUIT ) quit = true; } }
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}

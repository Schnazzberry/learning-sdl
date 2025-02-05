#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <vector>
#include <string>

#ifndef BASIC_SDL_FUNCTIONS_H
#define BASIC_SDL_FUNCTIONS_H

//Starts up SDL and creates window and gets window surface
bool init(SDL_Window** pWindow, SDL_Surface** pScreenSurface, const int SCREEN_WIDTH=640, const int SCREEN_HEIGHT=480);


//Loads media into list of surfaces
bool loadAllMedia(SDL_Surface* pMediaSurfaces[], const std::string paths[], const int numSurfaces, SDL_Surface** pScreenSurface);

//Loads media into one surface
bool loadMedia(SDL_Surface** pMediaSurface, const std::string path, SDL_Surface** pScreenSurface);

//loads media into a surface
SDL_Surface* loadSurface(std::string path, const SDL_PixelFormat* screenPixelFormat);


//Frees Surface and sets to NULL
void close(SDL_Surface** pSurface);

//Frees window and sets to NULL
void close(SDL_Window** pWindow);

//Frees all the windows in a list (calls delete[])
void closeAllWindows(SDL_Window* pWindows[], int numWindows);

//Frees all the surfaces in a list (calls delete[])
void closeAllSurfaces(SDL_Surface* pSurfaces[], int numSurfaces);

#endif

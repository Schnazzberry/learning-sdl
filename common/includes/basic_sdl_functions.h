#include <SDL2/SDL.h>
#include <stdio.h>
#include <vector>

#ifndef BASIC_SDL_FUNCTIONS_H
#define BASIC_SDL_FUNCTIONS_H

//Starts up SDL and creates window and gets window surface
bool init(SDL_Window** pWindow, SDL_Surface** pScreenSurface, const int SCREEN_WIDTH=640, const int SCREEN_HEIGHT=480);


//Loads media
bool loadMedia(SDL_Surface** pMediaSurface, char filename[]);


//Frees Surface and sets to NULL
void close(SDL_Surface** pSurface);

//Frees window and sets to NULL
void close(SDL_Window** pWindow);

// Frees all the surfaces and windows in a list and deletes pointer to pointer
void closeAll(std::vector<SDL_Surface**> pSurfaces = {}, std::vector<SDL_Window**> pWindows = {});

#endif
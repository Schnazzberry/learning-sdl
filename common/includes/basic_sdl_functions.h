#include <SDL2/SDL.h>
#include <stdio.h>

#ifndef BASIC_SDL_FUNCTIONS_H
#define BASIC_SDL_FUNCTIONS_H

//Starts up SDL and creates window
bool init(SDL_Window**, SDL_Surface**, const int, const int);


//Loads media
bool loadMedia(SDL_Surface**, char[]);


//Frees Surface and sets to NULL
void close(SDL_Surface**);

//Frees window and sets to NULL
void close(SDL_Window**);

#endif
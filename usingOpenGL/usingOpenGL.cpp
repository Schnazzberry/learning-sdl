#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include "../common/includes/basic_sdl_functions.h"
#include "../common/includes/glad.h"

// Globals
int gScreenHeight = 640;
int gScreenWidth  = 480;

SDL_Window**  pWindow = new SDL_Window*;
SDL_Surface** pScreenSurface = new SDL_Surface*;
SDL_Surface** pDisplayedSurface = new SDL_Surface*;

SDL_GLContext* pOpenGLContext = new SDL_GLContext;


void GetOpenGLInfo() {
    printf("Vendor: %s\nRenderer; %s\nVersion: %s\nShading Language Version: %s\n", 
        glGetString(GL_VENDOR), glGetString(GL_RENDERER), glGetString(GL_VERSION), glGetString(GL_SHADING_LANGUAGE_VERSION));
    
    return;
}

void GetInput(SDL_Event event, bool *quit) {
    while(SDL_PollEvent(&event) != 0) {
        if(event.type == SDL_QUIT) {
            printf("Goodbye!\n");
            *quit = true;
        }
    }
    return;
}

void PreDraw() {

    return;
}

void Draw() {

    return;
}


void MainLoop() {
    SDL_Event event;
    bool quit = false;

    GetOpenGLInfo();

    while (!quit)
    {    
        GetInput(event, &quit);

        PreDraw();

        Draw();

        //Update the screen
        SDL_GL_SwapWindow(*pWindow);
    }
}
void terminate() {
    close(pWindow);
	delete pWindow;
	delete pScreenSurface;
    pWindow = NULL;
    pScreenSurface = NULL;

    close(pDisplayedSurface);
    delete pDisplayedSurface;
    pDisplayedSurface= NULL;
    
    SDL_Quit();
    return;
}

int main()
{
    if (!init(pWindow, pScreenSurface, pOpenGLContext)) { printf("Could not initialize SDL. Terminating Program"); exit(1);}
    //else if (!loadAllMedia()) { printf("Could not load media. Terminating Program");}

    MainLoop();

    terminate();
    
    return 0;
}
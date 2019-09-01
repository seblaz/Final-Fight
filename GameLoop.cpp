//
// Created by sebas on 31/8/19.
//
#include <SDL2/SDL.h>
#include <unistd.h>
#include <chrono>

using namespace std;

const int MS_PER_FRAME = 16666; // Microseconds. TODO: leer los FPS del archivo de configuracion.

void processInput(bool &exit) {
    SDL_Event e;
    if (SDL_PollEvent(&e) && (e.type == SDL_QUIT)) {
        exit = true;
    }
}

SDL_Window* start(){
    
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    
	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		//Create window
		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface( window );

			//Fill the surface white
			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

			//Update the surface
			SDL_UpdateWindowSurface( window );

		}
	}

	return window;
}

int main(int argc, char *args[]) {
    bool exit = false;
    SDL_Window* window = start();

    while (!exit) {
        auto start = chrono::system_clock::now();
        processInput(exit);
//        update();
//        render();
        auto end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;
        usleep(MS_PER_FRAME - elapsed_seconds.count() * 1000 * 1000); // Microseconds.
    }

    // Destroy window
	SDL_DestroyWindow( window );

    // Quit SDL subsystems
	SDL_Quit();
}

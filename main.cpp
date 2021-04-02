#include <SDL2/SDL.h>
#include "Pixelmap.hpp"
#include "Ant.hpp"

#define WIN_WIDTH (int)640
#define WIN_HEIGHT (int)480


int main(int argc, char ** argv)
{
	// Setup environment variables
    bool quit = false;
    SDL_Event event;




	// Startup video
    SDL_Init(SDL_INIT_VIDEO);

	// Window creation
    SDL_Window * window = SDL_CreateWindow("sdl2 pixel drawing",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT, 0);


	// Renderer which operates window view
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	// Our texture to be overwitten by frame buffer
	SDL_Texture * texture = SDL_CreateTexture(renderer,
	SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, WIN_WIDTH, WIN_HEIGHT);


	// Begin Graphical setup

	// Color def
	SDL_Color SDLcolorBlack = { 0, 0, 0, 255 };
	SDL_Color SDLcolorWhite = { 255, 255, 255, 255};
	SDL_Color SDLcolorRed = { 255, 0, 0, 255 };
	SDL_Color SDLcolorGreen = { 0, 255, 0, 255 };
	SDL_Color SDLcolorBlue = { 0, 0, 255, 255 };

	Uint32 colorBlack = 0x000000FF;
	Uint32 colorWhite = 0xFFFFFFFF;
	Uint32 colorRed = 0xFF0000FF;

	// Create Pixel buffer for drawing to window and set bg to white
	Pixelmap *pixelmap = new Pixelmap(WIN_WIDTH,WIN_HEIGHT,sizeof(Uint32),&colorWhite);

    while (!quit)
    {
		// Event logic
		
		
		
		// Copy pixels[uint32] to texture
		SDL_UpdateTexture(texture, NULL, pixelmap->pixeldata, WIN_WIDTH * sizeof(u_int32_t));
		// Clear window through renderer
		SDL_RenderClear(renderer);
		// Copy texture to window (whole screen)
        SDL_RenderCopy(renderer, texture, NULL, NULL);
		// Update window
        SDL_RenderPresent(renderer);

		// Event handling
        SDL_PollEvent(&event);
        switch (event.type)
        {
			// If quit signal then quit
            case SDL_QUIT:
                quit = true;
                break;
        }
    }
	delete pixelmap;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
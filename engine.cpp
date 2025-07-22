#include "engine.h"

#include <SDL3_ttf/SDL_ttf.h>
#include <iostream>

#define WINDOW_TITLE ","

#define FONT_PATH "font.otf"

engine::engine()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
        std::cerr << "SDL failed to initialize! SDL_ERROR: " << SDL_GetError() << "\n";
    }
    w = SDL_CreateWindow(WINDOW_TITLE, 640, 480, SDL_WINDOW_RESIZABLE);
    r = SDL_CreateRenderer(w, nullptr);

    if (TTF_Init() < 0) {
        std::cerr << "ttf init error" << std::endl;
    }

    font = TTF_OpenFont(FONT_PATH, 24); // assign to member
    if (!font) {
        std::cerr << "failed to load font" << std::endl;
    }

    this->Menu.menuInit(r, font);
    this->Menu.settingsInit();
}

int engine::s() {
	while (q == 0) {
		draw(scene);
		input();
		update();
	}

	SDL_DestroyRenderer(r);
	SDL_DestroyWindow(w);

	return 0;
}
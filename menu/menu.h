#pragma once

#define MENU_H

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <vector>
#include <string>

class menu {
private:
    SDL_Renderer* r;
    SDL_Surface* Surfaces[3];
    SDL_Texture* Textures[3];

    int underlinedIndex = -1;
public:
    menu();
    SDL_FRect Rects[3];
    void render(TTF_Font* font);
    void destroy();
    void init(SDL_Renderer* renderer, TTF_Font* font);
    void underlineMenuItem(int index);
};
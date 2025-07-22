#include "menu.h"
#include <string>

menu::menu() {}

void menu::menuInit(SDL_Renderer *renderer, TTF_Font* font) {
    this->r = renderer;
    this->font = font;
    SDL_Color TEXT_COLOR = {255, 255, 255, 255};

    MainMenuSurfaces[0] = TTF_RenderText_Solid(font, "start", 5, TEXT_COLOR);
    MainMenuSurfaces[1] = TTF_RenderText_Solid(font, "settings", 8, TEXT_COLOR);
    MainMenuSurfaces[2] = TTF_RenderText_Solid(font, "quit", 4, TEXT_COLOR);


    for (int i = 0; i < 3; ++i) {
        MainMenuTextures[i] = SDL_CreateTextureFromSurface(renderer, MainMenuSurfaces[i]);
    }

    MainMenuRects[0].x = 100.0f;
    MainMenuRects[0].y = 100.0f;
    MainMenuRects[0].w = static_cast<float>(MainMenuSurfaces[0]->w);
    MainMenuRects[0].h = static_cast<float>(MainMenuSurfaces[0]->h);

    MainMenuRects[1].x = 100.0f;
    MainMenuRects[1].y = 200.0f;
    MainMenuRects[1].w = static_cast<float>(MainMenuSurfaces[1]->w);
    MainMenuRects[1].h = static_cast<float>(MainMenuSurfaces[1]->h);

    MainMenuRects[2].x = 100.0f;
    MainMenuRects[2].y = 300.0f;
    MainMenuRects[2].w = static_cast<float>(MainMenuSurfaces[2]->w);
    MainMenuRects[2].h = static_cast<float>(MainMenuSurfaces[2]->h);

    for (int i = 0; i < 3; ++i) {
        SDL_DestroySurface(MainMenuSurfaces[i]);
    }
}

void menu::destroy() {
    for (int i = 0; i < 3; ++i) {
        SDL_DestroyTexture(MainMenuTextures[i]);        
    }
}

void menu::underlineMenuItem(int i) {
    underlinedIndex = i; // 0 start, 1 settings, 2 exit !
}

void menu::renderMenu() {
    for (int i = 0; i < 3; ++i) {
        if (i == underlinedIndex && underlinedIndex != -1) {
            SDL_FRect underline = {
                MainMenuRects[i].x,
                MainMenuRects[i].y + MainMenuRects[i].h + 2.0f,
                MainMenuRects[i].w,
                2.0f
            };
            SDL_SetRenderDrawColor(r, 255, 0, 0, 255); // Red underline
            SDL_RenderFillRect(r, &underline);
        }
        SDL_SetRenderDrawColor(r, 0, 0, 0, 255);
        SDL_RenderFillRect(r, &MainMenuRects[i]);
        SDL_RenderTexture(r, MainMenuTextures[i], nullptr, &MainMenuRects[i]);    
    }
}
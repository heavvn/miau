#include "menu.h"
#include <string>

menu::menu() {}

void menu::init(SDL_Renderer *renderer, TTF_Font* font) {
    this->r = renderer;
    SDL_Color TEXT_COLOR = {255, 255, 255, 255};

    Surfaces[0] = TTF_RenderText_Solid(font, "start", 5, TEXT_COLOR);
    Surfaces[1] = TTF_RenderText_Solid(font, "settings", 8, TEXT_COLOR);
    Surfaces[2] = TTF_RenderText_Solid(font, "quit", 4, TEXT_COLOR);

    Textures[0] = SDL_CreateTextureFromSurface(renderer, Surfaces[0]);
    Textures[1] = SDL_CreateTextureFromSurface(renderer, Surfaces[1]);
    Textures[2] = SDL_CreateTextureFromSurface(renderer, Surfaces[2]);

    Rects[0].x = 100.0f;
    Rects[0].y = 100.0f;
    Rects[0].w = static_cast<float>(Surfaces[0]->w);
    Rects[0].h = static_cast<float>(Surfaces[0]->h);

    Rects[1].x = 100.0f;
    Rects[1].y = 200.0f;
    Rects[1].w = static_cast<float>(Surfaces[1]->w);
    Rects[1].h = static_cast<float>(Surfaces[1]->h);

    Rects[2].x = 100.0f;
    Rects[2].y = 300.0f;
    Rects[2].w = static_cast<float>(Surfaces[2]->w);
    Rects[2].h = static_cast<float>(Surfaces[2]->h);

    // Free surfaces after creating textures
    for (int i = 0; i < 3; ++i) {
        SDL_DestroySurface(Surfaces[i]);
    }
}

void menu::underlineMenuItem(int i) {
    underlinedIndex = i;
}

void menu::render(TTF_Font* font) {
    for (int i = 0; i < 3; ++i) {
        // Draw menu item (e.g., text)
                // Underline if this item is active
        if (i == underlinedIndex && underlinedIndex != -1) {
            SDL_FRect underline = {
                Rects[i].x,
                Rects[i].y + Rects[i].h + 2.0f,
                Rects[i].w,
                2.0f
            };
            SDL_SetRenderDrawColor(r, 255, 0, 0, 255); // Red underline
            SDL_RenderFillRect(r, &underline);
        }
        SDL_SetRenderDrawColor(r, 0, 0, 0, 255);
        SDL_RenderFillRect(r, &Rects[i]);
        SDL_RenderTexture(r, Textures[i], nullptr, &Rects[i]);    
    }
}
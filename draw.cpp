#include "engine.h"
void engine::draw(Scene scene) {
    SDL_SetRenderTarget(r, NULL);
    SDL_SetRenderDrawColor(r, 0, 0, 0, 255);

    SDL_RenderClear(r); // Clear the screen (window)

    switch (scene) {
        case MENU:
            this->Menu.render(font);
            break;
    }

    SDL_RenderPresent(r);
}

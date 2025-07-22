#include "engine.h"
void engine::draw(Scene scene) {
    SDL_SetRenderTarget(r, NULL);
    SDL_SetRenderDrawColor(r, 0, 0, 0, 255);

    SDL_RenderClear(r);

    switch (scene) {
        case MENU:
            this->Menu.renderMenu();
            break;
        case SETTINGS:
            this->Menu.renderSettingsBase();
            break;
    }

    SDL_RenderPresent(r);
}

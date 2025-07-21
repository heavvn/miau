#include "engine.h"
#include <iostream>
void engine::input() {
    while (SDL_PollEvent(&e)) {
        float mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        SDL_FRect mouseRect = {mouseX, mouseY, 1.0f, 1.0f};
        switch (this->scene) {
            case MENU:
                bool hoveringAny = false;

                for (int i = 0; i < 3; ++i) {
                    if (hasIntersectionFloat(&this->Menu.Rects[i], &mouseRect)) {
                        std::cout << "hovered over menu item " << i << std::endl;
                        this->Menu.underlineMenuItem(i);
                        hoveringAny = true;
                        break; // No need to keep looping once we found one
                    }
                }

                if (!hoveringAny) {
                    this->Menu.underlineMenuItem(-1);
                }
        }


        switch (e.type) {
            case SDL_EVENT_QUIT:
                q = 1;
                break;
            
            case SDL_EVENT_MOUSE_BUTTON_DOWN:
                if (hasIntersectionFloat(&this->Menu.Rects[1], &mouseRect)) {
                    this->scene = SETTINGS;
                }

            case SDL_EVENT_KEY_DOWN:
                SDL_Keycode keyPressed = e.key.key;

                switch (keyPressed) {
                    case SDLK_ESCAPE:
                        this->scene = MENU;
                }
        }
    }
}; 
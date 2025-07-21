#include "engine.h"
#include <iostream>
void engine::input() {
    while (SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_EVENT_QUIT:
                q = 1;
                break;
            
            case SDL_EVENT_MOUSE_BUTTON_DOWN:
                std::cout << "click!" << std::endl;;
        }
        
        switch (this->scene) {
            case MENU:
                float mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);

                bool hoveringAny = false;

                for (int i = 0; i < 3; ++i) {
                    SDL_FRect mouseRect = {mouseX, mouseY, 1.0f, 1.0f};
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
    }
};
#include "engine.h"
#include <iostream>
bool engine::checkMouseOverMenuItem(int i) {
    float mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    SDL_FRect mouseRect = {mouseX, mouseY, 1.0f, 1.0f};



    switch (this->scene) {
        case MENU: {
            if (hasIntersectionFloat(&this->Menu.MainMenuRects[i], &mouseRect)) {
                return true;
            }
        }
        

        case SETTINGS: {
            if (hasIntersectionFloat(&this->Menu.SettingsRects[i], &mouseRect)) {
                return true;
            }
        }
    }
}

void engine::input() {
    while (SDL_PollEvent(&e)) {
        float mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        SDL_FRect mouseRect = {mouseX, mouseY, 1.0f, 1.0f};
        switch (this->scene) {
            case MENU: {
                bool hoveringAny = false;

                for (int i = 0; i < 3; ++i) {
                    if (checkMouseOverMenuItem(i)) {
                        std::cout << "hovered over menu item " << i << std::endl;
                        this->Menu.underlineMenuItem(i);
                        hoveringAny = true;
                        break; // No need to keep looping once we found one
                    }
                }

                if (!hoveringAny) {
                    this->Menu.underlineMenuItem(-1);
                } break;
            }
            case SETTINGS: {
                bool hoveringAny = false;

                for (int i = 0; i < 5; ++i) {
                    if (checkMouseOverMenuItem(i)) {
                        std::cout << "hovered over settings item " << i << std::endl;
                        this->Menu.underlineMenuItem(i);
                        hoveringAny = true;
                        break; // No need to keep looping once we found one
                    }
                }

                if (!hoveringAny) {
                    this->Menu.underlineMenuItem(-1);
                } break;
            }
        }


        switch (e.type) {
            case SDL_EVENT_QUIT:
                q = 1;
                break;
            // make it one check, that reports what was clicked on
            // rather than checking every item, every click.
            // - jas  7/21/25
            case SDL_EVENT_MOUSE_BUTTON_DOWN:
                switch (this->scene) {
                    case MENU: {
                        std::cout << " i " << std::endl;
                        if (checkMouseOverMenuItem(1)) {
                            std::cout << "lll" << std::endl;
                            this->scene = SETTINGS;
                        }


                    }

                    case SETTINGS: {
                        if (checkMouseOverMenuItem(4)) {
                            this->scene = MENU;
                        }
                    }
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
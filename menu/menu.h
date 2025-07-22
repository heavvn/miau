#pragma once

#define MENU_H

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <vector>
#include <string>

class menu {
private:
    SDL_Renderer* r;
    TTF_Font* font;
    SDL_Surface* MainMenuSurfaces[3];
    SDL_Texture* MainMenuTextures[3];

    SDL_Surface* SettingsSurfaces[5]; // language, resolution, keybinds, audio, back
    SDL_Texture* SettingsTextures[5];

    int underlinedIndex = -1;
public:
    menu();
    SDL_FRect MainMenuRects[3];
    SDL_FRect SettingsRects[5];
    void renderMenu();
    void destroy();
    void renderSettingsBase();
    void settingsInit();
    void menuInit(SDL_Renderer* renderer, TTF_Font* font);
    void underlineMenuItem(int index);
};
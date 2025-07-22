#include "menu.h"

void menu::settingsInit() {
    SDL_Color TEXT_COLOR = {255, 255, 255, 255};

    SettingsSurfaces[0] = TTF_RenderText_Solid(font, "language", 8, TEXT_COLOR);
    SettingsSurfaces[1] = TTF_RenderText_Solid(font, "resolution", 10, TEXT_COLOR);
    SettingsSurfaces[2] = TTF_RenderText_Solid(font, "controls", 8, TEXT_COLOR);
    SettingsSurfaces[3] = TTF_RenderText_Solid(font, "audio", 5, TEXT_COLOR);
    SettingsSurfaces[4] = TTF_RenderText_Solid(font, "back", 4, TEXT_COLOR);

    for (int i = 0; i < 5; ++i) {
        SettingsTextures[i] = SDL_CreateTextureFromSurface(r, SettingsSurfaces[i]);
    }

    for (int i = 0; i < 5; ++i) {
        SettingsRects[i].x = 100.0f;
        SettingsRects[i].y = 100.0f + (i * 50.0f); // Spacing of 50 pixels between items
        SettingsRects[i].w = static_cast<float>(SettingsSurfaces[i]->w);
        SettingsRects[i].h = static_cast<float>(SettingsSurfaces[i]->h);
    }

    for (int i = 0; i < 5; ++i) {
        SDL_DestroySurface(SettingsSurfaces[i]);
    }
}

void menu::renderSettingsBase() {
    SDL_SetRenderDrawColor(r, 0, 0, 0, 255); // Set background color
    SDL_RenderClear(r); // Clear the renderer

    for (int i = 0; i < 5; ++i) {
        if (i == underlinedIndex && underlinedIndex != -1) {
            SDL_FRect underline = {
                SettingsRects[i].x,
                SettingsRects[i].y + SettingsRects[i].h + 2.0f,
                SettingsRects[i].w,
                2.0f
            };
            SDL_SetRenderDrawColor(r, 255, 0, 0, 255); // Red underline
            SDL_RenderFillRect(r, &underline);
        }
        SDL_SetRenderDrawColor(r, 0, 0, 0, 255);
        SDL_RenderFillRect(r, &SettingsRects[i]);
        SDL_RenderTexture(r, SettingsTextures[i], nullptr, &SettingsRects[i]);
    }
}
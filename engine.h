#pragma once

#define ENGINE_H
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "menu/menu.h"
class engine
{
	private:
		SDL_Window* w;
		SDL_Renderer* r;
		SDL_Event e;

		enum Scene { MENU , NIL};
		Scene scene = MENU;

		void update(float dtAsSeconds);

		void input();
		void draw(Scene scene);
		void update();

		bool hasIntersectionFloat(const SDL_FRect* a, const SDL_FRect* b);
		
		int q = 0;

		menu Menu;

		TTF_Font* font;
	public:
		engine();
		int s();
};
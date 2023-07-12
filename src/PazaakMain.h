#ifndef PAZAAKMAIN_H
#define PAZAAKMAIN_H

#include <Windows.h>
#include <glew.h>

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"

#include <SDL.h>









#undef main
class PazaakMain
{
public:
	PazaakMain();
	~PazaakMain();
	void run();

	void init();

private:
	SDL_Window* window;
	SDL_GLContext glContext;
	
};


#endif

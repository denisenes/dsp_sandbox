#pragma once

#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"

#include <SDL2/SDL.h>
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <SDL_opengles2.h>
#else
#include <SDL2/SDL_opengl.h>
#endif

namespace SDL{
    
    extern const char* glsl_version;
    extern SDL_Window* window;
    extern SDL_GLContext gl_context;

    int setupSDL();
    void terminateSDL();

} // namespace SDL

#include <some_engine/include/some_engine.hpp>
#include <iostream>
#include <SDL2/SDL.h>

using namespace some_engine;
using namespace extern_1;

MainClass::MainClass()
{
    if (SDL_Init(SDL_INIT_TIMER) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return;
    }
    SDL_Quit();
}

void MainClass::dummy() const
{
    std::cout << "Hello from " << __FUNCTION__ << std::endl;
    m_extern.dummy();
}
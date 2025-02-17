#include "Window.hpp"
#include "../SDL2-2.0.10/include/SDL.h"

#include <iostream>

Window::Window(int width, int height) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Error: SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    m_window = SDL_CreateWindow(
        "SDL2 Text Rendering Example", 500, 200, width, height, SDL_WINDOW_SHOWN
    );
    if (!m_window) {
        std::cerr << "Error: Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return;
    }

    // Create a renderer
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!m_renderer) {
        std::cerr << "Error: Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return;
    }


}
Window::~Window() {
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Window::run() {

    while (m_isRunning) {

        processEvents();

        onUpdate();

        // Clear the screen
        SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
        SDL_RenderClear(m_renderer);

        onRender();

        // Present the renderer
        SDL_RenderPresent(m_renderer);
    }
}

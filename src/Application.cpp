#include "Application.hpp"
#include "SDL2/SDL_ttf.h"
#include <iostream>

Application::Application() {
    // Initialize SDL_ttf
    if (TTF_Init() == -1) {
        std::cerr << "Error: SDL_ttf could not initialize! TTF_Error: " << TTF_GetError() << std::endl;
        SDL_Quit();
        return;
    }
    // Load a font
    m_font = TTF_OpenFont("RobotoMono-Medium.ttf", 24);
    if (!m_font) {
        std::cerr << "Error: Font could not be loaded! TTF_Error: " << TTF_GetError() << std::endl;
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        TTF_Quit();
        SDL_Quit();
        return;
    }
    m_textTexture = nullptr;
    updateCursor();
}
void Application::onRender() {
    // Get the texture dimensions
    if (m_textTexture != nullptr) {
        SDL_Rect  dest ={0,0,0,0};
        SDL_QueryTexture(m_textTexture, NULL, NULL, &dest.w, &dest.h);
        SDL_RenderCopy(m_renderer, m_textTexture, NULL, &dest);
    }
    renderCursor();
}
void Application::updateCursor() {
    int cursorPos = m_buffer.getCursorPos();
    std::string subText = m_buffer.getText().substr(0, cursorPos);
    int textWidth = 0, textHeight = 0;
    TTF_SizeText(m_font, subText.c_str(), &textWidth, &m_cursor.height);

    m_cursor.x = 0 + textWidth;  // Start position + text width
    m_cursor.y = 0;  // Assuming single line for now
}
void Application::renderCursor() {
    SDL_SetRenderDrawColor(m_renderer, 0, 255, 0 , 255);
    SDL_Rect cursorRect = {m_cursor.x, m_cursor.y, m_cursor.width, m_cursor.height}; // 2-pixel wide cursor
    SDL_RenderFillRect(m_renderer, &cursorRect);
}
void Application::onUpdate() {

}
void Application::updateTextTexture() {

    const std::string& text = m_buffer.getText();
    if(text == "") {
        m_textTexture = nullptr;
        return;
    }

    SDL_Color textColor = {255, 255, 255, 255};
    SDL_Surface* textSurface = TTF_RenderText_Solid(m_font, text.c_str(), textColor);
    if (!textSurface) {
        std::cerr << "Error: Text could not be rendered! TTF_Error: " << TTF_GetError() << std::endl;
        TTF_CloseFont(m_font);
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        TTF_Quit();
        SDL_Quit();
        return;
    }

    // Convert the surface to a texture
    m_textTexture = SDL_CreateTextureFromSurface(m_renderer, textSurface);
    SDL_FreeSurface(textSurface); // Surface is no longer needed after creating the texture
}
void Application::processKeyDownEvents(SDL_Event &event) {\
        if (event.type == SDL_TEXTINPUT) {
            char c = event.text.text[0];
            m_buffer.insertChar(c);
            updateTextTexture();
            updateCursor();
        }
}
void Application::handleKeyDownEvents(const SDL_Keycode &key) {
    if (key==SDLK_ESCAPE) {
        m_isRunning = false;
    }
    else if (key == SDLK_LEFT) {
        m_buffer.moveCursorLeft();
        updateCursor();
    }
    else if (key == SDLK_RIGHT) {
        m_buffer.moveCursorRight();
        updateCursor();
    }
    else if (key == SDLK_BACKSPACE) {
        m_buffer.deleteChar();
        updateTextTexture();
        updateCursor();
    }
}
void Application::processEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT ) {
            m_isRunning = false;
        }
        else if (event.type == SDL_TEXTINPUT) {
            processKeyDownEvents(event);
        }
        else if (event.type == SDL_KEYDOWN) {
            handleKeyDownEvents(event.key.keysym.sym);
        }
    }
}
Application::~Application(){
    TTF_CloseFont(m_font);
    TTF_Quit();
}

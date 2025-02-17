#pragma once
#include <GapBuffer.hpp>
#include <SDL_ttf.h>

#include "Window.hpp"

struct Cursor {
    int x,y;
    int width,height;
    bool cursorVisible;
    float lastBlinkTime;
    const float blinkingDelay;
    Cursor():blinkingDelay(500) {
        cursorVisible = false;
        lastBlinkTime = 0;
        x = 0;
        y = 30;
        width = 4;
        height = -20;
    }
};

class Application :public Window{
private:
    Cursor m_cursor;
    GapBuffer m_buffer;
    void processKeyDownEvents(SDL_Event &event);
    void updateTextTexture();
    void handleKeyDownEvents(const SDL_Keycode &key);
    void renderCursor();
    void updateCursor();
public:
    TTF_Font * m_font;
    SDL_Texture* m_textTexture;
    Application();
    ~Application();

  protected:
    void onUpdate() override;
    void onRender() override;
    void processEvents() override;
};
#pragma once
#include <SDL_render.h>

class Window {
  public:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;

    bool m_isRunning = true;

    Window(int width=800, int height=600);
    ~Window();
    void run();

protected:
    virtual void onUpdate()=0;
    virtual void onRender()=0;
    virtual void processEvents()=0;
};

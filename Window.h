//
// Created by Vlad Sydorchuk on 11/11/17.
//

#ifndef WINDOW_H
#define WINDOW_H

# include <string>
#include "libraries/SDL/SDL2_image.framework/Versions/A/Headers/SDL_image.h"
#include "libraries/SDL/SDL2.framework/Versions/A/Headers/SDL.h"
#include "libraries/SDL/SDL2_ttf.framework/Versions/A/Headers/SDL_ttf.h"
#include "Display/ADisplay.h"

class Window : ADisplay {

private:
    Window();
    Window(std::string name);
    Window(Window const & c);
    Window & operator=(Window const & c);

public:
    Window(const std::string &title, int width, int height);
    ~Window();

    void pollEvents();
    void clear() const;
    void update() const;

    inline bool isClosed() const { return _closed; };
    int getFlag(void) const;
    void dispInit();

private:
    std::string _title;
    int         _width;
    int         _height;
    bool        _closed;
    int         _flag;
    void    displayModules();
    void    updateDisplayInfo();
    SDL_Window *_window;

public:
    static SDL_Renderer *renderer;
};

#endif

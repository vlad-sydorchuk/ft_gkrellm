//
// Created by Vlad Sydorchuk on 11/11/17.
//

#ifndef RECT_H
#define RECT_H

#include "Window.h"
#include "libraries/SDL/SDL2_image.framework/Versions/A/Headers/SDL_image.h"
#include "libraries/SDL/SDL2.framework/Versions/A/Headers/SDL.h"
#include "libraries/SDL/SDL2_ttf.framework/Versions/A/Headers/SDL_ttf.h"

class Rect {

private:
    Rect();
    Rect(std::string name);
    Rect(Rect const & c);
    Rect & operator=(Rect const & c);

public:
    Rect(int w, int h, int x, int y, int r, int g, int b, int a);
    Rect(int w, int h, int x, int y, const std::string &image_path);

    ~Rect();
    void draw() const;
    void drawImg();

private:

    int _w;
    int _h;
    int _x;
    int _y;
    int _r;
    int _g;
    int _b;
    int _a;

    //SDL_Texture *_texture1;

};


#endif

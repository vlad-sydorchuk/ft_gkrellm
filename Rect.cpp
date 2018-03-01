//
// Created by Vlad Sydorchuk on 11/11/17.
//

#include "Rect.h"
#include <iostream>
#include <vector>
#include <string>

Rect::Rect(int w, int h, int x, int y, int r, int g, int b, int a) :
_w(w), _h(h), _x(x), _y(y), _r(r), _g(g), _b(b), _a(a)
{

}

Rect::Rect(int w, int h, int x, int y, const std::string &image_path) :
_w(w), _h(h), _x(x), _y(y)
{
    /*
    SDL_Surface *surface = IMG_Load(image_path.c_str());
    if (!surface)
    {
        std::cout << "Error create surface" << std::endl;
    }
    _texture = SDL_CreateTextureFromSurface(_renderer, surface);
    if (!_texture)
    {
        std::cout << "Error create _texture" << std::endl;
    }
    SDL_FreeSurface(surface);
    */
}

Rect::~Rect()
{
    //SDL_DestroyTexture(_texture);
}

void Rect::drawImg()
{
    int step;
    std::vector<std::string> img;

    img.push_back("res/img/all.png");
    img.push_back("res/img/user.png");
    img.push_back("res/img/info.png");
    img.push_back("res/img/clock.png");
    img.push_back("res/img/cpu.png");
    img.push_back("res/img/ram.png");
    img.push_back("res/img/network.png");
    img.push_back("res/img/unicorn.png");

    SDL_Texture *texture[8];
    SDL_Rect rectImg[8];
    SDL_Surface *surface;

    step = 300;
    for (int i = 0; i < img.size() - 1; i++)
    {
        surface = IMG_Load(img[i].c_str());
        texture[i] = SDL_CreateTextureFromSurface(Window::renderer, surface);
        SDL_FreeSurface(surface);

        rectImg[i].w = 100;
        rectImg[i].h = 100;
        rectImg[i].x = 315;
        rectImg[i].y = step;
        SDL_RenderCopy(Window::renderer, texture[i], nullptr, &rectImg[i]);
        SDL_DestroyTexture(texture[i]);
        step += 100;
    }

    surface = IMG_Load(img[7].c_str());
    texture[7] = SDL_CreateTextureFromSurface(Window::renderer, surface);
    SDL_FreeSurface(surface);

    rectImg[7].w = 100;
    rectImg[7].h = 100;
    rectImg[7].x = 1465;
    rectImg[7].y = step + 80;
    SDL_RenderCopy(Window::renderer, texture[7], nullptr, &rectImg[7]);
    SDL_DestroyTexture(texture[7]);
}

void Rect::draw() const
{
    SDL_Rect rect;
    SDL_Rect rectLine[6];

    //bg yellow
    rect.w = 450;
    rect.h = 600 * 2;
    rect.x = 0;
    rect.y = 0;

    SDL_SetRenderDrawColor(Window::renderer, 232, 197, 100, 255);
    SDL_RenderFillRect(Window::renderer, &rect);

    int hLine = 3; // толщина линии
    int wLine = 430; // длина линии
    int step = 100; // шаг
    int shift = 300;
    int xLine = 10; // отступ слева

    SDL_SetRenderDrawColor(Window::renderer, 30, 30, 35, 255);
    for (int i = 0; i < 6; i++)
    {
        rectLine[i].w = wLine;
        rectLine[i].h = hLine;
        rectLine[i].x = xLine;
        rectLine[i].y = step + shift;
        SDL_RenderFillRect(Window::renderer, &rectLine[i]);
        step += 100;
    }
}

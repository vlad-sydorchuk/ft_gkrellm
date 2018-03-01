//
// Created by Vlad Sydorchuk on 11/11/17.
//

#include "Window.h"
#include <iostream>

#include "HostUserName.h"

SDL_Renderer *Window::renderer = nullptr;

Window::Window(const std::string &title, int width, int height) :
_title(title), _width(width), _height(height)
{
    _window = nullptr;
    dispInit();
    _flag = 0;
}

Window::~Window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(_window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Window::displayModules(void)
{

}

void Window::updateDisplayInfo(void)
{

}

void Window::dispInit() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "Error init window" << std::endl;
        return ;
    }

    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
    {
        std::cout << "Error with image" << std::endl;
        return ;
    }

    _window = SDL_CreateWindow(
            _title.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            _width, _height,
            SDL_WINDOW_ALLOW_HIGHDPI);

    if (TTF_Init() == -1)
    {
        std::cout << "Error with TTF" << std::endl;
        return ;
    }

    if (_window == nullptr)
    {
        std::cout << "Error create window" << std::endl;
        return ;
    }

    renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == nullptr)
    {
        std::cout << "Error create renderer" << std::endl;
        return ;
    }


}

int Window::getFlag(void) const
{
    return (this->_flag);
}

void Window::update(void) const
{
    SDL_RenderPresent(renderer);
}

void Window::pollEvents()
{
    SDL_Event event;


    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                _closed = true;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        _closed = true;
                        break;
                }
            case SDL_MOUSEBUTTONDOWN:
                    if (event.motion.x > 5  && event.motion.x < 220)
                    {
                        if (event.motion.y > 170 && event.motion.y < 205) // прописать для каждой кнопки
                            _flag = 0;
                        else if (event.motion.y > 210 && event.motion.y < 245) // прописать для каждой кнопки
                            _flag = 1;
                        else if (event.motion.y > 255 && event.motion.y < 295) // прописать для каждой кнопки
                            _flag = 2;
                        else if (event.motion.y > 305 && event.motion.y < 345) // прописать для каждой кнопки
                            _flag = 3;
                        else if (event.motion.y > 355 && event.motion.y < 395) // прописать для каждой кнопки
                            _flag = 4;
                        else if (event.motion.y > 405 && event.motion.y < 445) // прописать для каждой кнопки
                            _flag = 5;
                        else if (event.motion.y > 455 && event.motion.y < 495) // прописать для каждой кнопки
                            _flag = 6;
                    }
                    break;
            default:
                break;
        }
    }
}

void Window::clear() const
{
    SDL_SetRenderDrawColor(renderer, 30, 30, 35, 255);
    SDL_RenderClear(renderer);
}
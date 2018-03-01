/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Text.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:13:37 by vsydorch          #+#    #+#             */
/*   Updated: 2017/11/12 19:54:33 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Text.h"
#include "Window.h"

#include <vector>

Text::Text(int font_size)
{
	std::string font_path = "res/fonts/Prototype.ttf";
	_font = TTF_OpenFont(font_path.c_str(), font_size);
}

Text::~Text (void)
{

}

void Text::display(SDL_Renderer *renderer)
{
	std::vector<std::string> msg;

    msg.push_back("ALL");
    msg.push_back("Host/User name");
    msg.push_back("OS Info");
    msg.push_back("Data/Time");
    msg.push_back("CPU");
    msg.push_back("RAM");
    msg.push_back("Network");

    std::vector<int> x;

    x.push_back(230);
    x.push_back(40);
    x.push_back(180);
    x.push_back(130);
    x.push_back(230);
    x.push_back(215);
    x.push_back(165);

	SDL_Texture *texture[7];
	SDL_Rect rectText[7];
    SDL_Surface *surface;

    SDL_Color color = {0, 0, 0, 255};

    int y = 330;

    for (int i = 0; i < msg.size(); i++)
    {
		surface = TTF_RenderText_Solid(_font, msg[i].c_str(), color);
		texture[i] = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
		SDL_QueryTexture(texture[i], nullptr, nullptr, &rectText[i].w, &rectText[i].h);
		rectText[i].x = x[i];
		rectText[i].y = y;
		SDL_RenderCopy(renderer, texture[i], nullptr, &rectText[i]);
		SDL_DestroyTexture(texture[i]);
		y += 100;
	}
	x.clear();
	msg.clear();
}

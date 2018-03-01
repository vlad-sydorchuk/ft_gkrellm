/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostUserName.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:57:15 by vsydorch          #+#    #+#             */
/*   Updated: 2017/11/12 23:26:02 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HostUserName.h"
#include "Window.h"
#include "Text.h"
#include "Modules/UserModule.h"

HostUserName::HostUserName(int font_size)
{
	std::string font_path = "res/fonts/Montserrat-Bold.ttf";
	_font = TTF_OpenFont(font_path.c_str(), font_size);
    host = new UserModule;
}

HostUserName::~HostUserName()
{

}

void HostUserName::showInfo(SDL_Renderer *renderer)
{
    host->updateModule();
    std::size_t pos;
	std::vector<std::string> msg;

    msg.push_back("Host name:");
    msg.push_back("User name:");
    pos = host->getInfo()[0].find(":");
    msg.push_back(host->getInfo()[0].substr(pos + 1));
    
    pos = host->getInfo()[1].find(":");
    msg.push_back(host->getInfo()[1].substr(pos + 1));

	SDL_Texture *texture[4];
	SDL_Rect rectText[4];
    SDL_Surface *surface;

    SDL_Color color2 = {222, 209, 133, 255};
    SDL_Color color1 = {150, 141, 74, 255};

    int y = 330;

    int x = 550;

    for (int i = 0; i < msg.size(); i++)
    {
    	if (i == (msg.size() / 2))
    		y = 330;
    	if (i >= (msg.size() / 2))
    	{
    		x = 870;
    		surface = TTF_RenderText_Solid(_font, msg[i].c_str(), color2);
    	}
    	else
    		surface = TTF_RenderText_Solid(_font, msg[i].c_str(), color1);
		texture[i] = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
		SDL_QueryTexture(texture[i], nullptr, nullptr, &rectText[i].w, &rectText[i].h);
		rectText[i].x = x;
		rectText[i].y = y;
		SDL_RenderCopy(renderer, texture[i], nullptr, &rectText[i]);
		SDL_DestroyTexture(texture[i]);
		y += 100;
	}
	msg.clear();
}

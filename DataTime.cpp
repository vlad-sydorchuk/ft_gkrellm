/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataTime.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 22:35:12 by vsydorch          #+#    #+#             */
/*   Updated: 2017/11/12 23:25:12 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DataTime.h"
#include "Window.h"
#include "Text.h"
#include "Modules/DataModule.h"

DataTime::DataTime(int font_size)
{
	std::string font_path = "res/fonts/Montserrat-Bold.ttf";
	_font = TTF_OpenFont(font_path.c_str(), font_size);
    data = new DataModule;
}

DataTime::~DataTime()
{

}

void DataTime::showInfo(SDL_Renderer *renderer)
{
    data->updateModule();
	std::vector<std::string> msg;

    msg.push_back("Data:");
    msg.push_back(data->getInfo()[0]);
    
	SDL_Texture *texture[2];
	SDL_Rect rectText[2];
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
    		x = 770;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cpu.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 22:44:32 by vsydorch          #+#    #+#             */
/*   Updated: 2017/11/12 23:11:07 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.h"
#include "Text.h"
#include "Cpu.h"
#include "Modules/CpuModule.h"

Cpu::Cpu(int font_size)
{
	std::string font_path = "res/fonts/Montserrat-Bold.ttf";
	_font = TTF_OpenFont(font_path.c_str(), font_size);
    cpu = new CpuModule;
}

Cpu::~Cpu()
{

}

void Cpu::showInfo(SDL_Renderer *renderer)
{
    cpu->updateModule();
    std::size_t pos;
	std::vector<std::string> msg;
	int end;

    msg.push_back("CPU: ");
    msg.push_back("CPU Idle: ");
    msg.push_back("CPU Load:");
    msg.push_back("CPU Core:");

	pos = cpu->getInfo()[0].find(":");
    msg.push_back(cpu->getInfo()[0].substr(pos + 1));

    pos = cpu->getInfo()[1].find(":");
    end = cpu->getInfo()[1].substr(pos + 1).size();
    msg.push_back(cpu->getInfo()[1].substr(pos + 1, end - 1));
    
    pos = cpu->getInfo()[2].find(":");
    end = cpu->getInfo()[2].substr(pos + 1).size();
    msg.push_back(cpu->getInfo()[2].substr(pos + 1, end - 1));

    pos = cpu->getInfo()[3].find(":");
    msg.push_back(cpu->getInfo()[3].substr(pos + 1));

	SDL_Texture *texture[8];
	SDL_Rect rectText[8];
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
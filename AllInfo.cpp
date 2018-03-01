/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AllInfo.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:51:19 by vsydorch          #+#    #+#             */
/*   Updated: 2017/11/12 23:30:35 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AllInfo.h"
#include "Window.h"
#include "Text.h"

#include "Modules/UserModule.h"
#include "Modules/OsModule.h"
#include "Modules/DataModule.h"
#include "Modules/CpuModule.h"
#include "Modules/RamModule.h"
#include "Modules/NetModule.h"

AllInfo::AllInfo(std::string hostName, int font_size)
{
	std::string font_path = "res/fonts/Montserrat-Bold.ttf";
	_hostName = hostName;
	_font = TTF_OpenFont(font_path.c_str(), font_size);

    host = new UserModule;
    os = new OsModule;
    data = new DataModule;
    cpu = new CpuModule;
    ram = new RamModule;
    net = new NetModule;
}

AllInfo::~AllInfo()
{

}

void AllInfo::showInfo(SDL_Renderer *renderer)
{
	std::vector<std::string> msg;
    std::size_t pos;
    int end;

    host->updateModule();
    os->updateModule();
    data->updateModule();
    cpu->updateModule();
    ram->updateModule();
    net->updateModule();

    msg.push_back("Host name:");
    msg.push_back("User name:");
    msg.push_back("Product name:");
    msg.push_back("Product version:");
    msg.push_back("Build version:");
    msg.push_back("Data:");
    msg.push_back("CPU: ");
    msg.push_back("CPU Idle: ");
    msg.push_back("CPU Load:");
    msg.push_back("RAM: ");
    msg.push_back("Network: ");
    
    pos = host->getInfo()[0].find(":");
    msg.push_back(host->getInfo()[0].substr(pos + 1));
    
    pos = host->getInfo()[1].find(":");
    msg.push_back(host->getInfo()[1].substr(pos + 1));
    
    pos = os->getInfo()[0].find(":");
    msg.push_back(os->getInfo()[0].substr(pos + 1));
    
    pos = os->getInfo()[1].find(":");
    msg.push_back(os->getInfo()[1].substr(pos + 1));
    
    pos = os->getInfo()[2].find(":");
    msg.push_back(os->getInfo()[2].substr(pos + 1));

    msg.push_back(data->getInfo()[0]);

    pos = cpu->getInfo()[0].find(":");
    msg.push_back(cpu->getInfo()[0].substr(pos + 1));

    pos = cpu->getInfo()[1].find(":");
    end = cpu->getInfo()[1].substr(pos + 1).size();
    msg.push_back(cpu->getInfo()[1].substr(pos + 1, end - 1));
    
    pos = cpu->getInfo()[2].find(":");
    end = cpu->getInfo()[2].substr(pos + 1).size();
    msg.push_back(cpu->getInfo()[2].substr(pos + 1, end - 1));
    
    pos = ram->getInfo()[0].find(":");
    msg.push_back(ram->getInfo()[0].substr(pos + 1));
    
    pos = net->getInfo()[0].find(":");
    msg.push_back(net->getInfo()[0].substr(pos + 1));

	SDL_Texture *texture[22];
	SDL_Rect rectText[22];
    SDL_Surface *surface;

    SDL_Color color2 = {222, 209, 133, 255};
    SDL_Color color1 = {150, 141, 74, 255};

    int y = 50;

    int x = 550;

    for (int i = 0; i < msg.size(); i++)
    {
    	if (i == (msg.size() / 2))
    		y = 50;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Network.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 22:56:18 by vsydorch          #+#    #+#             */
/*   Updated: 2017/11/12 23:26:53 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORK_H
# define NETWORK_H

#include <string>
#include "Text.h"
#include <vector>

#include "libraries/SDL/SDL2_image.framework/Versions/A/Headers/SDL_image.h"
#include "libraries/SDL/SDL2.framework/Versions/A/Headers/SDL.h"
#include "libraries/SDL/SDL2_ttf.framework/Versions/A/Headers/SDL_ttf.h"

class NetModule;

class Network
{
	private:
		Network();
		Network(std::string name);
		Network(Network const & c);
		Network & operator=(Network const & c);

	public:
		Network(int font_size);
		~Network();

		void showInfo(SDL_Renderer *renderer);

	private:
		std::string _hostName;
		std::string _userName;
		TTF_Font *_font;

		NetModule *net;
};

#endif

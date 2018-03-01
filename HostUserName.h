/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostUserName.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:57:28 by vsydorch          #+#    #+#             */
/*   Updated: 2017/11/12 23:26:06 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTUSERNAME_H
# define HOSTUSERNAME_H

#include <string>
#include "Text.h"
#include <vector>

#include "libraries/SDL/SDL2_image.framework/Versions/A/Headers/SDL_image.h"
#include "libraries/SDL/SDL2.framework/Versions/A/Headers/SDL.h"
#include "libraries/SDL/SDL2_ttf.framework/Versions/A/Headers/SDL_ttf.h"

class UserModule;

class HostUserName 
{
	private:
		HostUserName();
		HostUserName(std::string name);
		HostUserName(HostUserName const & c);
		HostUserName & operator=(HostUserName const & c);

	public:
		HostUserName(int font_size);
		~HostUserName();

		void showInfo(SDL_Renderer *renderer);

	private:
		std::string _hostName;
		std::string _userName;
		TTF_Font *_font;

		UserModule *host;
};

#endif
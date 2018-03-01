/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ram.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 22:50:44 by vsydorch          #+#    #+#             */
/*   Updated: 2017/11/12 23:08:34 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAM_H
# define RAM_H

#include <string>
#include "Text.h"
#include <vector>

#include "libraries/SDL/SDL2_image.framework/Versions/A/Headers/SDL_image.h"
#include "libraries/SDL/SDL2.framework/Versions/A/Headers/SDL.h"
#include "libraries/SDL/SDL2_ttf.framework/Versions/A/Headers/SDL_ttf.h"

class RamModule;

class Ram
{
	private:
		Ram();
		Ram(std::string name);
		Ram(Ram const & c);
		Ram & operator=(Ram const & c);

	public:
		Ram(int font_size);
		~Ram();

		void showInfo(SDL_Renderer *renderer);

	private:
		std::string _hostName;
		std::string _userName;
		TTF_Font *_font;

		RamModule *ram;
};


#endif
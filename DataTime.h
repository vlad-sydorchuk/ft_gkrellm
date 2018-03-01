/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataTime.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 22:35:22 by vsydorch          #+#    #+#             */
/*   Updated: 2017/11/12 23:25:16 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATATIME_H
# define DATATIME_H

#include <string>
#include "Text.h"
#include <vector>

#include "libraries/SDL/SDL2_image.framework/Versions/A/Headers/SDL_image.h"
#include "libraries/SDL/SDL2.framework/Versions/A/Headers/SDL.h"
#include "libraries/SDL/SDL2_ttf.framework/Versions/A/Headers/SDL_ttf.h"

class DataModule;

class DataTime 
{
	private:
		DataTime();
		DataTime(std::string name);
		DataTime(DataTime const & c);
		DataTime & operator=(DataTime const & c);

	public:
		DataTime(int font_size);
		~DataTime();

		void showInfo(SDL_Renderer *renderer);


	private:
		std::string _hostName;
		std::string _userName;
		TTF_Font *_font;

		DataModule *data;
};

#endif

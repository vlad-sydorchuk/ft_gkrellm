/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsInfo.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 22:11:53 by vsydorch          #+#    #+#             */
/*   Updated: 2017/11/12 23:08:38 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFO_H
# define OSINFO_H

#include <string>
#include "Text.h"
#include <vector>

#include "libraries/SDL/SDL2_image.framework/Versions/A/Headers/SDL_image.h"
#include "libraries/SDL/SDL2.framework/Versions/A/Headers/SDL.h"
#include "libraries/SDL/SDL2_ttf.framework/Versions/A/Headers/SDL_ttf.h"

class OsModule;

class OsInfo
{
	private:
		OsInfo();
		OsInfo(std::string name);
		OsInfo(OsInfo const & c);
		OsInfo & operator=(OsInfo const & c);

	public:
		OsInfo(int font_size);
		~OsInfo();

		void showInfo(SDL_Renderer *renderer);

		/* Setter's */
		void setUser(std::string const user);
		void setHost(std::string const host);

		/* Getter's */
		std::string & getUser(void) const;
		std::string & getHost(void) const;

	private:
		std::string _hostName;
		std::string _userName;
		TTF_Font *_font;

		OsModule *os;
};


#endif
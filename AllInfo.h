/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AllInfo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:51:25 by vsydorch          #+#    #+#             */
/*   Updated: 2017/11/12 23:22:34 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLINFO_H
# define ALLINFO_H

#include <string>
#include "Text.h"
#include <vector>

#include "libraries/SDL/SDL2_image.framework/Versions/A/Headers/SDL_image.h"
#include "libraries/SDL/SDL2.framework/Versions/A/Headers/SDL.h"
#include "libraries/SDL/SDL2_ttf.framework/Versions/A/Headers/SDL_ttf.h"

class UserModule;
class OsModule;
class DataModule;
class CpuModule;
class RamModule;
class NetModule;

class AllInfo 
{
	private:
		AllInfo();
		AllInfo(std::string name);
		AllInfo(AllInfo const & c);
		AllInfo & operator=(AllInfo const & c);

	public:
		AllInfo(std::string hostName, int font_size);
		~AllInfo();

		void showInfo(SDL_Renderer *renderer);

	private:
		std::string _hostName;
		std::string _userName;
		std::string _productName;
		std::string _productVersion;
		std::string _buildVersion;
		std::string _proc;
		std::string _cpuIdle;
		std::string _cpuLoad;
		std::string _ram;
		std::string _network;
		TTF_Font *_font;

		UserModule *host;
		OsModule *os;
		DataModule *data;
		CpuModule *cpu;
		RamModule *ram;
		NetModule *net;
};

#endif
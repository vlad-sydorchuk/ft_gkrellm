/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cpu.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 22:44:27 by vsydorch          #+#    #+#             */
/*   Updated: 2017/11/12 23:08:55 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_H
# define CPU_H

#include <string>
#include "Text.h"
#include <vector>

#include "libraries/SDL/SDL2_image.framework/Versions/A/Headers/SDL_image.h"
#include "libraries/SDL/SDL2.framework/Versions/A/Headers/SDL.h"
#include "libraries/SDL/SDL2_ttf.framework/Versions/A/Headers/SDL_ttf.h"

class CpuModule;

class Cpu
{
	private:
		Cpu();
		Cpu(std::string name);
		Cpu(Cpu const & c);
		Cpu & operator=(Cpu const & c);
		
	public:
		Cpu(int font_size);
		~Cpu();

		void showInfo(SDL_Renderer *renderer);

	private:
		std::string _hostName;
		std::string _userName;
		TTF_Font *_font;

		CpuModule *cpu;
};


#endif
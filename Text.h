/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Text.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:13:44 by vsydorch          #+#    #+#             */
/*   Updated: 2017/11/12 23:08:24 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXT_H
# define TEXT_H

#include "libraries/SDL/SDL2_image.framework/Versions/A/Headers/SDL_image.h"
#include "libraries/SDL/SDL2.framework/Versions/A/Headers/SDL.h"
#include "libraries/SDL/SDL2_ttf.framework/Versions/A/Headers/SDL_ttf.h"

#include <iostream>
#include <string>

class Text
{

private:
	Text();
    Text(std::string name);
    Text(Text const & c);
    Text & operator=(Text const & c);

public:
	Text(int font_size);
	~Text();

	void display(SDL_Renderer *renderer);

private:
	TTF_Font *_font;

};

#endif
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 11:49:10 by vsydorch          #+#    #+#              #
#    Updated: 2017/11/12 22:59:25 by vsydorch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_gkrellm
CC = clang++ 
CFLAGS = -F./libraries/SDL
SDL_FLAGS = -framework SDL2 -framework SDL2_image -framework SDL2_ttf
DSRC = ./
SRC = 	Window.cpp \
		Rect.cpp \
		Text.cpp \
		AllInfo.cpp \
		HostUserName.cpp \
		OsInfo.cpp \
		DataTime.cpp \
		Cpu.cpp \
		Ram.cpp \
		Network.cpp \
		main.cpp \
		Display/DisplayNcurses.cpp \
		Modules/CpuModule.cpp \
		Modules/DataModule.cpp \
		Modules/NetModule.cpp \
		Modules/OsModule.cpp \
		Modules/RamModule.cpp \
		Modules/UserModule.cpp \

OBJ = $(addprefix $(DSRC)/,$(SRC:.cpp=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) -Wall -Werror -Wextra $(CFLAGS) $(SDL_FLAGS) $(OBJ) -o $(NAME) -lncurses


%.o: %.cpp
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "Compiling.."  $<

clean:
	@echo "Cleaning.."
	@rm -rf $(OBJ)

fclean: clean
	@echo "Cleaning.."
	@rm -rf $(NAME)

re: fclean all

sdl2:
	cp -r libraries/SDL/SDL2_image.framework ~/Library/Frameworks/
	cp -r libraries/SDL/SDL2.framework ~/Library/Frameworks/
	cp -r libraries/SDL/SDL2_ttf.framework ~/Library/Frameworks/

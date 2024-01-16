# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlence-l <nlence-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 14:06:05 by nlence-l          #+#    #+#              #
#    Updated: 2024/01/12 14:06:08 by nlence-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GRAY 	= \033[90m
GREEN   = \033[32m
RED		= \033[31m
MAGENTA = \033[35m
YELLOW  = \033[33m
BLUE	= \033[34m
BOLD	= \033[1m
RESET   = \033[0m

NAME	= cub3D

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address

SRCDIR	= srcs

SRC 	= srcs/draw_rays.c srcs/draw_rays2.c srcs/draw_rays3.c srcs/draw_rays4.c \
		srcs/init_game.c srcs/init_textures.c srcs/main.c srcs/minimap_utils.c \
		srcs/minimap.c srcs/move_player.c srcs/torch.c srcs/utils.c srcs/utils2.c \
		srcs/parsing/check.c srcs/parsing/check1.c srcs/parsing/error.c srcs/parsing/init.c \
		srcs/parsing/map.c srcs/parsing/mem.c srcs/parsing/utils.c srcs/parsing/utils1.c \
		srcs/parsing/utils2.c

OBJDIR	= .obj

OBJ 	= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

HEADER	= -I ./include -I ./libft/include -I ./MLX42/include/MLX42

LIBS 	= -L./MLX42/build -lmlx42 ./libft/libft.a -ldl -lglfw -pthread -lm

all: $(NAME)

mlft:
	@make -C libft
	
mlmlx:
	@cmake -S MLX42 -B MLX42/build && make -C MLX42/build -j4
	@printf "$(GRAY) - MLX42\t$(GREEN)[OK]$(RESET)\n"

$(NAME): mlmlx mlft $(OBJ)
	@printf "$(GRAY) - $(NAME)$(RESET)\t"
	@$(CC) $(CFLAGS) $(HEADER) $(OBJ) -o $(NAME) $(LIBS)
	@printf "$(GREEN)[OK]$(RESET)\n"
	
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "$(GRAY) - objects$(RESET)\t"
	@rm -rf $(OBJDIR)
	@printf "$(YELLOW)[REMOVED]$(RESET)\n"

fclean: clean
	@printf "$(GRAY) - $(NAME)$(RESET)\t"
	@rm -f $(NAME)
	@printf "$(YELLOW)[REMOVED]$(RESET)\n"

re: fclean all

clib:
	@$(MAKE) fclean -sC libft

call: fclean clib

.PHONY: all, mlft, mlmlx, clean, fclean, re, clib, call
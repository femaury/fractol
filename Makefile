# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: femaury <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 20:03:09 by femaury           #+#    #+#              #
#    Updated: 2018/07/07 22:18:14 by femaury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC_PATH = srcs
SRC_NAME = fractol_main.c fractol_draw.c mlx_events.c mlx_img_refresh.c \
		   fractol_julia.c fractol_color.c fractol_mandelbrot.c
OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -framework OpenGL -framework AppKit

ifndef ECHO
T := $(words $(SRC_NAME))
N := x
C = $(words $N)$(eval N := x $N)
ECHO = echo "\r[\033[33m`expr $C '*' 100 / $T`%\033[0m] \
	   Compiling \033[35mfractol\033[0m...\c"
endif

.PHONY: all, clean, fclean, re

all:
	@$(MAKE) -C libft/
	@$(MAKE) -C minilibx/
	@$(MAKE) $(NAME)

$(NAME): $(OBJ) libft/libft.a
	@$(CC) $(CFLAGS) -Iincs -o $(NAME) $(OBJ) libft/libft.a \
		libft/ft_printf/libftprintf.a minilibx/libmlx.a $(MLXFLAGS)
	@echo "\r[\033[32m100%\033[0m] \033[35m$(NAME)\033[0m is ready!   "

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c incs/fractol.h
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -Iincs -o $@ -c $<
	@$(ECHO)

clean:
ifeq ($(MAKECMDGOALS), clean)
	@$(RM) $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@$(MAKE) -C libft/ clean
	@$(MAKE) -C minilibx/ clean
	@echo "[\033[32mOK\033[0m] minilibx cleaned."
	@echo "[\033[32mOK\033[0m] $(NAME) objects cleaned."
else
	@$(RM) $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "[\033[32mOK\033[0m] $(NAME) objects cleaned."
endif

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C libft/ fclean
	@$(MAKE) -C minilibx/ clean
	@echo "[\033[32mOK\033[0m] minilibx cleaned."
	@echo "[\033[32mOK\033[0m] $(NAME) \033[31mhas been removed.\033[0m"
ifeq ($(MAKECMDGOALS), re)
	@echo ""
endif

re: fclean all

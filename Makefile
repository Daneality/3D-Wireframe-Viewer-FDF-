# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 17:23:33 by nradin            #+#    #+#              #
#    Updated: 2023/03/07 19:47:41 by dsas             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c \
		color.c \
		draw.c \
		exits.c \
		get_input.c \
		isometric.c \
		key_hooks.c \
		mouse_hooks.c \
		rotations.c \
		utils.c

NAME = fdf

LIBFT = libft/
MLX = mlx_mac/

SRCS_DIR = srcs/

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = gcc

CC_FLAGS =  -I/opt/X11/include -I/includes -v -Wall -Wextra -Werror

all: $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@gcc $(CC_FLAGS) -Imlx_mac -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	@make -C $(LIBFT)
	@make -C $(MLX)
	mv $(MLX)/libmlx.dylib libmlx.dylib
	@gcc -o3 $(CC_FLAGS) -Lmlx_mac -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJECTS_PREFIXED) libft/libft.a ./libmlx.dylib

clean:
	@rm -rf $(OBJS_DIR)
	@make fclean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@rm -f libmlx.dylib

re: fclean all

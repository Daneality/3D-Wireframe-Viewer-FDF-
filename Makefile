# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 17:23:33 by nradin            #+#    #+#              #
#    Updated: 2023/02/09 19:18:15 by dsas             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c

NAME = fractal

LIBFT = libft/
MLX = mlx_mac/

SRCS_DIR = srcs/

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = gcc

CC_FLAGS =  -I/opt/X11/include #-Wall -Wextra -Werror

all: $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@gcc $(CC_FLAGS) -Imlx_mac -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	@make -C $(LIBFT)
	@make -C $(MLX)
	mv $(MLX)/libmlx.dylib libmlx.dylib
	@gcc -o3 -Lmlx_mac -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJECTS_PREFIXED) libft/libft.a ./libmlx.dylib

clean:
	@rm -rf $(OBJS_DIR)
	@make fclean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@rm -f libmlx.dylib

re: fclean all

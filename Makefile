# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msiitone <msiitone@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 14:31:25 by msiitone          #+#    #+#              #
#    Updated: 2024/05/24 22:10:17 by msiitone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S := $(shell uname -s)

MLX_FLAGS := -lglfw

ifeq ($(UNAME_S),Linux)
    MLX_FLAGS += -ldl -pthread -lm
endif
ifeq ($(UNAME_S),Darwin)
    MLX_FLAGS += -L"/Users/$(USER)/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit
endif

NAME = so_long

SRCS = srcs/main.c srcs/check_map.c

OBJ = $(SRCS:.c=.o)

INCLUDES = -I./includes -I./libft -I./MLX42/include

MLX42 = MLX42/build/libmlx42.a $(MLX_FLAGS)

LIBFT = ./libft

CFLAGS = -Wall -Wextra -Werror

COMPILE = cc $(CFLAGS) $(INCLUDES)

all : $(NAME)

%.o : %.c
	$(COMPILE) -c $< -o $@
	
$(NAME) : $(OBJ)
	$(MAKE) -C $(LIBFT)
	@cmake MLX42 -B ./MLX42/build && $(MAKE) -C MLX42/build -j4
	$(COMPILE) $(OBJ) $(MLX42) -L$(LIBFT) -lft -o $(NAME) 

clean :
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT) clean
	

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT) fclean
	@rm -rf MLX42/build

re : fclean all

.PHONY: all clean fclean re

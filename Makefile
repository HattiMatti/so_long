# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msiitone <msiitone@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 14:31:25 by msiitone          #+#    #+#              #
#    Updated: 2024/05/15 18:13:42 by msiitone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main.c

OBJ = $(SRCS:.c=.o)

INCLUDES = ./includes/so_long.h 

MLX42 = MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

LIBFT = ./libft

CFLAGS = -Wall -Wextra -Werror

COMPILE = cc $(CFLAGS)

all : $(NAME)

$(OBJ): $(SRCS)
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
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msiitone <msiitone@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 18:28:13 by msiitone          #+#    #+#              #
#    Updated: 2023/11/17 18:32:20 by msiitone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_isascii.c ft_memcpy.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c \
				ft_atoi.c ft_isdigit.c ft_memmove.c ft_split.c ft_strlcpy.c \
				ft_strtrim.c ft_bzero.c ft_isprint.c ft_memset.c ft_strchr.c \
				ft_strlen.c ft_substr.c ft_calloc.c ft_itoa.c ft_putchar_fd.c \
				ft_strdup.c ft_strmapi.c ft_tolower.c ft_isalnum.c \
				ft_memchr.c ft_putendl_fd.c ft_striteri.c ft_strncmp.c \
				ft_toupper.c ft_isalpha.c ft_memcmp.c ft_putnbr_fd.c \
				ft_strjoin.c ft_strnstr.c get_next_line.c get_next_line_utils.c \
				ft_printf.c ft_printf_utils.c

OBJ	=	${SRCS:.c=.o}

CFLAGS	= -Wall -Wextra -Werror

COMPILE	= cc $(CFLAGS) -c

$(NAME): $(OBJ)
	$(COMPILE) $(SRCS)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re

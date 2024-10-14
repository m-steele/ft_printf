# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 09:57:19 by ekosnick          #+#    #+#              #
#    Updated: 2024/10/02 09:59:51 by ekosnick         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#compliler and flags
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
#source 'c' and object 'o' files
SRCS =	ft_bzero.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memset.c \
		ft_strlen.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
		ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
		ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_ptoa.c

OBJ = $(SRCS:.c=.o)
NAME = libft.a

#converts .c files --> .o files in libft.h directory: (-o $@ -->id .o names) ($< --> first rerequisite .c names)
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@ 

#creates the library
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

#Rules
all: $(NAME)

clean:
	$(RM) $(OBJ) program a.out

fclean: clean
	$(RM) $(NAME)

re:	fclean all

#Do not confuse files with these rules
.PHONY: re all clean fclean
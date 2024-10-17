# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 09:52:59 by ekosnick          #+#    #+#              #
#    Updated: 2024/10/17 10:55:12 by ekosnick         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#compliler and flags
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

LIB = ./libft/libft.a

#source 'c' and object 'o' files
NAME = libftprintf.a
SRCS =	ft_printf.c \
		process_p.c process_u.c process_x.c process_xx.c \
		process_id.c process_s.c process_c.c

OBJ = $(SRCS:.c=.o)
LIBFT_OBJECTS = libft/*.o

#converts .c files --> .o files in .h directory: (-o $@ -->id .o names) ($< --> first rerequisite .c names)
%.o: %.c libftprintf.h
	$(CC) $(CFLAGS) -c $< -o $@ 

#creates the library
$(NAME): $(OBJ) libft
	ar rcs $(NAME) $(OBJ) $(LIBFT_OBJECTS)

#Rules
libft:
	make -C libft

all: $(NAME)

clean:
	$(RM) $(OBJ) program a.out

fclean: clean
	$(RM) $(NAME)

re:	fclean all

#Do not confuse files with these rules
.PHONY: re all clean fclean
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 09:52:59 by ekosnick          #+#    #+#              #
#    Updated: 2024/10/18 12:30:06 by ekosnick         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#compliler and flags
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

#source 'c' to object 'o' files
SRCS =	ft_printf.c \
		process_p.c process_u.c process_x.c process_xx.c \
		process_id.c process_s.c process_c.c \
		ft_itoa.c ft_strdup.c ft_strlen.c \
		ft_strjoin.c

OBJ = $(SRCS:.c=.o)
NAME = libftprintf.a

#converts .c files --> .o files in .h directory: (-o $@ -->id .o names) ($< --> first rerequisite .c names)
%.o: %.c ft_printf.h
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
# get_next_line
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raulp <raulp@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 15:34:37 by raulp             #+#    #+#              #
#    Updated: 2025/11/03 15:48:49 by raulp            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME    = libftprintf.a

CC      = cc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar

SRC     = 	get_next_line.c \
			get_next_line_utils.c \

OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs $(NAME) $(OBJ)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
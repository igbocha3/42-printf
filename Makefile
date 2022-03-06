# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igbocha3 <igbocha3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 23:26:49 by igbocha3          #+#    #+#              #
#    Updated: 2022/02/28 09:52:36 by igbocha3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	ft_printf.c \
		ft_put_c.c \
		ft_put_s.c \
		ft_put_p.c \
		ft_put_d.c \
		ft_put_u.c \
		ft_put_x.c \
		ft_len_d.c \
		ft_len_x.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	cc $(FLAGS) -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
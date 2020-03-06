# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tliao <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/19 20:06:45 by tliao             #+#    #+#              #
#    Updated: 2019/08/19 22:22:38 by tliao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_advanced_do-op

SRC = main.c op.c op2.c

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror $(SRC) -o $(NAME)

clean:
	@/bin/rm -f $(NAME)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

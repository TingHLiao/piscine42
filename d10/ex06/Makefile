# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tliao <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/19 20:06:45 by tliao             #+#    #+#              #
#    Updated: 2019/08/19 21:02:08 by tliao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

SRC = main.c op.c

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror $(SRC) -o $(NAME)

clean:
	@/bin/rm -f $(NAME)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

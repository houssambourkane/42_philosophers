# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 11:23:55 by hbourkan          #+#    #+#              #
#    Updated: 2022/03/12 22:41:33 by hbourkan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FLAGS = -Wall -Wextra -Werror

CFILES = philo.c philo_utils.c start.c end.c \
		philo_list.c diner.c parse.c controlers.c print.c \
		spawning.c

all: $(NAME)

$(NAME):
	cc $(CFILES) $(FLAGS) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all
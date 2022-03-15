# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 11:23:55 by hbourkan          #+#    #+#              #
#    Updated: 2022/03/12 22:40:23 by hbourkan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

FLAGS = -Wall -Wextra -Werror

CFILES = philo_bonus.c philo_utils_bonus.c start_bonus.c end_bonus.c \
		philo_list_bonus.c diner_bonus.c parse_bonus.c controlers_bonus.c print_bonus.c\
		spawning_bonus.c

all: $(NAME)

$(NAME):
	cc $(CFILES) $(FLAGS) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all
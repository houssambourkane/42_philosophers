/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:09:26 by hbourkan          #+#    #+#             */
/*   Updated: 2022/03/11 18:48:16 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	parse_philo(t_data *data, t_philo **list_philo)
{
	int		i;
	t_philo	*temp;
	t_philo	*new_element;

	i = 1;
	*list_philo = create_new_node(data, i++);
	temp = *list_philo;
	while (i <= data->number_of_philosophers)
	{
		if (i == data->number_of_philosophers)
			new_element = create_last_node(data, i, temp);
		else
			new_element = create_new_node(data, i);
		add_node_to_list(list_philo, new_element);
		i++;
	}
}

void	parse_data(int argc, char **argv, t_data *data)
{
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->each_philo_must_eat = ft_atoi(argv[5]);
	else
		data->each_philo_must_eat = -1;
}

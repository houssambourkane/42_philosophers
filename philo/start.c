/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:08:26 by hbourkan          #+#    #+#             */
/*   Updated: 2022/03/10 16:19:47 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_init(t_data *data, t_philo **philo)
{
	t_philo	*temp;
	int		i;

	i = 0;
	temp = *philo;
	data->kill_philos = 0;
	data->fork = malloc(sizeof(*(data->fork)) * data->number_of_philosophers);
	if (!data->fork)
		return ;
	pthread_mutex_init(&data->print_mutex, NULL);
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_init(&data->fork[i++], NULL);
		pthread_mutex_init(&temp->eat_mutex, NULL);
		temp = temp->next;
	}
}

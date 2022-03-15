/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:10:15 by hbourkan          #+#    #+#             */
/*   Updated: 2022/03/10 16:24:26 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_destroy(t_data *data, t_philo **philo)
{
	t_philo	*temp;
	int		i;

	i = 0;
	temp = *philo;
	pthread_mutex_destroy(&data->print_mutex);
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_destroy(&data->fork[i++]);
		pthread_mutex_destroy(&temp->eat_mutex);
		temp = temp->next;
	}
	free(data->fork);
}

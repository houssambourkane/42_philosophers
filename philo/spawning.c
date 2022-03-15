/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:22:21 by hbourkan          #+#    #+#             */
/*   Updated: 2022/03/15 15:08:51 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_philo *philo)
{
	t_philo	*temp;

	temp = philo;
	while (temp)
	{
		pthread_join(temp->thr, NULL);
		temp = temp->next;
		if (temp == philo)
			break ;
	}
}

static	void	philo_creation(t_philo *philo)
{
	t_philo		*temp;
	pthread_t	control_thr;

	temp = philo;
	while (temp)
	{
		temp->last_meal = current_timestamp_millisecond();
		pthread_create(&temp->thr, NULL, routine, temp);
		pthread_create(&control_thr, NULL, control, temp);
		pthread_detach(control_thr);
		temp = temp->next;
		if (temp == philo)
			break ;
	}
	if (philo->data->each_philo_must_eat != -1)
	{
		pthread_create(&control_thr, NULL, meal_counter, philo);
		pthread_detach(control_thr);
	}
	join_threads(philo);
}

void	philosophers_spawner(t_philo **philo)
{
	t_philo		*temp;

	temp = *philo;
	temp->data->start_time = current_timestamp_millisecond();
	if (temp->data->number_of_philosophers == 1)
	{
		print_mutex(temp, "died\n");
		return ;
	}
	philo_creation(*philo);
}

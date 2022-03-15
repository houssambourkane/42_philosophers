/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlers_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:20:00 by hbourkan          #+#    #+#             */
/*   Updated: 2022/03/12 22:42:57 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*meal_counter(void *arg)
{
	t_philo	*philo;
	t_philo	*temp;

	philo = (t_philo *)arg;
	temp = philo;
	while (temp)
	{
		sem_wait(temp->meals_sem);
		temp = temp->next;
		if (temp == philo)
			break ;
	}
	sem_post(philo->data->signal_death);
	return (NULL);
}

void	*control(void *arg)
{
	t_philo	*philo;
	t_philo	*temp;

	philo = (t_philo *)arg;
	temp = philo;
	while (1)
	{
		if (current_timestamp_millisecond() - philo->last_meal
			>= (unsigned long) philo->data->time_to_die
			&& !philo->is_eating)
		{
			print_sem(philo, "died\n", 1);
			sem_post(philo->data->signal_death);
			exit(0);
		}
		usleep(1000);
	}
	return (NULL);
}

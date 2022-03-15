/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:20:00 by hbourkan          #+#    #+#             */
/*   Updated: 2022/03/15 15:10:23 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_meal_amount(t_philo *philo)
{
	t_philo	*temp;

	temp = philo;
	while (temp)
	{
		if (temp->meals_eaten < temp->data->each_philo_must_eat)
			return (0);
		temp = temp->next;
		if (temp == philo)
			break ;
	}	
	return (1);
}

void	*meal_counter(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->data->kill_philos)
	{
		pthread_mutex_lock(&philo->data->print_mutex);
		if (check_meal_amount(philo) == 1)
			philo->data->kill_philos = 1;
		pthread_mutex_unlock(&philo->data->print_mutex);
	}
	return (NULL);
}

void	*control(void *arg)
{
	t_philo			*philo;
	unsigned long	time_display;

	philo = (t_philo *)arg;
	while (!philo->data->kill_philos)
	{
		pthread_mutex_lock(&philo->eat_mutex);
		pthread_mutex_lock(&philo->data->print_mutex);
		time_display = current_timestamp_millisecond()
			- philo->data->start_time;
		if (current_timestamp_millisecond() - philo->last_meal
			>= (unsigned long)philo->data->time_to_die
			&& !philo->data->kill_philos)
		{
			printf("%lu %d died\n", time_display, philo->id);
			philo->data->kill_philos = 1;
		}
		pthread_mutex_unlock(&philo->data->print_mutex);
		pthread_mutex_unlock(&philo->eat_mutex);
		usleep(1000);
	}
	return (NULL);
}

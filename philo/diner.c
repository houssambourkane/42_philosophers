/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:06:59 by hbourkan          #+#    #+#             */
/*   Updated: 2022/03/15 15:11:09 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->left_fork]);
	print_mutex(philo, "has taken a fork\n");
	pthread_mutex_lock(&philo->data->fork[philo->right_fork]);
	print_mutex(philo, "has taken a fork\n");
}

static void	start_eating(t_philo *philo)
{
	unsigned long	time_display;

	pthread_mutex_lock(&philo->eat_mutex);
	time_display = current_timestamp_millisecond() - philo->data->start_time;
	philo->last_meal = current_timestamp_millisecond();
	pthread_mutex_lock(&philo->data->print_mutex);
	if (!philo->data->kill_philos)
		printf("%lu %d is eating\n", time_display, philo->id);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->print_mutex);
	my_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->fork[philo->right_fork]);
	pthread_mutex_unlock(&philo->eat_mutex);
}

static void	sleeping(t_philo *philo)
{
	print_mutex(philo, "is sleeping\n");
	my_usleep(philo->data->time_to_sleep);
	print_mutex(philo, "is thinking\n");
}

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(philo->data->time_to_eat * 1000);
	while (!philo->data->kill_philos)
	{
		take_forks(philo);
		start_eating(philo);
		sleeping(philo);
	}
	return (NULL);
}

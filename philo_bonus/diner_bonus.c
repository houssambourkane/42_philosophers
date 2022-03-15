/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:06:59 by hbourkan          #+#    #+#             */
/*   Updated: 2022/03/15 15:12:32 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	take_forks(t_philo *philo)
{
	sem_wait(philo->data->forks);
	print_sem(philo, "has taken a fork\n", 0);
	if (philo->next)
		sem_wait(philo->data->forks);
	else
	{
		print_sem(philo, "has died\n", 0);
		sem_post(philo->data->signal_death);
		exit(0);
	}
	print_sem(philo, "has taken a fork\n", 0);
}

static void	start_eating(t_philo *philo)
{
	philo->last_meal = current_timestamp_millisecond();
	philo->is_eating = 1;
	print_sem(philo, "is eating\n", 0);
	philo->meals_eaten++;
	my_usleep(philo->data->time_to_eat);
	philo->is_eating = 0;
	if (philo->meals_eaten == philo->data->each_philo_must_eat)
		sem_post(philo->meals_sem);
	sem_post(philo->data->forks);
	if (philo->next)
		sem_post(philo->data->forks);
}

static void	sleeping(t_philo *philo)
{
	print_sem(philo, "is sleeping\n", 0);
	my_usleep(philo->data->time_to_sleep);
	print_sem(philo, "is thinking\n", 0);
}

void	routine(t_philo *philo)
{
	pthread_t	control_thread;

	philo->last_meal = current_timestamp_millisecond();
	pthread_create(&control_thread, NULL, control, philo);
	pthread_detach(control_thread);
	if (philo->id % 2 == 0)
		usleep(philo->data->time_to_eat * 1000);
	while (1)
	{
		take_forks(philo);
		start_eating(philo);
		sleeping(philo);
	}
}

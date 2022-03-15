/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawning_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:22:21 by hbourkan          #+#    #+#             */
/*   Updated: 2022/03/14 13:40:57 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	terminate_childs(t_philo *philo)
{
	t_philo	*temp;

	temp = philo;
	sem_wait(temp->data->signal_death);
	while (temp)
	{
		kill(temp->child_pid, SIGTERM);
		temp = temp->next;
		if (temp == philo)
			break ;
	}
}

static	void	philo_creation(t_philo *philo)
{
	t_philo		*temp;

	temp = philo;
	while (temp)
	{
		temp->child_pid = fork();
		if (temp->child_pid == -1)
		{
			printf("Fork failed");
			exit(0);
		}
		if (temp->child_pid == 0)
			routine(temp);
		temp = temp->next;
		if (temp == philo)
			break ;
		usleep(100);
	}
	terminate_childs(philo);
}

void	philosophers_spawner(t_philo **philo)
{
	t_philo		*temp;
	pthread_t	thr;

	temp = *philo;
	temp->data->start_time = current_timestamp_millisecond();
	if (temp->data->each_philo_must_eat != -1)
	{
		pthread_create(&thr, NULL, meal_counter, temp);
		pthread_detach(thr);
	}
	philo_creation(*philo);
}

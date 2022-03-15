/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:08:26 by hbourkan          #+#    #+#             */
/*   Updated: 2022/03/12 22:41:22 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	sema_init(t_philo **philo)
{
	t_philo	*temp;

	temp = *philo;
	sem_unlink("forks");
	sem_unlink("signal_death");
	sem_unlink("print");
	sem_unlink("eat");
	sem_unlink("meals");
	temp->data->forks = sem_open("forks", O_CREAT, 0666,
			temp->data->number_of_philosophers);
	temp->data->signal_death = sem_open("signal_death", O_CREAT, 0666, 0);
	temp->data->print_sem = sem_open("print", O_CREAT, 0666, 1);
	sem_open("meals", O_CREAT, 0666, 0);
	sem_open("eat", O_CREAT, 0666, 1);
	while (temp)
	{
		temp->meals_sem = sem_open("meals", 0);
		temp = temp->next;
		if (temp == *philo)
			break ;
	}
}

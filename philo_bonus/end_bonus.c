/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:10:15 by hbourkan          #+#    #+#             */
/*   Updated: 2022/03/12 22:42:24 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	sema_destroy(t_philo **philo)
{
	t_philo	*temp;

	temp = *philo;
	sem_close(temp->data->forks);
	sem_close(temp->data->signal_death);
	sem_close(temp->data->print_sem);
	while (temp)
	{
		sem_close(temp->meals_sem);
		temp = temp->next;
		if (temp == *philo)
			break ;
	}
}

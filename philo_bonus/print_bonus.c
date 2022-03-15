/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:13:24 by hbourkan          #+#    #+#             */
/*   Updated: 2022/03/10 11:08:04 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_sem(t_philo *philo, char *str, int i)
{
	unsigned long	time_display;

	time_display = current_timestamp_millisecond() - philo->data->start_time;
	sem_wait(philo->data->print_sem);
	printf("%lu %d %s", time_display, philo->id, str);
	if (i != 1)
		sem_post(philo->data->print_sem);
}

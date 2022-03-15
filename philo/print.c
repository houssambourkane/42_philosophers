/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:13:24 by hbourkan          #+#    #+#             */
/*   Updated: 2022/03/10 16:25:01 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_mutex(t_philo *philo, char *str)
{
	unsigned long	time_display;

	pthread_mutex_lock(&philo->data->print_mutex);
	time_display = current_timestamp_millisecond()
		- philo->data->start_time;
	if (!philo->data->kill_philos)
		printf("%lu %d %s", time_display, philo->id, str);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

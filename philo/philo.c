/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:46:17 by hbourkan          #+#    #+#             */
/*   Updated: 2022/03/10 15:53:31 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	if (argc == 5 || argc == 6)
	{
		parse_data(argc, argv, &data);
		parse_philo(&data, &philo);
		if (!check_data(&data))
			return (0);
		mutex_init(&data, &philo);
		philosophers_spawner(&philo);
		mutex_destroy(&data, &philo);
	}
	else
		return (0);
}

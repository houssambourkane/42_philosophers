/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:46:17 by hbourkan          #+#    #+#             */
/*   Updated: 2022/03/12 22:42:18 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
		sema_init(&philo);
		philosophers_spawner(&philo);
		sema_destroy(&philo);
	}
	else
		exit(0);
}

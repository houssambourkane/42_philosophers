/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:47:13 by hbourkan          #+#    #+#             */
/*   Updated: 2022/03/13 18:55:45 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	nb;
	int					sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nb > 9223372036854775807 && sign == 1)
			return (-1);
		if (nb > 9223372036854775808u && sign == -1)
			return (0);
		nb = nb * 10 + str[i++] - '0';
	}
	return (nb * sign);
}

static int	print_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
	return (0);
}

int	check_data(t_data *data)
{
	if (data->number_of_philosophers <= 0)
		return (print_error("Wrong number of philosophers\n"));
	if (data->time_to_die < 0)
		return (print_error("Time to die is negative\n"));
	if (data->time_to_sleep < 0)
		return (print_error("Time to sleep is negative\n"));
	if (data->time_to_eat < 0)
		return (print_error("Time to eat is negative\n"));
	if (data->each_philo_must_eat == 0)
		return (print_error("Number of meals is invalid\n"));
	return (1);
}

unsigned long	current_timestamp_millisecond(void)
{
	struct timeval	te;

	gettimeofday(&te, NULL);
	return (te.tv_sec * 1000UL + te.tv_usec / 1000);
}

void	my_usleep(unsigned long long time_to_wait)
{
	unsigned long long	time;

	time = current_timestamp_millisecond();
	while (current_timestamp_millisecond() < time + time_to_wait)
		usleep(400);
}

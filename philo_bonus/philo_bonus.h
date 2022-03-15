/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:25:36 by hbourkan          #+#    #+#             */
/*   Updated: 2022/03/13 18:55:42 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_data
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				each_philo_must_eat;
	sem_t			*forks;
	sem_t			*print_sem;
	sem_t			*signal_death;
	unsigned long	start_time;
}	t_data;

typedef struct s_philo {
	int				id;
	pid_t			child_pid;
	int				is_eating;
	int				meals_eaten;
	sem_t			*meals_sem;
	unsigned long	last_meal;
	struct s_data	*data;
	struct s_philo	*next;
}	t_philo;

t_philo			*create_new_node(t_data *data, int id);
t_philo			*create_last_node(t_data *data, int id, t_philo *first);
t_philo			*last_node(t_philo *lst);
void			add_node_to_list(t_philo **alst, t_philo *new);
int				ft_atoi(const char *str);
void			routine(t_philo *philo);
void			parse_philo(t_data *data, t_philo **list_philo);
void			parse_data(int argc, char **argv, t_data *data);
void			sema_init(t_philo **philo);
void			sema_destroy(t_philo **philo);
void			*control(void *arg);
int				check_data(t_data *data);
unsigned long	current_timestamp_millisecond(void);
void			print_sem(t_philo *philo, char *str, int i);
void			*meal_counter(void *arg);
void			philosophers_spawner(t_philo **philo);
void			my_usleep(unsigned long long time_to_wait);
#endif

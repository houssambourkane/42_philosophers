/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:57:55 by hbourkan          #+#    #+#             */
/*   Updated: 2022/03/11 18:49:32 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*create_new_node(t_data *data, int id)
{
	t_philo	*node;

	node = malloc(sizeof(t_philo));
	if (!node)
		return (NULL);
	node->id = id;
	node->meals_eaten = 0;
	node->left_fork = id - 1;
	node->right_fork = id;
	node->data = data;
	node->next = NULL;
	return (node);
}

t_philo	*create_last_node(t_data *data, int id, t_philo *first)
{
	t_philo	*node;

	node = malloc(sizeof(t_philo));
	if (!node)
		return (NULL);
	node->id = id;
	node->meals_eaten = 0;
	node->left_fork = id - 1;
	node->right_fork = 0;
	node->data = data;
	node->next = first;
	return (node);
}

t_philo	*last_node(t_philo *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

void	add_node_to_list(t_philo **alst, t_philo *new)
{
	t_philo	*last;

	if (*alst == NULL)
	{
		*alst = new;
		(*alst)->next = NULL;
		return ;
	}
	last = last_node(*alst);
	last->next = new;
}

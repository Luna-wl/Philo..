/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:42:08 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/21 14:40:56 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// t_philo	*create_fork(t_philo *philo)
// {
// 	int	i;

// 	i = 0;
// 	philo->fork = malloc(sizeof(pthread_mutex_t) * philo->input->num);
// 	while (i < philo->input->num)
// 	{
// 		pthread_mutex_init(&philo->fork[i], NULL);
// 		i++;
// 	}
// 	return (philo);
// }

t_philo	*create_fork(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->input->num)
	{
		philo[i].fork_r = &philo[i].fork;
		philo[i].fork_l = &philo[philo[i].l_fork].fork;
		i++;
	}
	return (philo);
}

t_philo	*create_philo(t_input *input)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo) * input->num);
	if (!philo)
		return (0);
	i = -1;
	while (++i < input->num)
	{
		philo[i].id = i + 1;
		philo[i].t_eat = 0;
		philo[i].eat_cont = 0;
		philo[i].input = input;
		philo[i].take_fork = 0;
		philo[i].r_fork = i;
		philo[i].l_fork = (i + 1) % input->num;
		pthread_mutex_init(&philo[i].fork, NULL);
	}
	return (create_fork(philo));
	// return (philo);
}

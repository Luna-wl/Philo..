/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:42:08 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/20 17:37:05 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_fork(t_input *data)
{
	int	i;

	data->fork = malloc(sizeof(t_input) * data->num);
	if (!data->fork)
		return ;
	i = -1;
	while (++i < data->num)
	{
		pthread_mutex_init(&data->fork[i], NULL);
	}
}

void	create_philo(t_input *input)
{
	// t_philo	*philo;
	int		i;

	input->philo = malloc(sizeof(t_philo) * input->num);
	if (!input->philo)
		return ;
	i = -1;
	while (++i < input->num)
	{
		input->philo[i].id = i + 1;
		input->philo[i].t_eat = 0;
		input->philo[i].eat_cont = 0;
		// philo[i].input = input;
		input->philo[i].take_fork = 0;
		input->philo[i].r_fork = i;
		input->philo[i].l_fork = (i + 1) % input->num;
		// pthread_mutex_init(&philo->fork[i], NULL);
	}
	// return (philo);
}

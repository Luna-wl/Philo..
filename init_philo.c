/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:42:08 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/19 17:26:56 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		philo[i].r_fork = i;
		philo[i].l_fork = (i + 1) % input->num;
		pthread_mutex_init(&philo->fork[i], NULL);
	}
	return (philo);
}

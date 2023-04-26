/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:50:00 by y wluedara        #+#    #+#             */
/*   Updated: 2023/04/26 13:39:27 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_die(t_philo *philo)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < philo->input->num)
		{
			pthread_mutex_lock(&philo->input->lock);
			if (timestamp() - philo[i].t_eat >= philo->input->die_time)
			{
				pim_philo(philo, philo[i].id, RED"died ―(x_x)→", 1);
				return ;
			}
			if (philo->input->eat_full == philo->input->num)
			{
				return ;
			}
			pthread_mutex_unlock(&philo->input->lock);
			usleep(200);
		}
	}
}

int	check_eat(t_philo *philo)
{
	if (philo->input->must_eat == -1)
		return (1);
	else
	{
		if (philo->eat_count == philo->input->must_eat)
		{
			philo->input->eat_full++;
			return (0);
		}
	}
	return (1);
}

int	create_thread(t_philo *philo)
{
	int	i;

	i = -1;
	philo->input->time_start = timestamp();
	while (++i < philo->input->num)
	{
		philo[i].t_eat = timestamp();
		pthread_create(&philo[i].thread, NULL, routine, &philo[i]);
		pthread_detach(philo[i].thread);
	}
	check_die(philo);
	return (0);
}

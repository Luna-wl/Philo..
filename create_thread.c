/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:50:00 by y wluedara        #+#    #+#             */
/*   Updated: 2023/04/25 22:48:59 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_die(t_philo *philo)
{
	int	i;

	usleep(1000);
	while (1)
	{
		i = -1;
		while (++i < philo->input->num)
		{
			pthread_mutex_lock(&philo->input->lock);
			if (timestamp() - philo[i].t_eat >= philo->input->die_time)
			{
				// printf("id = %d time = %ld\n", philo[i].id, timestamp() - philo[i].t_eat);
				pim_philo(philo, philo[i].id, RED"died ―(x_x)→", 1);
				return ;
			}
			if (philo->input->eat_full == philo->input->num)
			{
				return ;
			}
			pthread_mutex_unlock(&philo->input->lock);
		}
	}
}

int	check_eat(t_philo *philo)
{
	if (philo->input->must_eat == -1)
		return (1);
	else
	{
		if (philo->eat_cont == philo->input->must_eat)
		{
			philo->input->eat_full++;
			return (0);
		}
	}
	return (1);
}

void	*routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	philo->t_eat = timestamp();
	if (philo->id % 2 == 0)
		my_sleep(philo->input->eat_time);
	while (1)
	{
		if (philo_take_fork(philo) == -1)
			return (NULL);
		if (philo_eat(philo))
			return (NULL);
		philo_sleep_think(philo);
	}
	return (NULL);
}

int	create_thread(t_philo *philo)
{
	int	i;

	i = -1;
	philo->input->time_start = timestamp();
	while (++i < philo->input->num)
	{
		pthread_create(&philo[i].thread, NULL, routine, &philo[i]);
	}
	check_die(philo);
	i = -1;
	while (++i < philo->input->num)
	{
		pthread_detach(philo[i].thread);
	}
	return (0);
}

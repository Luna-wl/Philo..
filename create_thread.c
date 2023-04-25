/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Create 7d: 2023/04/11 16:50:35 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/19 20:47:28 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_die(t_philo *philo)
{
	int	i;

	while (check_eat(philo))
	{
		i = -1;
		while (++i < philo->input->num)
		{
			pthread_mutex_lock(&philo->input->lock);
			if (philo->input->num == 1)
			{
				my_sleep(philo->input->die_time);
				pim_philo(philo, philo->id, RED"died ―(x_x)→", 1);
				return ;
			}
			if (timestamp() - philo->t_eat >= philo->input->die_time)
			{
				// printf("id = %d -> die_t = %ld\n", philo->id, timestamp() - philo->t_eat);
				pim_philo(philo, philo->id, RED"died ―(x_x)→", 1);
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
			return (0);
	}
	return (1);
}

void	*routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	if (philo->id % 2 == 0)
		my_sleep(philo->input->eat_time);
	philo->t_eat = philo->input->time_start;
	while (check_eat(philo))
	{
		if (philo_take_fork(philo) == -1)
			return (NULL);
		philo_eat(philo);
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

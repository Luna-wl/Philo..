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

	while (1)
	{
		i = -1;
		while (++i < philo->input->num)
		{
			pthread_mutex_lock(&philo->input->lock);
			if (timestamp() - philo->t_eat >= philo->input->die_time)
			{
				pim_philo(philo, philo->id, RED"died ―(x_x)→");
				philo->input->die = 1;
			}
			pthread_mutex_unlock(&philo->input->lock);
			usleep(100);
		}
		if (philo->input->die == 1)
			break ;
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
		if (philo->input->die == 1)
			return (NULL);
		if (philo_take_fork(philo) == -1)
			return (NULL);
		if (philo->input->die == 1)
			return (NULL);
		philo_eat(philo);
		if (philo->input->die == 1)
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
		pthread_join(philo[i].thread, NULL);
	}
	return (0);
}

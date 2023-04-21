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

void	kaboom_mutex(t_philo *philo, t_input *input)
{
	int	i;

	i = -1;
	while (++i < philo->input->num)
	{
		pthread_mutex_destroy(&philo->fork[i]);
	}
	pthread_mutex_destroy(&input->print);
	pthread_mutex_destroy(&input->lock);
}

int	check_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->input->lock);
	// if (philo->t_eat)
	pim_philo(philo, philo->id, "died ―(x_x)→");
	pthread_mutex_unlock(&philo->input->lock);
	return (0);
}

int	check_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->input->lock);
	if (philo->input->must_eat != -1)
	{
		if (philo->eat_cont == philo->input->must_eat)
			return (0);
	}
	else
	{
		if (philo->eat_cont == philo->input->must_eat)
			return (0);
	}
	pthread_mutex_unlock(&philo->input->lock);
	return (1);
}

void	*routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	if (philo->id % 2 == 0)
		my_sleep(philo->input->eat_time);
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

	i = 0;
	philo->input->time_start = timestamp();
	while (i < philo->input->num)
	{
		pthread_create(&philo[i].thread, NULL, routine, &philo[i]);
		i++;
		// usleep(500);
	}
	i = 0;
	while (i < philo->input->num)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	return (0);
}

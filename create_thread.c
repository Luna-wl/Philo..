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
	pthread_mutex_destroy(&input->lock);
	pthread_mutex_destroy(&input->print);
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
		if (check_die(philo))
			return (0);
	}
	pthread_mutex_unlock(&philo->input->lock);
	return (1);
}

void	*routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	// if (!(philo->id & 1))
	// 	usleep(philo->input->eat_time * (philo->input->num));
	// while (!(check_eat(philo)) || check_die(philo))
	while (1)
	{
		if (philo_take_fork(philo) == -1)
			return (NULL);
		philo_eat(philo);
		philo_sleep_think(philo);
		// usleep(200);
	}
	return (NULL);
}

int	create_thread(t_philo *philo)
{
	int	i;

	// i = -1;
	i = 0;
	philo->input->time_start = timestamp();
	printf("start = %ld\n", philo->input->time_start);
	// while (++i < philo->input->num)
	while (i < philo->input->num)
	{
		if (pthread_create(&philo[i].thread, NULL, routine, &philo[i]))
			return (0);
		i += 2;
		if (philo->id >= philo->input->num && !(philo->id & 1))
			i = 1;
		usleep(100);
	}
	return (0);
}

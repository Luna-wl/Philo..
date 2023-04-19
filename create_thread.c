/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:50:35 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/19 12:24:41 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	philo_sleep(t_philo *philo)
// {
	
// }

void	philo_eat(t_philo *philo)
{
	int	i;

	i = philo->id;
	printf("philo[i].id = %d\n", philo->id);
	pthread_mutex_lock();
	pim_philo(philo, philo->id, TAKE_FORKS);
	if (philo[i].l_fork >= philo->input->num)
	{
		pthread_mutex_lock();
		pim_philo(philo, philo->id, TAKE_FORKS);
	}
	else
	{
		pthread_mutex_lock(&philo[philo[i].l_fork].fork);
		pim_philo(philo, philo->id, TAKE_FORKS);
	}
	philo->t_eat = timestamp();
	pthread_mutex_unlock();
	pthread_mutex_unlock(&philo[philo[i].l_fork].fork);
}

void	*routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	while (1)
	{
		philo_eat(philo);
	}
	return (0);
}

int	create_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->input->num)
	{
		if (pthread_create(&philo[i].thread, NULL, routine, &philo[i]))
			return (0);
		if (pthread_detach(philo[i].thread))
			return (0);
		sleep(200);
		i += 2;
		if (i >= philo->input->num)
			i = 1;
	}
	return (0);
}

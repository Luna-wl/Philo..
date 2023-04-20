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

int	check_die(t_philo *philo)
{
	if (philo->input->die)
		return (0);
	return (1);
}

void	*routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	while (!philo->input->die)
	{
		philo_eat(philo);
		pim_philo(philo, philo->id, CYN"is sleeping (=_= zzzz)");
		// philo_sleep_think(philo);
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
		if (pthread_create(&philo[i].thread, NULL, routine, &philo[i]))
			return (0);
		usleep(100);
		i += 2;
		if (i >= philo->input->num && i % 2 == 0)
			i = 1;
	}
	return (0);
}

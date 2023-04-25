/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:05:27 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/26 01:47:47 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep_think(t_philo *philo)
{
	pim_philo(philo, philo->id, CYN"is sleeping (=_= zzzz)", 0);
	my_sleep(philo->input->sleep_time);
	pim_philo(philo, philo->id, MAG"is thinking (º﹃ º )", 0);
}

int	philo_eat(t_philo *philo)
{
	pim_philo(philo, philo->id, GRN"is eating ૮₍ ˶•⤙•˶ ₎ა", 0);
	my_sleep(philo->input->eat_time);
	philo->t_eat = timestamp();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->input->fork[philo->r_fork]);
	pthread_mutex_unlock(&philo->input->fork[philo->l_fork]);
	if (!check_eat(philo))
		return (1);
	return (0);
}

int	philo_take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->input->fork[philo->r_fork]);
	pim_philo(philo, philo->id, BLU"has taken a fork ( ˘▽˘)っ Y", 0);
	if (philo->input->die == 1)
		return (-1);
	pthread_mutex_lock(&philo->input->fork[philo->l_fork]);
	pim_philo(philo, philo->id, BLU"has taken a fork Y _(・_・ )", 0);
	return (0);
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
		usleep(200);
	}
	return (NULL);
}

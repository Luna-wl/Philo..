/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:05:27 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/24 22:14:04 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep_think(t_philo *philo)
{
	pim_philo(philo, philo->id, CYN"is sleeping (=_= zzzz)");
	my_sleep(philo->input->sleep_time);
	pim_philo(philo, philo->id, MAG"is thinking (º﹃ º )");
}

void	philo_eat(t_philo *philo)
{
	pim_philo(philo, philo->id, GRN"is eating ૮₍ ˶•⤙•˶ ₎ა");
	pthread_mutex_lock(&philo->input->lock);
	philo->t_eat = timestamp();
	philo->eat_cont++;
	pthread_mutex_unlock(&philo->input->lock);
	my_sleep(philo->input->eat_time);
	pthread_mutex_unlock(&philo->input->fork[philo->r_fork]);
	pthread_mutex_unlock(&philo->input->fork[philo->l_fork]);
}

int	philo_take_fork(t_philo *philo)
{
	if (philo->input->num == 1)
	{
		pim_philo(philo, philo->id, BLU"has taken a fork ( ˘▽˘)っ Y");
		return (-1);
	}
	else
	{
		pthread_mutex_lock(&philo->input->fork[philo->r_fork]);
		pim_philo(philo, philo->id, BLU"has taken a fork ( ˘▽˘)っ Y");
		if (philo->input->die == 1)
			return (-1);
		pthread_mutex_lock(&philo->input->fork[philo->l_fork]);
		pim_philo(philo, philo->id, BLU"has taken a fork Y _(・_・ )");
	}
	return (0);
}

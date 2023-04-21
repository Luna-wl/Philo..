/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:05:27 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/21 14:09:44 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->input->lock);
	pim_philo(philo, philo->id, CYN"is sleeping (=_= zzzz)");
	my_sleep(philo->input->sleep_time);
	pthread_mutex_unlock(&philo->input->lock);
	pim_philo(philo, philo->id, MAG"is thinking (º﹃ º )");
}

void	philo_eat(t_philo *philo)
{
	pim_philo(philo, philo->id, GRN"is eating ૮₍ ˶•⤙•˶ ₎ა");
	pthread_mutex_lock(&philo->input->lock);
	philo->t_eat = timestamp();
	philo->eat_cont++;
	// printf("philo->eat_cont = %d\n", philo->eat_cont);
	pthread_mutex_unlock(&philo->input->lock);
	my_sleep(philo->input->eat_time);
	pthread_mutex_unlock(&philo->fork[philo->r_fork]);
	pthread_mutex_unlock(&philo->fork[philo->l_fork]);
}


int	philo_take_fork(t_philo *philo)
{
	if (philo->input->num == 1)
	{
		pthread_mutex_lock(&philo->fork[philo->r_fork]);
		pim_philo(philo, philo->id, BLU"has taken a fork ( ˘▽˘)っ Y");
		pthread_mutex_unlock(&philo->fork[philo->r_fork]);
		pim_philo(philo, philo->id, RED"died ―(x_x)→"RESET);
		return (-1);
	}
	else
	{
		pthread_mutex_lock(&philo->fork[philo->r_fork]);
		pim_philo(philo, philo->id, BLU"has taken a fork ( ˘▽˘)っ Y");
		pthread_mutex_lock(&philo->fork[philo->l_fork]);
		pim_philo(philo, philo->id, BLU"has taken a fork Y _(・_・ )");
	}
	return (0);
}

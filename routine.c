/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:05:27 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/21 14:46:23 by wluedara         ###   ########.fr       */
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
	// printf("r = %p\n", &philo->fork[philo->r_fork]);
	// printf("l = %p\n", &philo->fork[philo->l_fork]);
	pthread_mutex_lock(&philo->input->lock);
	pim_philo(philo, philo->id, GRN"is eating ૮₍ ˶•⤙•˶ ₎ა");
	philo->t_eat = timestamp();
	philo->eat_cont++;
	pthread_mutex_unlock(&philo->input->lock);
	my_sleep(philo->input->eat_time);
	// pim_philo(philo, philo->id, "return fork");
	// pim_philo(philo, philo->id, "return fork");
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_unlock(philo->fork_l);
}

int	philo_take_fork(t_philo *philo)
{
	if (philo->input->num == 1)
	{
		pthread_mutex_lock(philo->fork_r);
		pim_philo(philo, philo->id, BLU"has taken a fork ( ˘▽˘)っ Y");
		pthread_mutex_unlock(philo->fork_r);
		pim_philo(philo, philo->id, RED"died ―(x_x)→"RESET);
		return (-1);
	}
	else
	{
		// printf("r[%d] fork = %p\n"RESET, philo->r_fork, &philo->fork);
		// printf("l[%d] fork = %p\n"RESET, philo->l_fork, &philo->fork);
		pthread_mutex_lock(philo->fork_r);
		pim_philo(philo, philo->id, BLU"has taken a fork ( ˘▽˘)っ Y");
		pthread_mutex_lock(philo->fork_l);
		pim_philo(philo, philo->id, BLU"has taken a fork Y _(・_・ )");
	}
	return (0);
}

// int	philo_take_fork(t_philo *philo)
// {
// 	if (philo->input->num == 1)
// 	{
// 		pthread_mutex_lock(&philo->fork[philo->r_fork]);
// 		pim_philo(philo, philo->id, BLU"has taken a fork ( ˘▽˘)っ Y");
// 		pthread_mutex_unlock(&philo->fork[philo->r_fork]);
// 		pim_philo(philo, philo->id, RED"died ―(x_x)→"RESET);
// 		return (-1);
// 	}
// 	else
// 	{
// 		printf("r[%d] fork = %p\n"RESET, philo->r_fork, &philo->fork[philo->r_fork]);
// 		printf("l[%d] fork = %p\n"RESET, philo->l_fork, &philo->fork[philo->l_fork]);
// 		pthread_mutex_lock(&philo->fork[philo->r_fork]);
// 		pim_philo(philo, philo->id, BLU"has taken a fork ( ˘▽˘)っ Y");
// 		pthread_mutex_lock(&philo->fork[philo->l_fork]);
// 		pim_philo(philo, philo->id, BLU"has taken a fork Y _(・_・ )");
// 	}
// 	return (0);
// }

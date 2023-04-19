/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:05:27 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/19 20:21:33 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep_think(t_philo *philo)
{
	pim_philo(philo, philo->id, CYN"is sleeping");
	pim_philo(philo, philo->id, "is thinking");
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork[philo->r_fork]);
	pim_philo(philo, philo->id, BLU"has taken a fork");
	pthread_mutex_lock(&philo->fork[philo->l_fork]);
	pim_philo(philo, philo->id, BLU"has taken a fork");
	pthread_mutex_lock(&philo->input->lock);
	philo->t_eat = timestamp();
	pim_philo(philo, philo->id, GRN"is eating");
	pthread_mutex_unlock(&philo->input->lock);
	my_sleep(philo->t_eat);
	pthread_mutex_unlock(&philo->fork[philo->r_fork]);
	pthread_mutex_unlock(&philo->fork[philo->l_fork]);
}

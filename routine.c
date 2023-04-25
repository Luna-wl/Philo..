/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:05:27 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/25 16:00:37 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep_think(t_philo *philo)
{
	pim_philo(philo, philo->id, CYN"is sleeping (=_= zzzz)", 0);
	my_sleep(philo->input->sleep_time);
	pim_philo(philo, philo->id, MAG"is thinking (º﹃ º )", 0);
}

void	philo_eat(t_philo *philo)
{
	pim_philo(philo, philo->id, GRN"is eating ૮₍ ˶•⤙•˶ ₎ა", 0);
	pthread_mutex_lock(&philo->input->lock);
	philo->t_eat = timestamp();
	// printf("eat_t in rountine = %ld\n", philo->t_eat);
	philo->eat_cont++;
	my_sleep(philo->input->eat_time);
	// printf("[%d]eat_cont = %d\n", philo->id, philo->eat_cont);
	pthread_mutex_unlock(&philo->input->lock);
	pthread_mutex_unlock(&philo->input->fork[philo->r_fork]);
	pthread_mutex_unlock(&philo->input->fork[philo->l_fork]);
}

int	philo_take_fork(t_philo *philo)
{
	if (philo->input->num == 1)
	{
		pim_philo(philo, philo->id, BLU"has taken a fork ( ˘▽˘)っ Y", 0);
		return (-1);
	}
	else
	{
		pthread_mutex_lock(&philo->input->fork[philo->r_fork]);
		pim_philo(philo, philo->id, BLU"has taken a fork ( ˘▽˘)っ Y", 0);
		if (philo->input->die == 1)
			return (-1);
		pthread_mutex_lock(&philo->input->fork[philo->l_fork]);
		pim_philo(philo, philo->id, BLU"has taken a fork Y _(・_・ )", 0);
	}
	return (0);
}

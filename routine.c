/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:05:27 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/20 17:35:38 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep_think(t_input *input)
{
	pthread_mutex_lock(&input->lock);
	pim_philo(input, input->philo->id, CYN"is sleeping (=_= zzzz)");
	my_sleep(input->sleep_time);
	// usleep(philo->input->sleep_time);
	pthread_mutex_unlock(&input->lock);
	pim_philo(input, input->philo->id, MAG"is thinking (º﹃ º )");
}

void	philo_eat(t_input *input)
{
	pthread_mutex_lock(&input->lock);
	pim_philo(input, input->philo->id, GRN"is eating ૮₍ ˶•⤙•˶ ₎ა");
	input->philo->t_eat = timestamp();
	input->philo->eat_cont++;
	// printf("philo->eat_cont = %d\n", philo->eat_cont);
	// printf("philo->t_eat = %ld\n", philo->t_eat);
	pthread_mutex_unlock(&input->lock);
	// my_sleep(philo->t_eat);
	// usleep(philo->input->eat_time);
	pthread_mutex_unlock(&input->fork[input->philo->r_fork]);
	pthread_mutex_unlock(&input->fork[input->philo->l_fork]);
}

int	philo_take_fork(t_input *input)
{
	if (input->num == 1)
	{
		pthread_mutex_lock(&input->fork[input->philo->r_fork]);
		pim_philo(input, input->philo->id, BLU"has taken a fork ( ˘▽˘)っ Y");
		pthread_mutex_unlock(&input->fork[input->philo->r_fork]);
		pim_philo(input, input->philo->id, RED"died ―(x_x)→"RESET);
		return (-1);
	}
	else
	{
		pthread_mutex_lock(&input->fork[input->philo->r_fork]);
		pim_philo(input, input->philo->id, BLU"has taken a fork ( ˘▽˘)っ Y");
		pthread_mutex_lock(&input->fork[input->philo->l_fork]);
		pim_philo(input, input->philo->id, BLU"has taken a fork Y _(・_・ )");
	}
	return (0);
}

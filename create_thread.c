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

// void	kaboom_mutex(t_philo *philo, t_input *input)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < philo->input->num)
// 	{
// 		pthread_mutex_destroy(&philo->fork[i]);
// 	}
// 	pthread_mutex_destroy(&input->lock);
// 	pthread_mutex_destroy(&input->print);
// }

int	check_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->input->lock);
	// if (philo->t_eat)
	pim_philo(philo, philo->id, "died ―(x_x)→");
	pthread_mutex_unlock(&philo->input->lock);
	return (0);
}

// int	check_eat(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->input->lock);
// 	if (philo->input->must_eat != -1)
// 	{
// 		if (philo->eat_cont == philo->input->must_eat)
// 			return (0);
// 	}
// 	else
// 	{
// 		if (check_die(philo))
// 			return (0);
// 	}
// 	pthread_mutex_unlock(&philo->input->lock);
// 	return (1);
// }

void	*routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	// while (!(check_eat(philo)) || check_die(philo))
	if (philo->id % 2 == 0)
		my_sleep(philo->input->eat_time);
	while (1)
	{
		if (philo_take_fork(philo) == -1)
			return (NULL);
		// // printf("before eat\n");
		philo_eat(philo);
		// // printf("after eat\n");
		philo_sleep_think(philo);
		// usleep(500);
	}
	return (NULL);
}

int	create_thread(t_philo *philo)
{
	int	i;

	// i = -1;
	i = 0;
	philo->input->time_start = timestamp();
	// printf("start = %ld\n", philo->input->time_start);
	// while (++i < philo->input->num)
	while (i < philo->input->num)
	{
		pthread_create(&philo[i].thread, NULL, routine, &philo[i]);
		i++;
		usleep(500);
	}
	i = -1;
	while (++i < philo->input->num)
	{
		pthread_join(philo[i].thread, NULL);
	}
	return (0);
}

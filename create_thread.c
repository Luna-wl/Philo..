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

void	kaboom_mutex(t_input *input)
{
	int	i;

	i = -1;
	while (++i < input->num)
	{
		pthread_mutex_destroy(&input->fork[i]);
	}
	pthread_mutex_destroy(&input->lock);
	pthread_mutex_destroy(&input->print);
}

int	check_die(t_input *input)
{
	pthread_mutex_lock(&input->lock);
	// if (philo->t_eat)
	pim_philo(input, input->philo->id, "died ―(x_x)→");
	pthread_mutex_unlock(&input->lock);
	return (0);
}

int	check_eat(t_input *input)
{
	pthread_mutex_lock(&input->lock);
	if (input->must_eat != -1)
	{
		if (input->philo->eat_cont == input->must_eat)
			return (0);
	}
	pthread_mutex_unlock(&input->lock);
	return (1);
}

void	*routine(void *input)
{
	t_input	*data;

	data = (t_input *)input;
	// if (!(philo->id & 1))
	// 	usleep(philo->input->eat_time * (philo->input->num));
	printf("%d\n", data->philo->r_fork);
	while (1)
	{
		// if (philo_take_fork(data) == -1)
		// 	return (NULL);
		// philo_eat(data);
		// philo_sleep_think(data);
		// usleep(200);
	}
	return (NULL);
}

int	create_thread(t_input *input)
{
	int	i;

	// i = -1;
	i = 0;
	input->time_start = timestamp();
	// printf("start = %ld\n", philo->input->time_start);
	// while (++i < philo->input->num)
	while (i < input->num)
	{
		if (pthread_create(&input->philo[i].thread, NULL, routine, &input->philo[i]))
			return (0);
		if (pthread_detach(input->philo[i].thread))
			return (0);
		i += 2;
		if (!(input->philo[i].id & 1))
			i = 1;
		usleep(500);
	}
	return (0);
}

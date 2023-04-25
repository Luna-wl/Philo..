/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:57:38 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/24 22:34:00 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_sleep(long time)
{
	long	time_n;

	time_n = timestamp();
	while (timestamp() - time_n < time)
	{
		usleep(1);
	}
}

long	timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	pim_philo(t_philo *philo, int id, char *msg, int die)
{
	pthread_mutex_lock(&philo->input->print);
	printf(RED"%ldms ", timestamp() - philo->input->time_start);
	printf(YEL"%d "RESET, id);
	printf("%s\n"RESET, msg);
	if (die == 1)
	{
		return ;
	}
	pthread_mutex_unlock(&philo->input->print);
}

void	kaboom_mutex(t_philo *philo, t_input *input)
{
	int	i;

	i = -1;
	while (++i < philo->input->num)
	{
		pthread_mutex_destroy(&philo->input->fork[i]);
	}
	pthread_mutex_destroy(&input->lock);
	pthread_mutex_destroy(&input->print);
	free(philo);
}

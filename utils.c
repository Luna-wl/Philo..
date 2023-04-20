/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:57:38 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/20 18:04:39 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_sleep(long time)
{
	long	time_n;

	time_n = timestamp();
	while (timestamp() - time_n < time)
	{
		if (timestamp() - time_n >= time)
			break;
		usleep(1);
	}
}

long	timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	pim_philo(t_philo *philo, int id, char *msg)
{
	// if (!check_die(philo))
	// 	return ;
	pthread_mutex_lock(&philo->input->print);
	printf(RED"%ld ", timestamp() - philo->input->time_start);
	printf(YEL"%d "RESET, id);
	printf("%s\n"RESET, msg);
	pthread_mutex_unlock(&philo->input->print);
}

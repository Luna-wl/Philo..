/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:57:38 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/18 21:41:56 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	pim_philo(t_philo *philo, int id, char *msg)
{
	pthread_mutex_lock(&philo->input->print);
	printf(RED"%ld ", timestamp() - philo->input->time_start);
	printf(YEL"%d "RESET, id);
	printf(GRN"%s\n"RESET, msg);
	pthread_mutex_unlock(&philo->input->print);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:57:38 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/12 16:20:53 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	pim_philo(long time, int id, char *msg)
{
	printf("%ld", time);
	printf("%d", id);
	if (msg == TAKE_FORKS)
		printf(GRN"%s\n"RESET, msg);
	else if (msg == THINKING)
		printf(YEL"%s\n"RESET, msg);
	else if (msg == SLEEPING)
		printf(CYN"%s\n"RESET, msg);
	else if (msg == EATING)
		printf(MAG"%s\n"RESET, msg);
	else if (msg == DIED)
		printf(BLU"%s\n"RESET, msg);
}

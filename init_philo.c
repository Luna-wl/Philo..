/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:42:08 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/12 17:09:21 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*create_philo(t_input *input)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo) * input->num);
	if (!philo)
		return (0);
	i = -1;
	while (++i < input->num)
	{
		philo[i].id = i + 1;
		philo[i].t_start = 0;
		philo[i].eat_cont = 0;
		philo[i].input = input;
		if (pthread_mutex_init(&philo[i].fork, NULL) != 0)
			printf(MAG"Error at init mutex\n"RESET);
	}
	return (philo);
}

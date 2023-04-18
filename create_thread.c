/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:50:35 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/12 17:08:38 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philosopher)
{
	
}

void	create_thread(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->input->num)
	{
		pthread_create(&philo[i].thread, NULL, routine, NULL);
		
	}
}

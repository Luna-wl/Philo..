/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 23:00:33 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/25 22:30:04 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_input	input;
	t_philo	*philo;

	if (ac < 5 || ac > 6)
	{
		pim_error("You put the wrong input", 1);
		return (0);
	}
	if (!check_argv(&av[1]))
	{
		pim_error("This is not what I want!", 0);
		return (0);
	}
	init_philo_input(&input, &av[1]);
	philo = create_philo(&input);
	create_thread(philo);
	kaboom_mutex(philo, &input);
	return (0);
}

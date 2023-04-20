/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 23:00:33 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/20 17:45:53 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_input	input;
	// t_philo	*philo;

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
	// philo = create_philo(&input);
	create_philo(&input);
	// test(&input);
	if (!create_thread(&input))
		return (0);
	// kaboom_mutex(&input);
	return (0);
}

/*
./philo 20 400 200 200

- number_of_philosophers: The number of philosophers and also the number of forks.

- time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die 
milliseconds since the beginning of their last meal or the beginning of the simulation, 
they die.

- time_to_eat (in milliseconds): The time it takes for a philosopher to eat. During that 
time, they will need to hold two forks.

- time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.

- number_of_times_each_philosopher_must_eat (optional argument): If all philosophers
 have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. 
 If not specified, the simulation stops when a philosopher dies.
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 23:00:33 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/04 19:11:42 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_input	input;
	t_philo	*philo;

	if (ac < 5 || ac > 6)
	{
		ft_putstr_fd(RED"You put the wrong input\n"RESET, 1);
		return (0);
	}
	if (my_atoi(av[1]) <= 0)
	{
		ft_putstr_fd(RED"Philo must have at least 1, okay?\n"RESET, 1);
		return (0);
	}
	if (!check_argv(&av[1]))
		ft_putstr_fd(BLU"This is not what I want!\n"RESET, 1);
	init_philo_input(&input, &av[1]);
	philo = create_philo(&input);
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
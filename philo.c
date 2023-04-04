/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 23:00:33 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/04 16:27:39 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_argv(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		if (my_atoi(av[i]) > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

void	init_philo_input(t_input *philo, char **s)
{
	philo->num = (int)my_atoi(s[0]);
	philo->die_time = (u_int64_t)my_atoi(s[1]);
	philo->eat_time = (u_int64_t)my_atoi(s[2]);
	philo->sleep_time = (u_int64_t)my_atoi(s[3]);
	if (s[4])
		philo->must_eat = (int)my_atoi(s[4]);
	else
		philo->must_eat = -1;
	
}

void	test(t_input *philo)
{
	printf(BLU"philo->num = %d\n", philo->num);
	printf("philo->die = %llu\n", philo->die_time);
	printf("philo->eat = %llu\n", philo->eat_time);
	printf("philo->sleep = %llu\n", philo->sleep_time);
	printf("philo->must_eat = %d\n"RESET, philo->must_eat);
}

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
	}
	return (philo);
}

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
	// for (int j = 0; philo[j].id; j++)
	// 	printf(YEL"philo[%d] = %d\n"RESET, j, philo[j].id);
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
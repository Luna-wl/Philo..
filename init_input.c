/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:41:15 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/04 16:42:36 by wluedara         ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:41:15 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/12 16:30:09 by wluedara         ###   ########.fr       */
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
		if (my_atoi(av[i]) <= 0 || my_atoi(av[i]) > 2147483647 \
		|| my_atoi(av[0]) > 200)
			return (0);
		i++;
	}
	return (1);
}

void	init_philo_input(t_input *data, char **s)
{
	data->num = (int)my_atoi(s[0]);
	data->die_time = my_atoi(s[1]);
	data->eat_time = my_atoi(s[2]);
	data->sleep_time = my_atoi(s[3]);
	if (s[4])
		data->must_eat = (int)my_atoi(s[4]);
	else
		data->must_eat = -1;
	if (pthread_mutex_init(&data->print, NULL) != 0)
		printf(MAG"Error at init mutex\n"RESET);
}

void	test(t_input *philo)
{
	printf(BLU"philo->num = %d\n", philo->num);
	printf("philo->die = %ld\n", philo->die_time);
	printf("philo->eat = %ld\n", philo->eat_time);
	printf("philo->sleep = %ld\n", philo->sleep_time);
	printf("philo->must_eat = %d\n"RESET, philo->must_eat);
}

void	test2(t_philo *philo)
{
	printf(BLU"philo->num = %d\n", philo->input->num);
	printf("philo->die = %ld\n", philo->input->die_time);
	printf("philo->eat = %ld\n", philo->input->eat_time);
	printf("philo->sleep = %ld\n", philo->input->sleep_time);
	printf("philo->must_eat = %d\n"RESET, philo->input->must_eat);
}

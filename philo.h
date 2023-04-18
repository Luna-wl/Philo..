/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 23:00:27 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/05 17:08:12 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "colours.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <pthread.h>
# include <sys/time.h>
# include <memory.h>

# define TAKE_FORKS "has taken a fork"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define DIED "died"

typedef struct s_input
{
	int				num;
	u_int64_t		die_time;
	u_int64_t		eat_time;
	u_int64_t		sleep_time;
	int				must_eat;
}	t_input;

typedef struct s_philo
{
	struct t_input	*input;
	pthread_t		thread;
	int				id;
	int				eat_cont;
	u_int64_t		t_die;
	pthread_mutex_t	lock;
}	t_philo;

// tool.c
int		ft_strlen(char *s);
int		is_space(char str);
long	my_atoi(char *str);
void	ft_putstr_fd(char *s, int fd);
// philo.c
int		check_argv(char **av);
void	init_philo_input(t_input *philo, char **s);
void	test(t_input *philo);
t_philo	*create_philo(t_input *input);

#endif
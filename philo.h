/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 23:00:27 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/19 12:24:18 by wluedara         ###   ########.fr       */
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
	long			die_time;
	long			eat_time;
	long			sleep_time;
	int				must_eat;
	long			time_start;
	pthread_mutex_t	print;
	struct t_philo			*philo;
}	t_input;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eat_cont;
	long			t_eat;
	int				die;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	l_fork;
	t_input			*input;
}	t_philo;

// tool
int		ft_strlen(char *s);
int		is_space(char str);
long	my_atoi(char *str);
void	ft_putstr_fd(char *s, int fd);
void	pim_error(char *s, int m);
// utils
long	timestamp(void);
void	pim_philo(t_philo *philo, int id, char *msg);
// philo
int		check_argv(char **av);
void	init_philo_input(t_input *philo, char **s);
t_philo	*create_philo(t_input *input);
// thread
int		create_thread(t_philo *philo);
void	*routine(void *philosopher);
void	philo_eat(t_philo *philo);

// int		philo_sleep(t_philo *philo);

void	test(t_input *philo);
void	test2(t_philo *philo);

#endif
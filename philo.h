/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 23:00:27 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/24 20:30:54 by wluedara         ###   ########.fr       */
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

typedef struct s_input
{
	int				num;
	long			die_time;
	long			eat_time;
	long			sleep_time;
	int				must_eat;
	long			time_start;
	int				die;
	pthread_mutex_t	print;
	pthread_mutex_t	lock;
	pthread_mutex_t	*fork;
}	t_input;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eat_cont;
	long			t_eat;
	int				r_fork;
	int				l_fork;
	long			take_fork;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;
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
int		philo_take_fork(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep_think(t_philo *philo);
// utils thread
void	my_sleep(long time);
void	check_die(t_philo *philo);
void	kaboom_mutex(t_philo *philo, t_input *input);

// void	test(t_input *philo);
void	test2(t_philo *philo);

#endif
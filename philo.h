/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 23:00:27 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/03 16:33:31 by wluedara         ###   ########.fr       */
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

typedef struct s_philo
{
	pthread_t		philo;
	int				index;
}	t_philo;

// tool.c
int		ft_strlen(char *s);
int		is_space(char str);
long	my_atoi(char *str);
void	ft_putstr_fd(char *s, int fd);
// philo.c
int		check_argv(char **av);

#endif
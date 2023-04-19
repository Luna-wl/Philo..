/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:26:46 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/18 21:21:34 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
}

int	is_space(char str)
{
	if (str == ' ' || str == '\f' || str == '\n' || str == '\r'
		|| str == '\t' || str == '\v' || str == '\t')
		return (1);
	return (0);
}

long	my_atoi(char *str)
{
	long	num;
	long	minus;

	num = 0;
	minus = 1;
	while (is_space(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	if (*str == '0')
	{
		str++;
		if (*str >= '0' && *str <= '9')
			return (2147483648);
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num * minus);
}

void	pim_error(char *s, int m)
{
	if (m == 1)
	{
		printf(RED" ---------------------------\n");
		printf("|  %s  |\n",s);
		printf(" ---------------------------\n"RESET);
	}
	else
	{
		printf(BLU" ---------------------------\n");
		printf("|  %s |\n",s);
		printf(" ---------------------------\n"RESET);
	}
}

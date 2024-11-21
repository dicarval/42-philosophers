/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:16:18 by dicarval          #+#    #+#             */
/*   Updated: 2024/11/21 16:05:23 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

unsigned long	ft_atoul(const char *str)
{
	unsigned long	res;
	unsigned int	i;

	res = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			error_hand(2);
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res);
}

void	print_message(int id, int message_code)
{
	struct timeval	tv;
	int				ret;
	unsigned long	mil_sec;

	pthread_mutex_lock(&(data()->message));
	ret = gettimeofday(&tv, NULL);
	mil_sec = tv.tv_sec * 1000L + tv.tv_usec / 1000;
	if (ret == 0 && message_code == 1 && data()->alive)
		printf("%ld %d has taken a fork\n", mil_sec, id);
	else if (ret == 0 && message_code == 2 && data()->alive)
		printf("%ld %d is eating\n", mil_sec, id);
	else if (ret == 0 && message_code == 3 && data()->alive)
		printf("%ld %d is sleeping\n", mil_sec, id);
	else if (ret == 0 && message_code == 4 && data()->alive)
		printf("%ld %d is thinking\n", mil_sec, id);
	else if (ret == 0 && message_code == 5)
		printf("%ld %d died\n", mil_sec, id);
	else if(ret == 1)
		printf("gettimeofday failed\n");
	pthread_mutex_unlock(&(data()->message));
}

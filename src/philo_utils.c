/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:16:18 by dicarval          #+#    #+#             */
/*   Updated: 2024/11/25 17:32:05 by dicarval         ###   ########.fr       */
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

unsigned long	get_current_time(void)
{
	struct timeval	time;

	pthread_mutex_lock(&(mutex()->curr_time));
	if (gettimeofday(&time, NULL) == -1)
	{
		pthread_mutex_unlock(&(mutex()->curr_time));
		return (0);
	}
	pthread_mutex_unlock(&(mutex()->curr_time));
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_message(int id, int message_code)
{
	unsigned long	timestamp;

	pthread_mutex_lock(&(mutex()->message));
	timestamp = get_current_time();
	//pthread_mutex_lock(&mutex()->var_uint);
	if (timestamp == 0)
		printf("gettimeofday failed\n");
	else if (message_code == 1 && data()->alive)
		printf("%ld %d has taken a fork\n", timestamp, id);
	else if (message_code == 2 && data()->alive)
		printf("%ld %d is eating\n", timestamp, id);
	else if (message_code == 3 && data()->alive)
		printf("%ld %d is sleeping\n", timestamp, id);
	else if (message_code == 4 && data()->alive)
		printf("%ld %d is thinking\n", timestamp, id);
	else if (message_code == 5)
		printf("%ld %d died\n", timestamp, id);
	//pthread_mutex_unlock(&mutex()->var_uint);
	pthread_mutex_unlock(&(mutex()->message));
}

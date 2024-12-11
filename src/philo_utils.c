/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:16:18 by dicarval          #+#    #+#             */
/*   Updated: 2024/12/11 10:21:57 by dicarval         ###   ########.fr       */
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
			error_hand(INVAL_ARG);
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
	unsigned long	current_time;

	pthread_mutex_lock(&(mutex()->curr_time));
	if (gettimeofday(&time, NULL) == -1)
	{
		pthread_mutex_unlock(&(mutex()->curr_time));
		error_hand(GET_TIME_DAY);
	}
	current_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	pthread_mutex_unlock(&(mutex()->curr_time));
	return (current_time);
}

void	print_message(int id, int message_code)
{
	unsigned long	timestamp;

	pthread_mutex_lock(&(mutex()->message));
	timestamp = get_current_time() - data()->start_time;
	if (message_code == FORK && (alive_protcl()))
		printf("%ld %d has taken a fork\n", timestamp, id + 1);
	else if (message_code == EAT && (alive_protcl()))
		printf("%ld %d is eating\n", timestamp, id + 1);
	else if (message_code == SLEEP && (alive_protcl()))
		printf("%ld %d is sleeping\n", timestamp, id + 1);
	else if (message_code == THINK && (alive_protcl()))
		printf("%ld %d is thinking\n", timestamp, id + 1);
	else if (message_code == DIE)
		printf("%ld %d died\n", timestamp, id + 1);
	else if (message_code == EAT_0)
		printf("Impossible any philosopher to eat.\n\
number_of_times_each_philosopher_must_eat = 0.\n");
	pthread_mutex_unlock(&(mutex()->message));
}

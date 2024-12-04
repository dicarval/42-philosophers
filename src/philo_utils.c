/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:16:18 by dicarval          #+#    #+#             */
/*   Updated: 2024/12/04 10:32:55 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

unsigned long long	ft_atoull(const char *str)
{
	unsigned long long	res;
	unsigned int		i;

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
	unsigned long	current_time;

	pthread_mutex_lock(&(mutex()->curr_time));
	if (gettimeofday(&time, NULL) == -1)
	{
		pthread_mutex_unlock(&(mutex()->curr_time));
		error_hand(5);
	}
	current_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	pthread_mutex_unlock(&(mutex()->curr_time));
	return (current_time);
}

int	stop_eat(void)
{
	unsigned int	i;
	unsigned int	j;

	if (data()->nbr_tt_eat == 0)
		return (1);
	i = 0;
	j = 0;
	while (i < data()->nbr_philo)
	{
		if (get_uint(&data()->i_tt_eat[i]) == (data()->nbr_tt_eat))
			j++;
		i++;
	}
	if (j == (data()->nbr_philo - 1))
	{
		set_uint(&mutex()->var_uint, &data()->stop_eat, 0);
		print_message(i, 0);
		return (0);
	}
	else
		return (1);
}

void	print_message(int id, int message_code)
{
	unsigned long	timestamp;

	pthread_mutex_lock(&(mutex()->message));
	timestamp = get_current_time();
	if (message_code == 1 && (alive_protcl()))
		printf("%ld %d has taken a fork\n", timestamp, id);
	else if (message_code == 2 && (alive_protcl()))
		printf("%ld %d is eating\n", timestamp, id);
	else if (message_code == 3 && (alive_protcl()))
		printf("%ld %d is sleeping\n", timestamp, id);
	else if (message_code == 4 && (alive_protcl()))
		printf("%ld %d is thinking\n", timestamp, id);
	else if (message_code == 5)
		printf("%ld %d died\n", timestamp, id);
	pthread_mutex_unlock(&(mutex()->message));
}

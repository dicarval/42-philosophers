/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:10:06 by dicarval          #+#    #+#             */
/*   Updated: 2024/11/25 16:21:31 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_init(void)
{
	unsigned int	i;

	i = 0;
	while (i < (data()->nbr_philo))
		pthread_mutex_init(&(mutex()->forks[i++]), NULL);
	pthread_mutex_init(&(mutex()->message), NULL);
	pthread_mutex_init(&(mutex()->curr_time), NULL);
	pthread_mutex_init(&(mutex()->var_uint), NULL);
}

unsigned long	set_ulint(unsigned long var)
{
	unsigned long temp;

	pthread_mutex_lock(&mutex()->var_uint);
	temp = var;
	pthread_mutex_unlock(&mutex()->var_uint);
	return (temp);
}

unsigned int	set_uint(unsigned int var)
{
	unsigned int temp;

	pthread_mutex_lock(&mutex()->var_uint);
	temp = var;
	pthread_mutex_unlock(&mutex()->var_uint);
	return (temp);
}



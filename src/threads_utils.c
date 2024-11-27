/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:10:06 by dicarval          #+#    #+#             */
/*   Updated: 2024/11/27 14:58:44 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_destroy(void)
{
	unsigned int	i;

	i = 0;
	while (i < (data()->nbr_philo))
		pthread_mutex_destroy(&(mutex()->forks[i++]));
	pthread_mutex_destroy(&(mutex()->message));
	pthread_mutex_destroy(&(mutex()->curr_time));
	pthread_mutex_destroy(&(mutex()->is_alive));
	pthread_mutex_destroy(&(mutex()->var_uint));
	pthread_mutex_destroy(&(mutex()->last_meal));
}

void	mutex_init(void)
{
	unsigned int	i;

	i = 0;
	while (i < (data()->nbr_philo))
		pthread_mutex_init(&(mutex()->forks[i++]), NULL);
	pthread_mutex_init(&(mutex()->message), NULL);
	pthread_mutex_init(&(mutex()->curr_time), NULL);
	pthread_mutex_init(&(mutex()->is_alive), NULL);
	pthread_mutex_init(&(mutex()->var_uint), NULL);
	pthread_mutex_init(&(mutex()->last_meal), NULL);
}

unsigned int	get_uint(unsigned int *var)
{
	unsigned int	temp;

	pthread_mutex_lock(&mutex()->var_uint);
	temp = *var;
	pthread_mutex_unlock(&mutex()->var_uint);
	return (temp);
}

void	set_uint(pthread_mutex_t *mutex, unsigned int *where, \
unsigned int value)
{
	pthread_mutex_lock(mutex);
	*where = value;
	pthread_mutex_unlock(mutex);
}

unsigned long	get_last_meal(unsigned int i)
{
	unsigned long	lst_meal;

	pthread_mutex_lock(&mutex()->last_meal);
	lst_meal = data()->last_meal[i];
	pthread_mutex_unlock(&mutex()->last_meal);
	return (lst_meal);
}

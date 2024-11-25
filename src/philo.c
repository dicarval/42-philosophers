/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:38:41 by dicarval          #+#    #+#             */
/*   Updated: 2024/11/25 17:36:47 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	forks_up(unsigned int id, int right, int left)
{
	unsigned int	lock;

	if(data()->nbr_philo == 1)
			return (2);
	lock = set_uint(0);
	if (id % 2 == 0 && data()->alive)
	{
		pthread_mutex_lock(&(mutex()->forks[right]));
		print_message(id, 1);
		pthread_mutex_lock(&(mutex()->forks[left]));
		print_message(id, 1);
		lock = set_uint(1);
	}
	else if (data()->alive)
	{
		pthread_mutex_lock(&(mutex()->forks[left]));
		print_message(id, 1);
		pthread_mutex_lock(&(mutex()->forks[right]));
		print_message(id, 1);
		lock = set_uint(1);
	}
	return (lock);
}

void	sleep_think(int id, int right, int left, unsigned int lock)
{
	if (lock == 2)
	{
		pthread_mutex_unlock(&(mutex()->forks[right]));
		while (data()->alive)
			lock++;
	}
	else if (id % 2 == 0 && lock == 1)
	{
		pthread_mutex_unlock(&(mutex()->forks[right]));
		pthread_mutex_unlock(&(mutex()->forks[left]));
	}
	else if (lock == 1)
	{
		pthread_mutex_unlock(&(mutex()->forks[left]));
		pthread_mutex_unlock(&(mutex()->forks[right]));
	}
	if (data()->alive && lock == 1)
	{
		print_message(id, 3);
		usleep((data()->tt_sleep) * 1000);
		print_message(id, 4);
		usleep(1000);
	}
}

void	*philo_loop(void *arg)
{
	unsigned int		id;
	unsigned int		right;
	unsigned int		left;
	unsigned int		lock;

	id = set_uint(*(int *)arg);
	right = set_uint(id);
	left = set_uint((id + 1) % (data()->nbr_philo));
	while ((data()->i_tt_eat[id] < data()->nbr_tt_eat || data()->no_stop)\
	 && data()->alive)
	{
		lock = set_uint(forks_up(id, right, left));
		if (data()->alive && lock == 1)
		{
			data()->last_meal[id] = get_current_time();
			print_message(id, 2);
			usleep((data()->tt_eat) * 1000);
		}
		sleep_think(id, right, left, lock);
		data()->i_tt_eat[id]++;
	}
	return (NULL);
}

void	thread_management(void)
{
	unsigned int	i;

	mutex_init();
	i = 0;
	while (i < (data()->nbr_philo))
	{
		data()->id[i] = i;
		data()->last_meal[i] = get_current_time();
		pthread_create(&(data()->philo[i]), NULL, philo_loop, &data()->id[i]);
		i++;
	}
	pthread_create(&data()->eat_monit, NULL, alive, NULL);
	i = 0;
	while (i < (data()->nbr_philo))
		pthread_join((data()->philo[i++]), NULL);
	pthread_join(data()->eat_monit, NULL);
	i = 0;
	while (i < (data()->nbr_philo))
		pthread_mutex_destroy(&(mutex()->forks[i++]));
	pthread_mutex_destroy(&(mutex()->message));
	pthread_mutex_destroy(&(mutex()->curr_time));
	pthread_mutex_destroy(&(mutex()->var_uint));
	ft_free();
	exit(0);
}

int	main(int ac, char **av)
{
	if (ac >= 5 && ac <= 6)
	{
		av_allocation(av);
		thread_management();
	}
	error_hand(4);
	return (0);
}

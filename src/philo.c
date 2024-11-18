/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:38:41 by dicarval          #+#    #+#             */
/*   Updated: 2024/11/18 16:49:31 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	forks_up(int id, int right, int left)
{
	int	lock;

	lock = 0;
	if (id % 2 == 0 && data()->alive)
	{
		pthread_mutex_lock(&(data()->forks[right]));
		print_message(id, 1);
		pthread_mutex_lock(&(data()->forks[left]));
		print_message(id, 1);
		lock = 1;
	}
	else if (data()->alive)
	{
		pthread_mutex_lock(&(data()->forks[left]));
		print_message(id, 1);
		pthread_mutex_lock(&(data()->forks[right]));
		print_message(id, 1);
		lock = 1;
	}
	return (lock);
}

void	sleep_think(int id, int right, int left, int lock)
{
	if (id % 2 == 0 && lock == 1)
	{
		pthread_mutex_unlock(&(data()->forks[right]));
		pthread_mutex_unlock(&(data()->forks[left]));
	}
	else if (lock == 1)
	{
		pthread_mutex_unlock(&(data()->forks[left]));
		pthread_mutex_unlock(&(data()->forks[right]));
	}
	if (data()->alive)
	{
		print_message(id, 3);
		usleep(data()->tt_sleep);
		print_message(id, 4);
	}
}

void	*philo_loop(void *arg)
{
	unsigned int		id;
	unsigned int		right;
	unsigned int		left;
	int					lock;

	id = *(int *)arg;
	right = id;
	left = (id + 1) % (data()->nbr_philo);
	while ((data()->i_tt_eat < data()->nbr_tt_eat || data()->nbr_tt_eat == -1)\
	 && data()->alive)
	{
		lock = forks_up(id, right, left);
		if (data()->alive)
		{
			gettimeofday(&data()->last_meal[id], NULL);
			print_message(id, 2);
			usleep(data()->tt_eat);
		}
		sleep_think(id, right, left, lock);
		data()->i_tt_eat++;
	}
	return (NULL);
}

void	thread_management(void)
{
	unsigned int	i;

	i = 0;
	while (i < (data()->nbr_philo))
		pthread_mutex_init(&(data()->forks[i++]), NULL);
	pthread_mutex_init(&(data()->message), NULL);
	i = 0;
	while (i < (data()->nbr_philo))
	{
		data()->id[i] = i;
		gettimeofday(&(data()->last_meal[i]), NULL);
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
		pthread_mutex_destroy(&(data()->forks[i++]));
	pthread_mutex_destroy(&(data()->message));
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

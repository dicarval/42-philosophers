/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:38:41 by dicarval          #+#    #+#             */
/*   Updated: 2024/11/26 17:40:47 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	forks_up(unsigned int id, int right, int left)
{
	unsigned int	lock;

	if(data()->nbr_philo == 1)
			return (2);
	lock = 0;
	if (id % 2 == 0 && !alive_protcl())
	{
		pthread_mutex_lock(&(mutex()->forks[right]));
		print_message(id, 1);
		pthread_mutex_lock(&(mutex()->forks[left]));
		print_message(id, 1);
		lock = 1;
	}
	else if (!alive_protcl())
	{
		pthread_mutex_lock(&(mutex()->forks[left]));
		print_message(id, 1);
		pthread_mutex_lock(&(mutex()->forks[right]));
		print_message(id, 1);
		lock = 1;
	}
	return (lock);
}

void	forks_down(unsigned int id, unsigned int right, unsigned int left,\
 unsigned int lock)
{
	if (lock == 2)
	{
		pthread_mutex_unlock(&(mutex()->forks[right]));
		while (!alive_protcl())
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
}

void	*philo_loop(void *arg)
{
	unsigned int		id;
	unsigned int		right;
	unsigned int		left;
	unsigned int		lock;

	id = *(int *)arg;
	right = id;
	left = (id + 1) % (data()->nbr_philo);
	while ((get_uint(&data()->i_tt_eat[id]) < data()->nbr_tt_eat ||\
	 data()->no_stop) && !alive_protcl())
	{
		lock = forks_up(id, right, left);
		eat(id, lock);
		forks_down(id, right, left, lock);
		pthread_mutex_lock(&mutex()->var_uint);
		data()->i_tt_eat[id]++;
		pthread_mutex_unlock(&mutex()->var_uint);
		if (get_uint(&data()->i_tt_eat[id]) < data()->nbr_tt_eat || \
		data()->no_stop)
			sleep_think(id, lock);
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
		pthread_mutex_lock(&mutex()->last_meal);
		data()->last_meal[i] = get_current_time();
		pthread_mutex_unlock(&mutex()->last_meal);
		pthread_create(&(data()->philo[i]), NULL, philo_loop, &data()->id[i]);
		i++;
	}
	pthread_create(&data()->eat_monit, NULL, alive, NULL);
	i = 0;
	while (i < (data()->nbr_philo))
		pthread_join((data()->philo[i++]), NULL);
	pthread_join(data()->eat_monit, NULL);
	mutex_destroy();
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

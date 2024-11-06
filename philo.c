/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:38:41 by dicarval          #+#    #+#             */
/*   Updated: 2024/11/06 16:59:08 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

philo_t	*data(void)
{
	static philo_t	data;

	return(&data);
}

void	av_check(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] >= 0 && av[i][j] <= 9)
				j++;
			else
				error_hand(1);
		}
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
			error_hand(2);
		i++;
	}
}

void	av_allocation(char **av)
{
	av_check(av);
	data()->nbr_philo = ft_atoi(av[1]);
	data()->tt_die = ft_atoi(av[2]);
	data()->tt_eat = ft_atoi(av[3]);
	data()->tt_sleep = ft_atoi(av[4]);
	if (av[5])
		data()->nbr_tt_eat = ft_atoi(av[5]);
	else
		data()->nbr_tt_eat = -1;
	data()->philo = malloc(sizeof(pthread_t)*(data()->nbr_philo));
	if (data()->philo == NULL)
		error_hand(3);
	data()->forks = malloc(sizeof(pthread_mutex_t)*(data()->nbr_philo));
	if (data()->forks == NULL)
		error_hand(3);
	data()->id = malloc(sizeof(int)*(data()->nbr_philo));
	if (data()->id == NULL)
		error_hand(3);
}

void	*eat_think_sleep_repeat(void *arg)
{
	int	i;
	int	id;
	int	right;
	int	left;

	id = *(int*)arg;
	right = id;
	left = (id + 1) % (data()->nbr_philo);
	while(1)
	{
		if(id % 2 == 0)
			pthread_mutex_lock(&(data()->forks[right]));
		else
			pthread_mutex_lock(&(data()->forks[left]));
		if(id % 2 != 0)
			pthread_mutex_lock(&(data()->forks[right]));
		else
			pthread_mutex_lock(&(data()->forks[left]));
		pthread_mutex_lock(&(data()->message));
		gettimeofday(, NULL);
	}

}

void	thread_management(char **av)
{
	int	i;

	i = 0;
	data()->dead_philo = 0;
	while(i < (data()->nbr_philo))
		pthread_mutex_init(&(data()->forks[i++]), NULL);
	pthread_mutex_init(&(data()->message), NULL);
	i = 0;
	while(i < (data()->nbr_philo))
	{
		data()->id[i] = i;
		pthread_create(&(data()->philo[i]), NULL, eat_think_sleep_repeat, \
		&data()->id[i++]);
	}
	i = 0;
	while(i < (data()->nbr_philo))
		pthread_join((data()->philo[i++]), NULL);
	i = 0;
	while(i < (data()->nbr_philo))
		pthread_mutex_destroy(&(data()->forks[i++]));
	pthread_mutex_destroy(&(data()->message));
	ft_exit();
}

int	main(int ac, char **av)
{
	if (ac >= 5 && ac <= 6)
	{
		av_allocation(av);
		thread_management(av);
	}
	error_hand(0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:38:41 by dicarval          #+#    #+#             */
/*   Updated: 2024/11/14 18:19:03 by dicarval         ###   ########.fr       */
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
		//attention to this verification, it should accept long because of milliseconds
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
	data()->alive_philo = 0;
}

void	print_message(int id, int message_code)
{
	struct timeval	tv;
	int				ret;
	long			mil_sec;

	pthread_mutex_lock(&(data()->message));
	ret = gettimeofday(&tv, NULL);
	mil_sec = tv.tv_sec * 1000L + tv.tv_usec / 1000;
	if(ret == 0 && message_code == 1)
		printf("%ld %d has taken a fork", mil_sec, id);
	else if(ret == 0 && message_code == 2)
		printf("%ld %d is eating", mil_sec, id);
	else if(ret == 0 && message_code == 3)
		printf("%ld %d is sleeping", mil_sec, id);
	else if(ret == 0 && message_code == 4)
		printf("%ld %d is thinking", mil_sec, id);
	else if(ret == 0 && message_code == 5)
		printf("%ld %d died", mil_sec, id);
	else
		printf("gettimeofday failed");
	pthread_mutex_unlock(&(data()->message));
}
unsigned long	elapsed_time_meals(struct timeval last_meal)
{
	unsigned long	elapsed;
	struct timeval	now;

	gettimeofday(&now, NULL);
	elapsed =
}

void	*alive(void *)
{
	int	i;

	while(1)
	{
		i = 0;
		while(i < data()->nbr_philo)
		{
			if(!data()->alive_philo && \
			elapsed_time_meals(data()->last_meal[i]) > data()->tt_die)
			{
				print_message(i, 5);
				data()->alive_philo = 1;
			}
			i++;
		}
		if (data()->alive_philo)
			break;
	}
	return (NULL);
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
	i = 0;
	while(i < data()->nbr_tt_eat || data()->nbr_tt_eat == -1)
	{
		if(id % 2 == 0 && !data()->alive_philo)
		{
			pthread_mutex_lock(&(data()->forks[right]));
			print_message(id, 1);
		}
		else if (!data()->alive_philo)
		{
			pthread_mutex_lock(&(data()->forks[left]));
			print_message(id, 1);
		}
		if(id % 2 != 0 && !data()->alive_philo)
		{
			pthread_mutex_lock(&(data()->forks[right]));
			print_message(id, 1);
		}
		else if (!data()->alive_philo)
		{
			pthread_mutex_lock(&(data()->forks[left]));
			print_message(id, 1);
		}
		gettimeofday(&data()->last_meal[id],NULL);
		print_message(id, 2);
		usleep(data()->tt_eat);
		i++;
	}

}

void	thread_management(char **av)
{
	int	i;

	i = 0;
	while(i < (data()->nbr_philo))
		pthread_mutex_init(&(data()->forks[i++]), NULL);
	pthread_mutex_init(&(data()->message), NULL);
	i = 0;
	while(i < (data()->nbr_philo))
	{
		data()->id[i] = i;
		gettimeofday(&data()->last_meal[i], NULL);
		pthread_create(&(data()->philo[i]), NULL, eat_think_sleep_repeat, \
		&data()->id[i++]);
	}
	pthread_create(&data()->eat_monit, NULL, alive, NULL);
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
	return (0);
}

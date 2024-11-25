/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_allocation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:29:58 by dicarval          #+#    #+#             */
/*   Updated: 2024/11/25 16:10:06 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	number_max(char *arg, int i)
{
	if (i == 1)
	{
		if (ft_atoul(arg) > INT_MAX)
			error_hand(2);
	}
	else
	{
		if (ft_atoul(arg) > LONG_MAX)
			error_hand(2);
	}
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
			if (av[i][j] >= '0' && av[i][j] <= '9')
				j++;
			else
				error_hand(1);
		}
		number_max(av[i], i);
		i++;
	}
}

void	mem_alloc(void)
{
	unsigned int	i;

	i = 0;
	data()->philo = malloc(sizeof(pthread_t) * (data()->nbr_philo));
	if (data()->philo == NULL)
		error_hand(3);
	mutex()->forks = malloc(sizeof(pthread_mutex_t) * (data()->nbr_philo));
	if (mutex()->forks == NULL)
		error_hand(3);
	data()->id = malloc(sizeof(int) * (data()->nbr_philo));
	if (data()->id == NULL)
		error_hand(3);
	data()->last_meal = malloc(sizeof(unsigned long) * (data()->nbr_philo));
	if (data()->last_meal == NULL)
		error_hand(3);
	data()->i_tt_eat = malloc(sizeof(unsigned int) * (data()->nbr_philo));
	if (data()->i_tt_eat == NULL)
		error_hand(3);
	while(data()->i_tt_eat[i])
		data()->i_tt_eat[i++] = 0;
}

void	av_allocation(char **av)
{
	av_check(av);
	data()->nbr_philo = ft_atoul(av[1]);
	if (data()->nbr_philo == 0)
		error_hand(2);
	data()->tt_die = ft_atoul(av[2]);
	data()->tt_eat = ft_atoul(av[3]);
	data()->tt_sleep = ft_atoul(av[4]);
	if (av[5])
	{
		data()->no_stop = 0;
		data()->nbr_tt_eat = ft_atoul(av[5]);
	}
	else
	{
		data()->no_stop = 1;
		data()->nbr_tt_eat = 0;
	}
	mem_alloc();
	data()->alive = 1;
}

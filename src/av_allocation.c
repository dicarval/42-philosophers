/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_allocation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:29:58 by dicarval          #+#    #+#             */
/*   Updated: 2024/11/18 15:53:47 by dicarval         ###   ########.fr       */
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

void	av_allocation(char **av)
{
	av_check(av);
	data()->nbr_philo = ft_atoul(av[1]);
	if (data()->nbr_philo == 1)
		error_hand(2);
	data()->tt_die = ft_atoul(av[2]);
	data()->tt_eat = ft_atoul(av[3]);
	data()->tt_sleep = ft_atoul(av[4]);
	if (av[5])
		data()->nbr_tt_eat = ft_atoul(av[5]);
	else
		data()->nbr_tt_eat = -1;
	data()->philo = malloc(sizeof(pthread_t) * (data()->nbr_philo));
	if (data()->philo == NULL)
		error_hand(3);
	data()->forks = malloc(sizeof(pthread_mutex_t) * (data()->nbr_philo));
	if (data()->forks == NULL)
		error_hand(3);
	data()->id = malloc(sizeof(int) * (data()->nbr_philo));
	if (data()->id == NULL)
		error_hand(3);
	data()->last_meal = malloc(sizeof(struct timeval) * (data()->nbr_philo));
	if (data()->last_meal == NULL)
		error_hand(3);
	data()->alive = 1;
}

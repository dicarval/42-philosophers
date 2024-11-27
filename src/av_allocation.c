/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_allocation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:29:58 by dicarval          #+#    #+#             */
/*   Updated: 2024/11/27 15:19:32 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	number_max(char *arg, int i)
{
	if (i == 1 || i == 5)
	{
		if (ft_atoull(arg) > UINT_MAX)
			error_hand(2);
	}
	else
	{
		if (ft_atoull(arg) > ULONG_MAX)
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
	data()->philo = NULL;
	mutex()->forks = NULL;
	data()->id = NULL;
	data()->last_meal = NULL;
	data()->i_tt_eat = NULL;
	data()->philo = malloc(sizeof(pthread_t) * (data()->nbr_philo));
	if (data()->philo == NULL)
		error_hand(3);
	mutex()->forks = malloc(sizeof(pthread_mutex_t) * (data()->nbr_philo));
	if (mutex()->forks == NULL)
		error_hand(3);
	data()->id = malloc(sizeof(unsigned int) * (data()->nbr_philo));
	if (data()->id == NULL)
		error_hand(3);
	data()->last_meal = malloc(sizeof(unsigned long) * (data()->nbr_philo));
	if (data()->last_meal == NULL)
		error_hand(3);
	data()->i_tt_eat = malloc(sizeof(unsigned int) * (data()->nbr_philo));
	if (data()->i_tt_eat == NULL)
		error_hand(3);
	while(i < data()->nbr_philo)
		data()->i_tt_eat[i++] = 0;
}

void	av_allocation(char **av)
{
	av_check(av);
	data()->nbr_philo = ft_atoull(av[1]);
	if (data()->nbr_philo == 0)
		error_hand(2);
	data()->tt_die = ft_atoull(av[2]);
	data()->tt_eat = ft_atoull(av[3]);
	data()->tt_sleep = ft_atoull(av[4]);
	if (av[5])
		data()->nbr_tt_eat = ft_atoull(av[5]);
	else
		data()->nbr_tt_eat = 0;
	mem_alloc();
	data()->alive = 1;
	data()->stop_eat = 1;
}

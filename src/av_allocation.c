/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_allocation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:29:58 by dicarval          #+#    #+#             */
/*   Updated: 2024/12/11 10:17:25 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
				error_hand(INVAL_ARG);
		}
		if (ft_atoul(av[i]) > UINT_MAX)
			error_hand(INVAL_ARG);
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
		error_hand(MALLOC);
	mutex()->forks = malloc(sizeof(pthread_mutex_t) * (data()->nbr_philo));
	if (mutex()->forks == NULL)
		error_hand(MALLOC);
	data()->id = malloc(sizeof(unsigned int) * (data()->nbr_philo));
	if (data()->id == NULL)
		error_hand(MALLOC);
	data()->last_meal = malloc(sizeof(unsigned long) * (data()->nbr_philo));
	if (data()->last_meal == NULL)
		error_hand(MALLOC);
	data()->i_tt_eat = malloc(sizeof(unsigned int) * (data()->nbr_philo));
	if (data()->i_tt_eat == NULL)
		error_hand(MALLOC);
	while (i < data()->nbr_philo)
		data()->i_tt_eat[i++] = 0;
}

void	av_allocation(char **av)
{
	av_check(av);
	data()->nbr_philo = ft_atoul(av[1]);
	if (data()->nbr_philo == 0 || data()->nbr_philo > 300)
		error_hand(PHILO_NUM);
	data()->tt_die = ft_atoul(av[2]);
	data()->tt_eat = ft_atoul(av[3]);
	data()->tt_sleep = ft_atoul(av[4]);
	if (av[5])
		data()->nbr_tt_eat = ft_atoul(av[5]);
	else
		data()->nbr_tt_eat = 0;
	mem_alloc();
	data()->alive = 1;
	data()->stop_eat = 1;
	if (av[5] && av[5][0] == '0' && av[5][1] == '\0')
	{
		print_message(0, EAT_0);
		data()->stop_eat = 0;
	}
}

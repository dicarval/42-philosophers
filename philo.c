/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:38:41 by dicarval          #+#    #+#             */
/*   Updated: 2024/10/31 16:25:57 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo *philo(void)
{
	static t_philo data;

	return(&data);
}

void	av_check(char **av)
{
	int i;
	int j;

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
		if (ft_atoi(av[i]) >= INT_MAX || ft_atoi(av[i]) >= INT_MIN)
		{
			error_hand(2);
		}
		i++;
	}
}

void	av_parsing(char **av)
{
	av_check(av);
	philo()->nbr_philo = ft_atoi(av[1]);
	philo()->tt_die = ft_atoi(av[2]);
	philo()->tt_eat = ft_atoi(av[3]);
	philo()->tt_sleep = ft_atoi(av[4]);
	if (av[5])
		philo()->nbr_tt_eat = ft_atoi(av[5]);
	else
		philo()->nbr_tt_eat = -1;

}

int	main(int ac, char **av)
{
	if (ac >= 5 && ac <= 6)
	{
		av_parsing(av);
	}
}

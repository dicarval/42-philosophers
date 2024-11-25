/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alive.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:34:13 by dicarval          #+#    #+#             */
/*   Updated: 2024/11/25 17:31:14 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	elapsed_time_meals(unsigned long last_meal)
{
	unsigned long	elapsed;
	unsigned long	now;

	now = get_current_time();
	elapsed = (now - last_meal);
	return (elapsed);
}

int	nbr_tt_eat()
{
	unsigned int	i;
	unsigned int	j;

	if(data()->nbr_tt_eat == 0)
		return (1);
	i = 0;
	j = 0;
	while (i < data()->nbr_philo)
	{
		if (data()->i_tt_eat[i] == (data()->nbr_tt_eat - 1))
			j++;
		i++;
	}
	if (j == (data()->nbr_philo - 1))
		return (0);
	else
		return (1);
}

void	*alive(void *arg)
{
	unsigned int	i;

	(void)arg;
	while (1)
	{
		i = 0;
		while (i < data()->nbr_philo)
		{
			if (data()->i_tt_eat[i] == (data()->nbr_tt_eat))
				break ;
			if (data()->alive && \
			elapsed_time_meals(data()->last_meal[i]) > data()->tt_die)
			{
				print_message(i, 5);
				data()->alive = set_uint(0);
				break ;
			}
			i++;
		}
		if (!data()->alive || !(nbr_tt_eat()))
			break ;
	}
	return (NULL);
}

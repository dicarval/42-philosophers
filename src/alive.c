/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alive.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:34:13 by dicarval          #+#    #+#             */
/*   Updated: 2024/11/26 17:41:33 by dicarval         ###   ########.fr       */
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
		if (get_uint(&data()->i_tt_eat[i]) == (data()->nbr_tt_eat - 1))
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
			if (get_uint(&data()->i_tt_eat[i]) == (data()->nbr_tt_eat))
				break ;
			printf("teste1\n");
			if (alive_protcl() && \
			elapsed_time_meals(ft_last_meal(i)) > data()->tt_die)
			{
				set_uint(&mutex()->is_alive, &data()->alive, 0);
				print_message(i, 5);
				break ;
			}
			i++;
		}
		if (!alive_protcl() || !(nbr_tt_eat()))
			break ;
	}
	return (NULL);
}

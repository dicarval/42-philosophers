/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:09:08 by dicarval          #+#    #+#             */
/*   Updated: 2024/11/25 11:24:27 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(void)
{
	if (mutex()->forks)
		free(mutex()->forks);
	if (data()->id)
		free(data()->id);
	if (data()->philo)
		free(data()->philo);
	if (data()->last_meal)
		free(data()->last_meal);
}

void	error_hand(int error_code)
{
	ft_free();
	if (error_code == 4)
		printf("Number of arguments incorrect.\nSyntax: number_of_philosophers\
 time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat]\n");
	if (error_code == 3)
		printf("Malloc failed, exiting.\n");
	if (error_code == 2)
		printf("The philosophers numbers is 0, please add more.\n");
	if (error_code == 1)
		printf("Invalid argument(s), please ensure the input meets the \
specified criteria\n");
	exit(error_code);
}

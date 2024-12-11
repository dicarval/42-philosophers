/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:09:08 by dicarval          #+#    #+#             */
/*   Updated: 2024/12/11 10:20:42 by dicarval         ###   ########.fr       */
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
	if (data()->i_tt_eat)
		free(data()->i_tt_eat);
}

void	error_hand(int error_code)
{
	ft_free();
	if (error_code == GET_TIME_DAY)
		printf("gettimeofday failed.\n");
	if (error_code == ARG_NUM)
		printf("Number of arguments incorrect.\nSyntax: number_of_philosophers\
 time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat]\n");
	if (error_code == MALLOC)
		printf("Malloc failed, exiting.\n");
	if (error_code == PHILO_NUM)
		printf("The number of philosophers is out of range, please reform.\n");
	if (error_code == INVAL_ARG)
		printf("Invalid argument(s), please ensure the input meets the \
specified criteria.\n");
	exit(error_code);
}

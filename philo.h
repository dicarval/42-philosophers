/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:59:47 by dicarval          #+#    #+#             */
/*   Updated: 2024/10/31 16:16:13 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO
#define PHILO

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

typedef struct	s_philo
{
	int	nbr_philo;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	nbr_tt_eat;
}				t_philo;


#endif

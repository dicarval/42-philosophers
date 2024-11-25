/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:59:47 by dicarval          #+#    #+#             */
/*   Updated: 2024/11/25 16:18:31 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

/*Philo Struct*/
typedef struct s_philo
{
	unsigned int	nbr_philo;
	unsigned long	tt_die;
	unsigned long	tt_eat;
	unsigned long	tt_sleep;
	unsigned int	nbr_tt_eat;
	unsigned int	*i_tt_eat;
	unsigned int	no_stop;
	unsigned int	*id;
	unsigned int	alive;
	unsigned long	*last_meal;
	pthread_t		*philo;
	pthread_t		eat_monit;
}				t_philo;

/*Mutex Struct*/
typedef struct s_mutex
{
	pthread_mutex_t	message;
	pthread_mutex_t	*forks;
	pthread_mutex_t	curr_time;
	pthread_mutex_t	var_uint;
}				t_mutex;

/*Struct function*/
t_philo			*data(void);
t_mutex			*mutex(void);

/*Function to monitoring if all philosophers are alive*/
void			*alive(void *arg);

/*Checking input and allocation of memory*/
void			av_allocation(char **av);
void			number_max(char *av, int i);
unsigned long	ft_atoul(const char *str);

/*Program message print*/
void			print_message(int id, int message_code);

/*Function to access current time*/
unsigned long	get_current_time(void);

unsigned long	set_ulint(unsigned long var);
unsigned int	set_uint(unsigned int var);

/*Mutexes initialization*/
void			mutex_init(void);

/*Error handle and freeing allocated memory*/
void			error_hand(int error_code);
void			ft_free(void);

#endif

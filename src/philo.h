/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:59:47 by dicarval          #+#    #+#             */
/*   Updated: 2024/11/26 15:26:15 by dicarval         ###   ########.fr       */
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
	pthread_mutex_t	is_alive;
	pthread_mutex_t	last_meal;
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

unsigned int	get_uint(unsigned int *var);
void			set_uint(pthread_mutex_t *mutex, unsigned int *where, \
unsigned int value);

void			eat(unsigned int id, unsigned int lock);
void			sleep_think(unsigned int id, unsigned int lock);

int				alive_protcl(void);
unsigned long	ft_last_meal(unsigned int i);

/*Mutexes initialization and elimination*/
void			mutex_init(void);
void			mutex_destroy(void);

/*Mutexes initialization*/
int				alive_protcl(void);
unsigned long	ft_last_meal(unsigned int i);

/*Error handle and freeing allocated memory*/
void			error_hand(int error_code);
void			ft_free(void);

#endif

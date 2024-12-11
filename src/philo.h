/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:59:47 by dicarval          #+#    #+#             */
/*   Updated: 2024/12/11 10:29:09 by dicarval         ###   ########.fr       */
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

/*Message print*/

# define EAT_0 0
# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE 5

/*Error handle*/

# define INVAL_ARG 1
# define PHILO_NUM 2
# define MALLOC 3
# define ARG_NUM 4
# define GET_TIME_DAY 5

/*Philo Struct*/
typedef struct s_philo
{
	unsigned int	nbr_philo;
	unsigned int	tt_die;
	unsigned int	tt_eat;
	unsigned int	tt_sleep;
	unsigned int	nbr_tt_eat;
	unsigned int	stop_eat;
	unsigned int	alive;
	unsigned int	*i_tt_eat;
	unsigned int	*id;
	unsigned long	start_time;
	unsigned long	*last_meal;
	pthread_t		*philo;
	pthread_t		eat_monit;
}				t_philo;

/*Mutexes Struct*/
typedef struct s_mutex
{
	pthread_mutex_t	message;
	pthread_mutex_t	*forks;
	pthread_mutex_t	curr_time;
	pthread_mutex_t	is_alive;
	pthread_mutex_t	var_uint;
	pthread_mutex_t	last_meal;
}				t_mutex;

/*Philo struct function*/
t_philo				*data(void);

/*Mutexes struct function*/
t_mutex				*mutex(void);

/*Monitorization if all philosophers are alive*/
void				*alive(void *arg);

/*Checks the alive variable, avoiding threads conflicts*/
int					alive_protcl(void);

/*Checks the input and allocation of memory*/
void				av_allocation(char **av);

/*ASCII to unsigned long*/
unsigned long		ft_atoul(const char *str);

/*Program's message print*/
void				print_message(int id, int message_code);

/*Access current time*/
unsigned long		get_current_time(void);

/*Reads the variable using mutexes, avoiding threads conflicts*/
unsigned int		get_uint(unsigned int *var);

/*Writes the variable using mutexes, avoiding threads conflicts*/
void				set_uint(pthread_mutex_t *mutex, unsigned int *where, \
unsigned int value);

/*Reads the last_meal variable using mutexes, avoiding threads conflicts*/
unsigned long		get_last_meal(unsigned int i);

/*Eat action*/
void				eat(unsigned int id, unsigned int lock);

/*Sleep and think action*/
void				sleep_think(unsigned int id, unsigned int lock);

/*Checks the number of times that philosophers have eat*/
int					stop_eat(void);

/*Mutexes initialization*/
void				mutex_init(void);

/*Mutexes elimination*/
void				mutex_destroy(void);

/*Error handle*/
void				error_hand(int error_code);

void				ft_free(void);

#endif

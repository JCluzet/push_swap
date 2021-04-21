/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:15:15 by jcluzet           #+#    #+#             */
/*   Updated: 2021/04/21 19:26:49 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_check
{
	int			*a;
	int			*b;
	int			max_a;
	int			max_b;
	int			smallest_a;
	int			pos_a;
	int			args;
}				t_check;

int				stocktableau(t_check *checker, int argc, char **argv);
void			stockmorenum(t_check *checker, char **argv, int index, int index2);
int				ft_atoi(const char *str);
int				findalgo(t_check *checker);
int				numcheck(char *str);
int				checkifsort(t_check *checker);
int				checksamenum(t_check *checker);
void			sort2numbers(t_check *checker);
void			sort3numbers(t_check *checker);
void			my_putstr(char *str);
int				firstswap(t_check *checker);
void			sortmultinumbers(t_check *checker);
void			smallestnumber(t_check *checker);
int				swapa(t_check *checker);
int				swapb(t_check *checker);
int				pusha(t_check *checker);
int				pushb(t_check *checker);
int				rotatea(t_check *checker);
int				rotateb(t_check *checker);
int				reverserotatea(t_check *checker);
int				reverserotateb(t_check *checker);

#endif

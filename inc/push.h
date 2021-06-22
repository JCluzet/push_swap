/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:15:15 by jcluzet           #+#    #+#             */
/*   Updated: 2021/06/08 20:23:13 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct					s_check
{
	int							*a;
	int							*b;
	int							*chunk;
	unsigned long int			max_a;
	unsigned long int			max_b;
	int							smallest_a;
	int							smallest_b;
	int							nb_under;
	unsigned long int			pos_a;
	unsigned long int			pos_b;
	int							nb_of_chunk;
	int							index;
	int							index2;
	int							pin;
	int							exit;
	int							falseargs;
	int							falseargs1;
	int							falseargs2;
	int							args;
}								t_check;

int								stocktableau(t_check *checker,
								int argc, char **argv);
int								stockmorenum(t_check *checker, char **argv,
								int index, int index2);
long long int					ft_atoi(const char *str);
void							writetab(t_check *checker);
int								findalgo(t_check *checker);
void							sort_less_40_numbers(t_check *checker);
void							find_med_chunk(t_check *checker);
int								numcheck(char *str);
int								whereis_notsort(t_check *checker);
int								checkif_b_sort(t_check *checker);
void							biggestnumber_forb(t_check *checker);
void							sortb_toa(t_check *checker);
int								checkifsort(t_check *checker);
void							sorta(t_check *checker);
int								checksamenum(t_check *checker);
void							sort2numbers(t_check *checker);
void							sort3numbers(t_check *checker);
void							my_putstr(char *str);
int								firstswap(t_check *checker);
void							push_numa_to_b(t_check *checker, int i);
void							sortmultinumbers(t_check *checker);
void							smallestnumber(t_check *checker);
int								swapa(t_check *checker);
int								number_of_chunks(t_check *checker, int chunk);
int		make_b_ready_for_num(t_check *checker, int nb);
int		next_front(t_check *checker, int nb);
int		next_back(t_check *checker, int nb);
int		num_up(t_check *checker, unsigned long int pos);
int			nb_to_launch(t_check *checker, int chunk);
int		biggest_a(t_check *checker);
int								swapb(t_check *checker);
int								biggest_b(t_check *checker);
int								pusha(t_check *checker);
int								pushb(t_check *checker);
int								rotatea(t_check *checker);
void							ft_putchar(char c);
void							ft_putnbr(int nb);
int								checkargs(t_check *checker, int pin);
int								findargs(int argc, char **argv,
								t_check *checker);
int								rotateb(t_check *checker);
int								reverserotatea(t_check *checker);
int								reverserotateb(t_check *checker);

#endif

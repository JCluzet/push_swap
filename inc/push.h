/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:15:15 by jcluzet           #+#    #+#             */
/*   Updated: 2021/06/24 18:03:16 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_check
{
	int							*a;
	int							*b;
	int							*chunk;
	unsigned long int			max_a;
	unsigned long int			max_b;
	int							nb;
	int							temp;
	float						num;
	float						numplus;
	int							nb1;
	unsigned long int			i;
	int							pos_of_num;
	int							smallest_a;
	int							smallest_b;
	unsigned long int			pos_a;
	unsigned long int			pos_b;
	unsigned long int			nb_of_chunk;
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
int								reverse_or_rotate(t_check *checker,
									int nb, int a);
int								reverse_rotate_decided(t_check *checker, int nb);
void							pre_sort_for_chunk(t_check *checker);
int								findalgo(t_check *checker);
void							sort_less_40_numbers(t_check *checker);
void							find_med_chunk(t_check *checker);
void							sortmultinumbers_2(t_check *checker, int chunk);
int								checkifsort(t_check *checker);
int								checksamenum(t_check *checker);
void							sort2numbers(t_check *checker);
void							sort3numbers(t_check *checker);
void							my_putstr(char *str);
void							sortmultinumbers(t_check *checker);
void							smallestnumber(t_check *checker);
int								swapa(t_check *checker);
int								number_of_chunks(t_check *checker, int chunk);
int								make_b_ready_for_num(t_check *checker, int nb);
int								next_front(t_check *checker, int nb);
int								next_back(t_check *checker, int nb);
int								num_up(t_check *checker, unsigned long int pos);
int								nb_to_launch(t_check *checker, int chunk);
int								biggest_a(t_check *checker);
int								swapb(t_check *checker);
int								rr(t_check *checker);
int								rrr(t_check *checker);
int								biggest_b(t_check *checker);
int								pusha(t_check *checker);
int								pushb(t_check *checker);
int								rotatea(t_check *checker, int a);
void							ft_putchar(char c);
void							ft_putnbr(int nb);
int								checkargs(t_check *checker, int pin);
int								findargs(int argc, char **argv,
									t_check *checker);
int								rotateb(t_check *checker, int a);
int								reverserotatea(t_check *checker, int a);
int								reverserotateb(t_check *checker, int a);

#endif

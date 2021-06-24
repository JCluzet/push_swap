/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:15:24 by jcluzet           #+#    #+#             */
/*   Updated: 2021/05/01 04:45:05 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_check
{
	int					*a;
	int					*b;
	unsigned long int	max_a;
	unsigned long int	max_b;
	int					args;
	int					exitnbr;
	int					index;
	int					flag_v;
	int					index2;
	int					pin;
	int					exit;
	int					falseargs;
	int					falseargs1;
	int					falseargs2;
}						t_check;

long long int			ft_atoi(const char *str);
int						swapa(t_check *checker);
void					ft_nbr_putnbr(int nb, t_check *checker);
int						swapb(t_check *checker);
int						findargs(int argc, char **argv, t_check *checker);
void					my_putstr(char *str);
int						pusha(t_check *checker);
void					ft_putnbr(int nb);
void					ft_putchar(char c);
int						pushb(t_check *checker);
int						checksamenum(t_check *checker);
int						numcheck(char *str);
int						rotatea(t_check *checker);
int						rotateb(t_check *checker);
int						reverserotatea(t_check *checker);
int						reverserotateb(t_check *checker);
int						ft_strcmp(char *s1, char *s2);
int						checkifsort(t_check *checker);
int						get_next_line(int fd, char **line);
int						dispatcheur(t_check *checker, char *buf);
int						checkargs(t_check *checker, int pin);
int						stocktableau(t_check *checker, int argc, char **argv);
int						stockmorenum(t_check *checker, char **argv,
							int index, int index2);
int						findmoreargs(char **argv, int argc);

#endif

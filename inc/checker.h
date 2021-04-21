/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:15:24 by jcluzet           #+#    #+#             */
/*   Updated: 2021/04/21 03:31:19 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH__SWAP_H
# define PUSH__SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_check
{
	int* a;
	int* b;
	int max_a;
	int max_b;
	int args;
}				t_check;

int		ft_atoi(const char *str);
int		swapa(t_check *checker);
int		swapb(t_check *checker);
void	my_putstr(char *str);
int 	pusha(t_check *checker);
int 	pushb(t_check *checker);
int		checksamenum(t_check *checker);
int 	numcheck(char *str);
int 	rotatea(t_check *checker);
int 	rotateb(t_check *checker);
int 	reverserotatea(t_check *checker);
int 	reverserotateb(t_check *checker);
int		ft_strcmp(char *s1, char *s2);
int		checkifsort(t_check *checker);
int		get_next_line(int fd, char **line);
int		dispatcheur(t_check *checker, char *buf);
int		stocktableau(t_check *checker, int argc, char **argv);
int		findmoreargs(char **argv, int argc);
void	writetab(t_check *checker);

#endif

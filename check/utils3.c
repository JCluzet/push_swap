/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:15:40 by jcluzet           #+#    #+#             */
/*   Updated: 2021/05/01 21:32:29 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putnbr(int nb)
{
	if (nb < 0)
		ft_putchar('-');
	if (nb < 0)
		nb = nb * -1;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar('0' + nb);
}

long long int	ft_atoi(const char *str)
{
	int				min;
	long long int	nb;

	nb = 0;
	min = 0;
	while (*str && ((*str >= '\t' && *str <= '\r') || *str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			min++;
		str++;
	}
	while (*str && (*str <= '9' && *str >= '0'))
	{
		nb = nb * 10 + (*str - 48);
		str++;
	}
	return ((min % 2 == 0) ? nb : -nb);
}


int	writetab(t_check *checker)
{
 	unsigned long int index;
	 int nb;

	nb = 10;
	index = 0;
	if (checker->flag_v == 0)
		return(0);
	while(index < 30)
	{
		my_putstr("\n");
		index++;
	}
	index = 0;
	 if (checker->max_a != 0)
 		my_putstr("\n-A-");
	else
		my_putstr("\n   ");
	if (checker->max_b != 0)
 		my_putstr("          -B-\n");
	else
		my_putstr("\n");
	my_putstr("\n");
	while (index < checker->max_a || index < checker->max_b)
	{
		if (index < checker->max_a)
			ft_putnbr(checker->a[index]);
		if (index < checker->max_b)
		{
			if (index < checker->max_a)
			{
				nb = 13;
				ft_nbr_putnbr(checker->a[index], checker);
				while (nb - checker->exitnbr > 0)
				{
					my_putstr(" ");
					nb--;
				}
			}
			else
				my_putstr("             ");
			ft_putnbr(checker->b[index]);
		}
		index++;
		my_putstr("\n");
	}
 	printf("\n\n");
	return(0);
 }

void			ft_nbr_putnbr(int nb, t_check *checker)
{
	checker->exitnbr = 0;
	if (nb < 0)
		checker->exitnbr++;
	if (nb < 0)
		nb = nb * -1;
	while (nb >= 10)
	{
		nb = nb / 10;
		checker->exitnbr++;
	}
	if (nb < 10)
		checker->exitnbr++;
}

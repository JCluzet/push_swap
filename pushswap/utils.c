/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:14:57 by jcluzet           #+#    #+#             */
/*   Updated: 2021/04/29 17:29:59 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push.h"

long long int	ft_atoi(const char *str)
{
	int			min;
	long long	nb;

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

int				checksamenum(t_check *checker)
{
	unsigned long int index;
	unsigned long int index2;

	index = 0;
	index2 = 0;
	while (index < checker->max_a)
	{
		while (index2 < checker->max_a)
		{
			if (checker->a[index] == checker->a[index2] && index2 != index)
			{
				checker->falseargs1 = index;
				checker->falseargs2 = index2;
				return (-1);
			}
			index2++;
		}
		index2 = 0;
		index++;
	}
	return (0);
}

void			smallestnumber(t_check *checker)
{
	unsigned long int index;

	index = 1;
	checker->smallest_a = checker->a[0];
	checker->pos_a = 0;
	while (index < checker->max_a)
	{
		if (checker->a[index] < checker->smallest_a)
		{
			checker->smallest_a = checker->a[index];
			checker->pos_a = index;
		}
		index++;
	}
}

void			my_putstr(char *str)
{
	int		index;

	index = 0;
	while (str[index])
	{
		write(1, &str[index], 1);
		index++;
	}
}

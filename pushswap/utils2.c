/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:14:57 by jcluzet           #+#    #+#             */
/*   Updated: 2021/04/29 04:13:08 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push.h"

int		findargs(int argc, char **argv, t_check *checker)
{
	int			index;
	int			pin;
	int			exit;

	pin = 0;
	exit = 0;
	index = 1;
	while (index < argc)
	{
		exit++;
		while (argv[index][pin])
		{
			if ((argv[index][pin] < '0' || argv[index][pin] > '9')
			&& ((argv[index][pin] != ' ') && (argv[index][pin] != '-')))
			{
				checker->falseargs = index;
				return (-1);
			}
			if (argv[index][pin] == ' ' && (argv[index][pin + 1] <= '9'
			&& argv[index][pin + 1] >= '0'))
				exit++;
			pin++;
		}
		pin = 0;
		index++;
	}
	return (exit);
}

int checkargs2(t_check *checker)
{
	if (checksamenum(checker) == -1)
	{
		my_putstr("Error\nArguments ");
		ft_putnbr(checker->falseargs1 + 1);
		my_putstr(" and ");
		ft_putnbr(checker->falseargs2 + 1);
		my_putstr(" or more are the same\n");
		return(0);
	}
	return (1);
}

int		checkargs(t_check *checker, int pin)
{
	if (pin == -1)
	{
		my_putstr("Error\nArguments ");
		ft_putnbr(checker->falseargs);
		my_putstr(" or more, are not integers\n");
		return(-1);
	}
	if (pin == -2)
	{
		my_putstr("Error\nArguments ");
		ft_putnbr(checker->falseargs + 1);
		my_putstr(" or more, are bigger than an integer\n");
		return(0);
	}
	if (pin == -3)
		my_putstr("Malloc error\n");
	if (pin == -3)
		return (0);
	if (checkargs2(checker) == 0)
		return (0);
	return(1);
}

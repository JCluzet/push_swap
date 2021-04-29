/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:14:57 by jcluzet           #+#    #+#             */
/*   Updated: 2021/04/29 17:49:55 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push.h"

int				findargs(int argc, char **argv, t_check *checker)
{
	checker->pin = 0;
	checker->exit = 0;
	while (checker->index < argc)
	{
		checker->exit++;
		while (argv[checker->index][checker->pin])
		{
			if ((argv[checker->index][checker->pin] < '0' ||
			argv[checker->index][checker->pin] > '9')
			&& ((argv[checker->index][checker->pin] != ' ')
			&& (argv[checker->index][checker->pin] != '-')))
			{
				checker->falseargs = checker->index;
				return (-1);
			}
			if (argv[checker->index][checker->pin] == ' ' &&
			(argv[checker->index][checker->pin + 1] <= '9'
			&& argv[checker->index][checker->pin + 1] >= '0'))
				checker->exit++;
			checker->pin++;
		}
		checker->pin = 0;
		checker->index++;
	}
	return (checker->exit);
}

int				checkargs2(t_check *checker)
{
	if (checksamenum(checker) == -1)
	{
		my_putstr("Error\nArguments ");
		ft_putnbr(checker->falseargs1 + 1);
		my_putstr(" and ");
		ft_putnbr(checker->falseargs2 + 1);
		my_putstr(" or more are the same\n");
		return (0);
	}
	return (1);
}

int				checkargs(t_check *checker, int pin)
{
	if (pin == -1)
	{
		my_putstr("Error\nArguments ");
		ft_putnbr(checker->falseargs);
		my_putstr(" or more, are not integers\n");
		return (-1);
	}
	if (pin == -2)
	{
		my_putstr("Error\nArguments ");
		ft_putnbr(checker->falseargs + 1);
		my_putstr(" or more, are bigger than an integer\n");
		return (0);
	}
	if (pin == -3)
		my_putstr("Malloc error\n");
	if (pin == -3)
		return (0);
	if (checkargs2(checker) == 0)
		return (0);
	return (1);
}

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar('0' + nb);
}

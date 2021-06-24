/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:15:40 by jcluzet           #+#    #+#             */
/*   Updated: 2021/04/29 04:31:59 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	my_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		write(1, &str[index], 1);
		index++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	numcheck(char *str)
{
	int		index;
	double	temp;

	index = 0;
	temp = atoi(str);
	if (temp > 2147483647 || temp < -2147483647)
		return (-2);
	while (str[index])
	{
		if (!(str[index] <= '9' && str[index] >= '0'))
			return (-1);
		index++;
	}
	return (0);
}

int	checkargs2(t_check *checker)
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

int	checkargs(t_check *checker, int pin)
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

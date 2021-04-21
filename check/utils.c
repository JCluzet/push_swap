/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:15:34 by jcluzet           #+#    #+#             */
/*   Updated: 2021/04/21 18:58:00 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int		findargs(int argc, char **argv)
{
	int index;
	int pin;
	int exit;

	pin = 0;
	exit = 0;
	index = 1;
	while (index < argc)
	{
		exit++;
		while (argv[index][pin])
		{
			if ((argv[index][pin] < '0' || argv[index][pin] > '9') &&
			(argv[index][pin] != ' '))
				return (-1);
			if (argv[index][pin] == ' ' && (argv[index][pin + 1] <= '9' &&
			argv[index][pin + 1] >= '0'))
				exit++;
			pin++;
		}
		pin = 0;
		index++;
	}
	return (exit);
}

int		stocktableau(t_check *checker, int argc, char **argv)
{
	int index;
	int index2;
	int pin;

	index2 = 0;
	pin = 0;
	index = 0;
	checker->args = findargs(argc, argv);
	if (checker->args == -1)
		return (-1);
	checker->a = malloc(checker->args * sizeof(int));
	checker->b = malloc(checker->args * sizeof(int));
	while (index < argc - 1)
	{
		checker->a[index + index2] = ft_atoi(argv[index + 1]);
		checker->b[index + index2] = 0;
		stockmorenum(checker, argv, index, index2);
		index++;
	}
	checker->max_a = checker->args;
	checker->max_b = 0;
	return (0);
}

void	stockmorenum(t_check *checker, char **argv, int index, int index2)
{
	int pin;

	pin = 0;
	while (argv[index + 1][pin])
	{
		if (argv[index + 1][pin] == ' ' && (argv[index + 1][pin + 1] <= '9'
		&& argv[index + 1][pin + 1] >= '0'))
		{
			index2++;
			checker->a[index + index2] = ft_atoi(argv[index + 1] + pin + 1);
			checker->b[index + index2] = 0;
		}
		pin++;
	}
	pin = 0;
}

int		ft_atoi(const char *str)
{
	int min;
	int nb;

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

int		checksamenum(t_check *checker)
{
	int index;
	int index2;

	index = 0;
	index2 = 0;
	while (index < checker->max_a)
	{
		while (index2 < checker->max_a)
		{
			if (checker->a[index] == checker->a[index2] && index2 != index)
				return (-1);
			index2++;
		}
		index2 = 0;
		index++;
	}
	return (0);
}

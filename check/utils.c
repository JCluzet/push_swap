/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:15:34 by jcluzet           #+#    #+#             */
/*   Updated: 2021/04/29 17:59:31 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int		findargs(int argc, char **argv, t_check *checker)
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

int		filltab(t_check *checker, int argc, char **argv)
{
	long long int	num;
	int				falsearg;

	falsearg = -1;
	while (checker->index < argc - 1)
	{
		num = ft_atoi(argv[checker->index + 1]);
		if (num > 2147483647 || num < -2147483648)
		{
			checker->falseargs = checker->index;
			return (-2);
		}
		checker->a[checker->index + checker->index2] = (int)num;
		checker->b[checker->index + checker->index2] = 0;
		if (stockmorenum(checker, argv, checker->index, checker->index2) == -2)
		{
			checker->falseargs = checker->index;
			return (-2);
		}
		checker->index++;
	}
	return (0);
}

int		stocktableau(t_check *checker, int argc, char **argv)
{
	checker->index2 = 0;
	checker->index = 1;
	checker->args = findargs(argc, argv, checker);
	checker->index = 0;
	if (checker->args == -1)
		return (-1);
	checker->a = malloc(checker->args * sizeof(int));
	checker->b = malloc(checker->args * sizeof(int));
	if (checker->a == NULL || checker->b == NULL)
		return (-3);
	if (filltab(checker, argc, argv) == -2)
		return (-2);
	checker->max_a = checker->args;
	checker->max_b = 0;
	return (0);
}

int		stockmorenum(t_check *checker, char **argv,
				int index, int index2)
{
	int				pin;
	long long int	num;

	pin = 0;
	while (argv[index + 1][pin])
	{
		if (argv[index + 1][pin] == ' ' && (argv[index + 1][pin + 1] <= '9'
		&& argv[index + 1][pin + 1] >= '0'))
		{
			index2++;
			num = ft_atoi(argv[index + 1] + pin + 1);
			if (num > 2147483647 || num < -2147483648)
				return (-2);
			checker->a[index + index2] = (int)num;
			checker->b[index + index2] = 0;
		}
		pin++;
	}
	pin = 0;
	return (0);
}

int		checksamenum(t_check *checker)
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

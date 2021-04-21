/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:14:34 by jcluzet           #+#    #+#             */
/*   Updated: 2021/04/21 19:19:57 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push.h"

int		findalgo(t_check *checker)
{
	if (checker->max_a == 1)
		return (0);
	if (checker->max_a == 2)
		sort2numbers(checker);
	if (firstswap(checker) == 1)
		return (0);
	if (checker->max_a == 3)
		sort3numbers(checker);
	while (checkifsort(checker) == 1)
		sortmultinumbers(checker);
	return (0);
}

int		findargs(int argc, char **argv)
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
			&& (argv[index][pin] != ' '))
				return (-1);
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

int		stocktableau(t_check *checker, int argc, char **argv)
{
	int		index;
	int		index2;
	int		pin;

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
	int			pin;

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

int		main(int argc, char **argv)
{
	t_check		checkerr;
	int			check;

	if (argc == 1)
		my_putstr("Error\nMissing arguments");
	if (argc == 1)
		return (0);
	check = stocktableau(&checkerr, argc, argv);
	if (check == -1)
	{
		my_putstr("Error\nNon-conforming arguments, numbers only");
		return (0);
	}
	if (check == -2)
	{
		my_putstr("Error\nSome arguments are bigger than an integer\n");
		return (0);
	}
	if (checksamenum(&checkerr) == -1)
	{
		my_putstr("Error\nDuplicate arguments");
		return (0);
	}
	findalgo(&checkerr);
	return (0);
}

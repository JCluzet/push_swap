/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:14:34 by jcluzet           #+#    #+#             */
/*   Updated: 2021/04/29 04:13:33 by jcluzet          ###   ########.fr       */
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

int		stocktableau(t_check *checker, int argc, char **argv)
{
	int		index;
	int		index2;
	long long int num;

	index2 = 0;
	index = 0;
	checker->args = findargs(argc, argv, checker);
	if (checker->args == -1)
		return (-1);
	checker->a = malloc(checker->args * sizeof(int));
	checker->b = malloc(checker->args * sizeof(int));
	if (checker->a == NULL || checker->b == NULL)
		return (-3);
	while (index < argc - 1)
	{
		num = ft_atoi(argv[index + 1]);
		if (num > 2147483647 || num < -2147483648)
		{
			checker->falseargs = index;
			return(-2);
		}
		checker->a[index + index2] = (int)num;
		checker->b[index + index2] = 0;
		if (stockmorenum(checker, argv, index, index2) == -2)
		{
			checker->falseargs = index;
			return(-2);
		}
		index++;
	}
	checker->max_a = checker->args;
	checker->max_b = 0;
	return (0);
}

int	stockmorenum(t_check *checker, char **argv, int index, int index2)
{
	int			pin;
	long long int num;

	pin = 0;
	while (argv[index + 1][pin])
	{
		if (argv[index + 1][pin] == ' ' && (argv[index + 1][pin + 1] <= '9'
		&& argv[index + 1][pin + 1] >= '0'))
		{
			index2++;
			num = ft_atoi(argv[index + 1] + pin + 1);
			if (num > 2147483647 || num < -2147483648)
				return(-2);
			checker->a[index + index2] = (int)num;
			checker->b[index + index2] = 0;
		}
		pin++;
	}
	pin = 0;
	return(0);
}

int		main(int argc, char **argv)
{
	t_check		checkerr;
	int			pin;
	int			pin2;

	if (argc == 1)
		my_putstr("Error\nMissing arguments");
	if (argc == 1)
		return (0);
	pin = stocktableau(&checkerr, argc, argv);
	if ((pin2 = checkargs(&checkerr, pin)) == 0)
	{
		free(checkerr.a);
		free(checkerr.b);
		return (0);
	}
	if (pin2 == -1)
		return (0);
	findalgo(&checkerr);
	free(checkerr.a);
	free(checkerr.b);
	return (0);
}

// Verifier des free eventuels en +
// Faire les 2 bonus avec un beau affichage

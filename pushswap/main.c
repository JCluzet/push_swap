/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:14:34 by jcluzet           #+#    #+#             */
/*   Updated: 2021/04/21 15:43:45 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/push.h"

int	findalgo(t_check *checker)
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

int	stocktableau(t_check *checker, int argc, char **argv)
{
	int index;

	index = 0;

	checker->args = argc - 1;
	checker->a = malloc(checker->args * sizeof(int));
	checker->b = malloc(checker->args * sizeof(int));
	while (index < checker->args)
	{
		if (numcheck(argv[index + 1]) == -1)
			return (-1);
		if (numcheck(argv[index + 1]) == -2)
			return (-2);
		checker->a[index] = ft_atoi(argv[index+1]);
		checker->b[index] = 0;
		index++;
	}
	checker->max_a = checker->args;
	checker->max_b = 0;
	return (0);
}

int main(int argc, char **argv)
{
	t_check checkerr;
	int check;

	if (argc == 1)
	{
		my_putstr("Error\nMissing arguments, please enter number like : ./push_swap 3 2 1");
		return (0);
	}
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

int	checkifsort(t_check *checker)
{
	int index;

	index = 0;
	while (index < checker->max_a - 1)
	{
		if (checker->a[index] > checker->a[index + 1])
			return (1);
		index++;
	}
	if (checker->max_b != 0)
		return (1);
	return (0);
}

// Rajouter le -v qui affiche l'etat des piles in checker
// Rajouter la possibilité d'avoir plusieurs nombre dans un argument
// Normer tout les fichiers
// Personnaliser le Makefile

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_per_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:14:52 by jcluzet           #+#    #+#             */
/*   Updated: 2021/04/29 03:31:39 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push.h"

void		sort2numbers(t_check *checker)
{
	int temp;

	if (checker->a[0] > checker->a[1])
	{
		temp = checker->a[0];
		checker->a[0] = checker->a[1];
		checker->a[1] = temp;
		my_putstr("sa\n");
	}
}

int			firstswap(t_check *checker)
{
	int temp;

	temp = checker->a[0];
	checker->a[0] = checker->a[1];
	checker->a[1] = temp;
	if (checkifsort(checker) == 0)
	{
		my_putstr("sa\n");
		return (1);
	}
	else
	{
		temp = checker->a[0];
		checker->a[0] = checker->a[1];
		checker->a[1] = temp;
	}
	return (0);
}

void		sort3numbers(t_check *checker)
{
	if (checker->a[0] > checker->a[1] &&
	checker->a[1] < checker->a[2] && checker->a[0] < checker->a[2])
		swapa(checker);
	if (checker->a[0] > checker->a[1] &&
	checker->a[1] > checker->a[2] && checker->a[0] > checker->a[2])
	{
		swapa(checker);
		reverserotatea(checker);
	}
	if (checker->a[0] > checker->a[1] &&
	checker->a[1] < checker->a[2] && checker->a[0] > checker->a[2])
		rotatea(checker);
	if (checker->a[0] < checker->a[1] &&
	checker->a[1] > checker->a[2] && checker->a[0] < checker->a[2])
	{
		swapa(checker);
		rotatea(checker);
	}
	if (checker->a[0] < checker->a[1] &&
	checker->a[1] > checker->a[2] && checker->a[0] > checker->a[2])
		reverserotatea(checker);
}

// void		sortmultinumbers(t_check *checker)          TEmp check
// {
// 	while (checker->max_a > 3)
// 	{
// 		smallestnumber(checker);
// 		if (checker->pos_a == 0)
// 			pushb(checker);
// 		else if (checker->pos_a < checker->max_a / 2)
// 			rotatea(checker);
// 		else
// 			reverserotatea(checker);
// 	}
// 	sort3numbers(checker);
// 	while (checker->max_b)
// 		pusha(checker);
// }



void		sortmultinumbers(t_check *checker)
{
	int ref;
	unsigned long int i;

	i = 0;
	ref = checker->a[0];
	while (i < checker->max_a)
	{
		if (checker->a[i] <= ref)
		{
			checker->pos_a = i;
			push_numa_to_b(checker, checker->a[i]);
			i = 0;
		}
		i++;
		writetab(checker);
	}
	// trier les nombres dans B et renvoyer a la fin de A
	// boucler sans prendre en compte les derniers renvoyés de B qui sont dans la fin de A
}

void	push_numa_to_b(t_check *checker, int i)
{
		while ( checker->a[0] != i)
		{
			if (checker->pos_a < checker->max_a / 2)
				rotatea(checker);
			else
				reverserotatea(checker);
		}
		pushb(checker);
}

// Prendre le premier de A comme ref
// tout ce qui est en dessous passe dans B

void	writetab(t_check *checker)
{
	unsigned long int index;

	index = 0;
	printf ("\n\n   -- NEW --\n");
	if (checker->max_a != 0)
		printf("\n --- tab A ---\n");
	while (index < checker->max_a)
	{
		printf("\n   -> %d", checker->a[index]);
		index++;
	}
	if (checker->max_b != 0)
		printf("\n\n --- tab B ---\n");
	index = 0;

	while (index < checker->max_b)
	{
		printf("\n   -> %d", checker->b[index]);
		index++;
	}
	printf("\n\n");
}

int			checkifsort(t_check *checker)
{
	unsigned long int index;

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

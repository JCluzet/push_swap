/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_per_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:14:52 by jcluzet           #+#    #+#             */
/*   Updated: 2021/06/08 22:52:39 by jcluzet          ###   ########.fr       */
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

// void		sortmultinumbers(t_check *checker)
// {
// 	int ref;
// 	unsigned long int i;
// 	int temp;

// 	checker->nb_under = 0;
// 	// while (checkifsort(checker) != 0)
// 	// {
// 		i = whereis_notsort(checker);
// 		temp = i;
// 		printf("\n    I >> %lu", i);
// 		ref = checker->a[i];
// 		printf("\n    ref >> %d", ref);
// 		while (i < checker->max_a)
// 		{
// 			if (checker->a[i] <= ref)
// 			{
// 				checker->pos_a = i;
// 				push_numa_to_b(checker, checker->a[i]);
// 				i = temp-1;
// 			}
// 			i++;
// 			writetab(checker);
// 		}
// 		sortb_toa(checker);
// 		printf("\n    After sort B");
// 		writetab(checker);
// 		// writetab(checker);
// 	// }
// }

// void		sortmultinumbers(t_check *checker)
// {
// 	unsigned long int i;

// 	i = 0;
// 	writetab(checker);
// 	while (checker->max_a != 0)
// 	{
// 		sortb_toa(checker);
// 		pushb(checker);
// 	}
// 	writetab(checker);
// 	// sorta(checker);
// 	// writetab(checker);
// 	while (checker->max_b != 0)
// 		pusha(checker);
// 	writetab(checker);
// }

void		sortmultinumbers(t_check *checker)
{
	// SORT tout les nb
	// trouver la mediane
	find_med_chunk(checker);
}

void		find_med_chunk(t_check *checker)
{
	unsigned long int i;
	int temp;

	i = 0;
	while (i < checker->max_a)
	{
		checker->b[i] = checker->a[i];
		i++;
	}
	i = 0;
	while (i < checker->max_a - 1)
	{
		if (checker->b[i] > checker->b[i + 1])
		{
			temp = checker->b[i];
			checker->b[i] = checker->b[i + 1];
			checker->b[i + 1] = temp;
			i = -1;
		}
		i++;
	}
	i = 0;
	printf("This is B after > {");
	while (i < checker->max_a)
	{
		printf("%d", checker->b[i]);
		if (i != checker->max_a - 1)
			printf(" ,");
		i++;
	}
	printf("}\n");

	// Find chunk

	checker->chunk = malloc(8 * sizeof(int));

	checker->chunk[0] = checker->b[0];
	checker->chunk[1] = checker->b[checker->max_a / 4 -1];

	checker->chunk[2] = checker->b[checker->max_a / 4];
	checker->chunk[3] = checker->b[checker->max_a / 2-1];

	checker->chunk[4] = checker->b[checker->max_a / 2];
	checker->chunk[5] = checker->b[(int)(checker->max_a / 1.33)-1];

	checker->chunk[6] = checker->b[(int)(checker->max_a / 1.33)];
	checker->chunk[7] = checker->b[checker->max_a-1];

	printf("\nChunk 1 --- %d > %d", checker->chunk[0], checker->chunk[1]);
	printf("\nChunk 2 --- %d > %d", checker->chunk[2], checker->chunk[3]);
	printf("\nChunk 3 --- %d > %d", checker->chunk[4], checker->chunk[5]);
	printf("\nChunk 4 --- %d > %d", checker->chunk[6], checker->chunk[7]);
}

void	sorta(t_check *checker)
{
	while (checker->max_a > 1)
	{
		smallestnumber(checker);
		while (checker->a[0] != checker->smallest_a)
		{
			if (checker->pos_a < checker->max_a / 2)
				rotatea(checker);
			else
				reverserotatea(checker);
		}
		pushb(checker);
	}
}

void	sortb_toa(t_check *checker)
{
	biggestnumber_forb(checker); // + grand finalement
	while (checker->b[0] != checker->smallest_b)
	{
		if (checker->pos_b < checker->max_b / 2)
			rotateb(checker);
		else
			reverserotateb(checker);
	}
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
	// if (checker->max_b != 0)
	// 	return (1);
	return (0);
}

int			whereis_notsort(t_check *checker)
{
	unsigned long int index;

	index = 0;
	while (index < checker->max_a - 1)
	{
		if (checker->a[index] > checker->a[index + 1])
			return (index);
		index++;
	}
	return (-1);
}

// int			checkif_b_sort(t_check *checker)
// {
// 	unsigned long int index;

// 	index = 0;
// 	while (index < checker->max_b - 1)
// 	{
// 		if (checker->b[index] > checker->b[index + 1])
// 			return (1);
// 		index++;
// 	}
// 	return (0);
// }

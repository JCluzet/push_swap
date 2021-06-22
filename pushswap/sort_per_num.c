/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_per_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:14:52 by jcluzet           #+#    #+#             */
/*   Updated: 2021/06/22 04:27:14 by jcluzet          ###   ########.fr       */
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
	find_med_chunk(checker);
	int chunk;
	int pos_of_num;
	int nb;
	writetab(checker);

	chunk = 0;
	// while(checkifsort(checker) == 1 || checker->max_b != 0)
	// {
	// 		chunk = 0;
	while (chunk != 8) // a supp
	{
		while (number_of_chunks(checker, chunk) != 0)
		{
			// writetab(checker);
			pos_of_num = nb_to_launch(checker, chunk);         // nb to launch >> position
			nb = num_up(checker, pos_of_num);
			printf("nb pos > %d to launch is now up\n\n", pos_of_num);
			writetab(checker);
			make_b_ready_for_num(checker, nb);     // A CORRIGER
			printf("b now ready!\n\n");
			pushb(checker);
			writetab(checker);
		}
		while (biggest_b(checker) != checker->b[0]) // supp ?
			rotateb(checker);
		printf("Juste avant de push tout b dans A : biggest:%d\n\n", biggest_b(checker));
		writetab(checker);
		if (chunk != 0)
		{
			while (checker->a[checker->max_a-1] != checker->chunk[chunk-1])
			{
				rotatea(checker);
				printf(">>%d\n",checker->chunk[chunk-1]);
			}
		}
		while (checker->max_b != 0)
		{
			pusha(checker);
		}
		chunk += 2;
	}
	while (biggest_a(checker) != checker->a[checker->max_a-1])
			rotatea(checker);
	// }
	writetab(checker);
}

int		biggest_b(t_check *checker)
{
	unsigned long int i;
	int nb;

	i = 0;
	nb = checker->b[i];
	while (i < checker->max_b )
	{
		if (checker->b[i] > nb)
			nb = checker->b[i];
		i++;
	}
	return(nb);
}

int		biggest_a(t_check *checker)
{
	unsigned long int i;
	int nb;

	i = 0;
	nb = checker->a[i];
	while (i < checker->max_a )
	{
		if (checker->a[i] > nb)
			nb = checker->a[i];
		i++;
	}
	return(nb);
}

int		make_b_ready_for_num(t_check *checker, int nb)
{
	int i;

	i = 0;
	if (checker->max_b < 2)
		return (0);
	if (next_back(checker, nb) == -1)
	{
		while ( checker->b[checker->max_b - 1] != next_front(checker, nb))
			rotateb(checker);
		return (0);
	}
	while ((checker->b[0] != next_back(checker, nb)))
	{
		rotateb(checker);
		printf("\n%d", next_back(checker, nb));
	}
	return(0);
}

int		next_front(t_check *checker, int nb)
{
	unsigned long int i;
	int next_nb;

	next_nb = 2147483644;
	i = 0;
	while (i < checker->max_b)
	{
		if (checker->b[i] > nb)
		{
			if (checker->b[i] < next_nb)
				next_nb = checker->b[i];
		}
		i++;
	}
	return(next_nb);
}

int		next_back(t_check *checker, int nb)
{
	unsigned long int i;
	int next_nb;

	next_nb = -1;
	i = 0;
	while (i < checker->max_b)
	{
		if (checker->b[i] < nb)
			if (checker->b[i] > next_nb)
				next_nb = checker->b[i];
		i++;
	}
	return(next_nb);
}

	// TANT QUE A n'est pas trié
	// {
	// 	TANT QUE A ne contient plus de nb du chunk_X
	// 	{
	//  	Comparer le nb le plus rapide a reverserotate ou reverse      >> FUNCTION num_to_launch
	//		Rotate ou Reverse le nb jusqu'en haut
	//		Verifier qu'on peut accueillir ce nombre dans B				  >> FUNCTION
	//		Trier B si on ne peut pas l'accueilir
	//		Emmener le nb correspondant dans B avec un pushb
	// 	}
	// 	push tout dans A et le rotate
	//	chunk_X++
	// }

int		num_up(t_check *checker, unsigned long int pos)
{
	int number;

	number = checker->a[pos];
	if (pos > checker->max_a/2)
		while (checker->a[0] != number)
			reverserotatea(checker);
	else
		while (checker->a[0] != number)
			rotatea(checker);
	return (number);

}

int			nb_to_launch(t_check *checker, int chunk)
{
	unsigned long int i;
	int nb;
	int nb1;

	i = 0;
	while (i < checker->max_a)
	{
		if (checker->a[i] <= checker->chunk[chunk+1] && checker->a[i] >= checker->chunk[chunk])
		{
			nb = i;
			i = checker->max_a - 1;
			while (i > 0)
			{
				if (checker->a[i] <= checker->chunk[chunk+1] && checker->a[i] >= checker->chunk[chunk])
				{
					nb1 = checker->max_a - i;
					if (nb1 <= nb)
					{
						return (i);
					}
					else
						return(nb);
				}
				i--;
			}
		}
		i++;
	}
	return(0);
}

int			number_of_chunks(t_check *checker, int chunk)
{
	unsigned long int i;
	int nb;

	nb = 0;
	i = 0;
	while (i < checker->max_a)
	{
		if (checker->a[i] <= checker->chunk[chunk+1] && checker->a[i] >= checker->chunk[chunk])
			nb++;
		i++;
	}
	return (nb);
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

// void	sorta(t_check *checker)
// {
// 	while (checker->max_a > 1)
// 	{
// 		smallestnumber(checker);
// 		while (checker->a[0] != checker->smallest_a)
// 		{
// 			if (checker->pos_a < checker->max_a / 2)
// 				rotatea(checker);
// 			else
// 				reverserotatea(checker);
// 		}
// 		pushb(checker);
// 	}
// }

// void	sortb_toa(t_check *checker)
// {
// 	biggestnumber_forb(checker); // + grand finalement
// 	while (checker->b[0] != checker->smallest_b)
// 	{
// 		if (checker->pos_b < checker->max_b / 2)
// 			rotateb(checker);
// 		else
// 			reverserotateb(checker);
// 	}
// }

// void	push_numa_to_b(t_check *checker, int i)
// {
// 		while ( checker->a[0] != i)
// 		{
// 			if (checker->pos_a < checker->max_a / 2)
// 				rotatea(checker);
// 			else
// 				reverserotatea(checker);
// 		}
// 		pushb(checker);
// }

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

// int			whereis_notsort(t_check *checker)
// {
// 	unsigned long int index;

// 	index = 0;
// 	while (index < checker->max_a - 1)
// 	{
// 		if (checker->a[index] > checker->a[index + 1])
// 			return (index);
// 		index++;
// 	}
// 	return (-1);
// }

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

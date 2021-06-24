/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_per_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:14:52 by jcluzet           #+#    #+#             */
/*   Updated: 2021/06/24 18:40:13 by jcluzet          ###   ########.fr       */
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

void		sort3numbers(t_check *checker)
{
	if (checker->a[0] > checker->a[1] &&
	checker->a[1] < checker->a[2] && checker->a[0] < checker->a[2])
		swapa(checker);
	if (checker->a[0] > checker->a[1] &&
	checker->a[1] > checker->a[2] && checker->a[0] > checker->a[2])
	{
		swapa(checker);
		reverserotatea(checker,1);
	}
	if (checker->a[0] > checker->a[1] &&
	checker->a[1] < checker->a[2] && checker->a[0] > checker->a[2])
		rotatea(checker,1);
	if (checker->a[0] < checker->a[1] &&
	checker->a[1] > checker->a[2] && checker->a[0] < checker->a[2])
	{
		swapa(checker);
		rotatea(checker,1);
	}
	if (checker->a[0] < checker->a[1] &&
	checker->a[1] > checker->a[2] && checker->a[0] > checker->a[2])
		reverserotatea(checker,1);
}


void		sort_less_40_numbers(t_check *checker)
{
	while (checker->max_a > 3)
	{
		smallestnumber(checker);
		if (checker->pos_a == 0)
			pushb(checker);
		else if (checker->pos_a < checker->max_a / 2)
			rotatea(checker,1);
		else
			reverserotatea(checker,1);
	}
	sort3numbers(checker);
	while (checker->max_b)
		pusha(checker);
}

void		sortmultinumbers(t_check *checker)
{
	find_med_chunk(checker);
	int chunk;
	int pos_of_num;
	int nb;

	chunk = 0;
	while (chunk != (int)checker->nb_of_chunk)
	{
		while (number_of_chunks(checker, chunk) != 0)
		{
			// writetab(checker);
			pos_of_num = nb_to_launch(checker, chunk);         // nb to launch >> position
			nb = num_up(checker, pos_of_num);
			// printf("nb pos > %d to launch is now up\n\n", pos_of_num);
			// writetab(checker);
			make_b_ready_for_num(checker, nb);
			pushb(checker);
		}

		while (biggest_b(checker) != checker->b[0])
		{
			if (reverse_or_rotate(checker, biggest_b(checker), 0) == 0)
				rotateb(checker, 1);
			else
				reverserotateb(checker, 1);
		}                                                                    //// DETERMINER SI biggest_b est plus facile a ramener en bas a base de rb ou rrb  et taxer des rr ou rrr ?
		// printf("Juste avant de push tout b dans A : biggest:%d\n\n", biggest_b(checker));
		// writetab(checker);
		if (chunk != 0)
		{
			while (checker->a[checker->max_a-1] != checker->chunk[chunk-1])
			{
				if (reverse_or_rotate(checker, checker->chunk[chunk-1], 1) == 0)
					rotatea(checker, 1);
				else
					reverserotatea(checker, 1);                                                      //// DETERMINER SI biggest_b est plus facile a ramener en bas a base de rb ou rrb  et taxer des rr ou rrr ?
				// printf(">>%d\n",checker->chunk[chunk-1]);
			}
		}
		while (checker->max_b != 0)
			pusha(checker);
		chunk += 2;
	}
	while (biggest_a(checker) != checker->a[checker->max_a-1])
	{
		if (reverse_or_rotate(checker, biggest_a(checker), 1) == 0)
			rotatea(checker, 1);
		else
			reverserotatea(checker, 1);                                                      //// DETERMINER SI biggest_b est plus facile a ramener en bas a base de rb ou rrb  et taxer des rr ou rrr ?
	}
	// writetab(checker);                                                                   ////// DETERMINER SI biggest_b est plus facile a ramener en bas a base de rb ou rrb  et taxer des rr ou rrr ?
}

int		reverse_or_rotate(t_check *checker, int nb, int a)
{
	unsigned long int i;

	i = 0;
	if ( a == 0 )
	{
	while (i < checker->max_b)
	{
		if (checker->b[i] == nb)
		{
			if (i < checker->max_b / 2)
			{
				return (0);
			}
			else
			{
				return (1);
			}
		}
		i++;
	}
	}
	else
	{
	while (i < checker->max_a)
	{
		if (checker->a[i] == nb)
		{
			if (i < checker->max_a / 2)
			{
				return (0);
			}
			else
			{
				return (1);
			}
		}
		i++;
	}
	}
	return (-1);
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
		{
			if (reverse_or_rotate(checker, next_front(checker, nb), 0) == 0)
				rotateb(checker, 1);
			else
				reverserotateb(checker, 1);                                                      //// DETERMINER SI biggest_b est plus facile a ramener en bas a base de rb ou rrb  et taxer des rr ou rrr ?
		}      	                                                     // DETERMINER SI next_front est plus facile a ramener en bas a base de ra ou rra ? et si rr est pas mieux ? ou rrr ??
		return (0);
	}
	while ((checker->b[0] != next_back(checker, nb)))
	{
		if (reverse_or_rotate(checker, next_back(checker, nb), 0) == 0)
			rotateb(checker, 1);
		else
			reverserotateb(checker, 1);                                                      //// DETERMINER SI biggest_b est plus facile a ramener en bas a base de rb ou rrb  et taxer des rr ou rrr ?
	}      	                                              // DETERMINER SI next_front est plus facile a ramener en bas a base de ra ou rra ?
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

int		num_up(t_check *checker, unsigned long int pos)
{
	int number;

	number = checker->a[pos];
	if (pos > checker->max_a/2)
		while (checker->a[0] != number)
			reverserotatea(checker, 1);
	else
		while (checker->a[0] != number)
			rotatea(checker, 1);
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
	float num;
	float numplus;

	if (checker->max_a > 200)
	{
		checker->nb_of_chunk = 20;
		numplus = 0.1;
	}
	// 10 > 0.2 >> 9100 ins
	// 16 > 0.16
	// 20 > 0.1 >> 7900 ins
	// 30 > 0.75 NOP
	// 40 > 0.05 >> 10000 ins
	else
	{
		numplus = 0.04;
		checker->nb_of_chunk = 8;
	}
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
	num = 0.0;

	checker->chunk = malloc(checker->nb_of_chunk * sizeof(int));

	if (checker->nb_of_chunk == 8)
	{
	checker->chunk[0] = checker->b[0];
	checker->chunk[1] = checker->b[checker->max_a / 4 -1];
	checker->chunk[2] = checker->b[checker->max_a / 4];
	checker->chunk[3] = checker->b[checker->max_a / 2-1];
	checker->chunk[4] = checker->b[checker->max_a / 2];
	checker->chunk[5] = checker->b[(int)(checker->max_a / 1.33)-1];
	checker->chunk[6] = checker->b[(int)(checker->max_a / 1.33)];
	checker->chunk[7] = checker->b[checker->max_a-1];
	}
	else
	{
	while(i < checker->nb_of_chunk)
	{
		checker->chunk[i] = checker->b[(int)(checker->max_a * num)];
		num += numplus;
		checker->chunk[i+1] = checker->b[(int)(checker->max_a * num) -1];
		i += 2;
	}
	}
}

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
	return (0);
}

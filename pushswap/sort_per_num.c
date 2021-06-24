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

void	sort2numbers(t_check *checker)
{
	int	temp;

	if (checker->a[0] > checker->a[1])
	{
		temp = checker->a[0];
		checker->a[0] = checker->a[1];
		checker->a[1] = temp;
		my_putstr("sa\n");
	}
}

void	sort3numbers(t_check *checker)
{
	if (checker->a[0] > checker->a[1]
		&& checker->a[1] < checker->a[2] && checker->a[0] < checker->a[2])
		swapa(checker);
	if (checker->a[0] > checker->a[1]
		&& checker->a[1] > checker->a[2] && checker->a[0] > checker->a[2])
	{
		swapa(checker);
		reverserotatea(checker, 1);
	}
	if (checker->a[0] > checker->a[1]
		&& checker->a[1] < checker->a[2] && checker->a[0] > checker->a[2])
		rotatea(checker, 1);
	if (checker->a[0] < checker->a[1]
		&& checker->a[1] > checker->a[2] && checker->a[0] < checker->a[2])
	{
		swapa(checker);
		rotatea(checker, 1);
	}
	if (checker->a[0] < checker->a[1]
		&& checker->a[1] > checker->a[2] && checker->a[0] > checker->a[2])
		reverserotatea(checker, 1);
}

void	sort_less_40_numbers(t_check *checker)
{
	while (checker->max_a > 3)
	{
		smallestnumber(checker);
		if (checker->pos_a == 0)
			pushb(checker);
		else if (checker->pos_a < checker->max_a / 2)
			rotatea(checker, 1);
		else
			reverserotatea(checker, 1);
	}
	sort3numbers(checker);
	while (checker->max_b)
		pusha(checker);
}

void	sortmultinumbers(t_check *checker)
{
	int	chunk;

	chunk = 0;
	find_med_chunk(checker);
	while (chunk != (int)checker->nb_of_chunk)
	{
		sortmultinumbers_2(checker, chunk);
		while (checker->max_b != 0)
			pusha(checker);
		chunk += 2;
	}
	while (biggest_a(checker) != checker->a[checker->max_a - 1])
	{
		if (reverse_or_rotate(checker, biggest_a(checker), 1) == 0)
			rotatea(checker, 1);
		else
			reverserotatea(checker, 1);
	}
}

void	sortmultinumbers_2(t_check *checker, int chunk)
{
	while (number_of_chunks(checker, chunk) != 0)
	{
		checker->pos_of_num = nb_to_launch(checker, chunk);
		checker->nb = num_up(checker, checker->pos_of_num);
		make_b_ready_for_num(checker, checker->nb);
		pushb(checker);
	}
	while (biggest_b(checker) != checker->b[0])
	{
		if (reverse_or_rotate(checker, biggest_b(checker), 0) == 0)
			rotateb(checker, 1);
		else
			reverserotateb(checker, 1);
	}
	if (chunk != 0)
	{
		while (checker->a[checker->max_a - 1] != checker->chunk[chunk - 1])
		{
			if (reverse_or_rotate(checker, checker->chunk[chunk - 1],
					1) == 0)
				rotatea(checker, 1);
			else
				reverserotatea(checker, 1);
		}
	}
}

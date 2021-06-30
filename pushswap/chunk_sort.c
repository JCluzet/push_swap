/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:14:57 by jcluzet           #+#    #+#             */
/*   Updated: 2021/07/01 01:02:50 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push.h"

void	attribute_chunk(t_check *checker)
{
	checker->chunk = malloc(checker->nb_of_chunk * sizeof(int));
	checker->checkmalloc = 1;
	if (checker->nb_of_chunk == 8)
	{
		checker->chunk[0] = checker->b[0];
		checker->chunk[1] = checker->b[checker->max_a / 4 - 1];
		checker->chunk[2] = checker->b[checker->max_a / 4];
		checker->chunk[3] = checker->b[checker->max_a / 2 - 1];
		checker->chunk[4] = checker->b[checker->max_a / 2];
		checker->chunk[5] = checker->b[(int)(checker->max_a / 1.33) - 1];
		checker->chunk[6] = checker->b[(int)(checker->max_a / 1.33)];
		checker->chunk[7] = checker->b[checker->max_a - 1];
	}
	else
	{
		while (checker->i < checker->nb_of_chunk)
		{
			checker->chunk[checker->i]
				= checker->b[(int)(checker->max_a * checker->num)];
			checker->num += checker->numplus;
			checker->chunk[checker->i + 1]
				= checker->b[(int)(checker->max_a * checker->num) - 1];
			checker->i += 2;
		}
	}
}

void	find_med_chunk(t_check *checker)
{
	if (checker->max_a > 200)
	{
		checker->nb_of_chunk = 20;
		checker->numplus = 0.1;
	}
	else
	{
		checker->numplus = 0.04;
		checker->nb_of_chunk = 8;
	}
	pre_sort_for_chunk(checker);
	checker->i = 0;
	checker->num = 0.0;
	attribute_chunk(checker);
}

void	pre_sort_for_chunk(t_check *checker)
{
	checker->i = 0;
	while (checker->i < checker->max_a)
	{
		checker->b[checker->i] = checker->a[checker->i];
		checker->i++;
	}
	checker->i = 0;
	while (checker->i < checker->max_a - 1)
	{
		if (checker->b[checker->i] > checker->b[checker->i + 1])
		{
			checker->temp = checker->b[checker->i];
			checker->b[checker->i] = checker->b[checker->i + 1];
			checker->b[checker->i + 1] = checker->temp;
			checker->i = -1;
		}
		checker->i++;
	}
}

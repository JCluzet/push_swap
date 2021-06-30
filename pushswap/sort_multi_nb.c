/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_multi_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:14:44 by jcluzet           #+#    #+#             */
/*   Updated: 2021/07/01 00:56:37 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push.h"

int	reverse_or_rotate(t_check *checker, int nb, int a)
{
	checker->i = 0;
	if (a == 0)
	{
		while (checker->i < checker->max_b)
		{
			if (checker->b[checker->i] == nb)
			{
				if (checker->i < checker->max_b / 2)
					return (0);
				else
					return (1);
			}
			checker->i++;
		}
	}
	else
		return (reverse_rotate_decided(checker, nb));
	return (-1);
}

int	reverse_rotate_decided(t_check *checker, int nb)
{
	while (checker->i < checker->max_a)
	{
		if (checker->a[checker->i] == nb)
		{
			if (checker->i < checker->max_a / 2)
				return (0);
			else
				return (1);
		}
		checker->i++;
	}
	return (-1);
}

int	make_b_ready_for_num(t_check *checker, int nb)
{
	if (checker->max_b < 2)
		return (0);
	if (next_back(checker, nb) == -1)
	{
		while (checker->b[checker->max_b - 1] != next_front(checker, nb))
		{
			if (reverse_or_rotate(checker, next_front(checker, nb), 0) == 0)
				rotateb(checker, 1);
			else
				reverserotateb(checker, 1);
		}
		return (0);
	}
	while ((checker->b[0] != next_back(checker, nb)))
	{
		if (reverse_or_rotate(checker, next_back(checker, nb), 0) == 0)
			rotateb(checker, 1);
		else
			reverserotateb(checker, 1);
	}
	return (0);
}

int	number_of_chunks(t_check *checker, int chunk)
{
	unsigned long int	i;
	int					nb;

	nb = 0;
	i = 0;
	while (i < checker->max_a)
	{
		if (checker->a[i] <= checker->chunk[chunk + 1]
			&& checker->a[i] >= checker->chunk[chunk])
			nb++;
		i++;
	}
	return (nb);
}

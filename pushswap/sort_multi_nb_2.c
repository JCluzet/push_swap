/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_multi_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:14:44 by jcluzet           #+#    #+#             */
/*   Updated: 2021/06/24 16:27:33 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push.h"

int	nb_to_launch(t_check *checker, int chunk)
{
	checker->i = 0;
	while (checker->i < checker->max_a)
	{
		if (checker->a[checker->i] <= checker->chunk[chunk + 1]
			&& checker->a[checker->i] >= checker->chunk[chunk])
		{
			checker->nb = checker->i;
			checker->i = checker->max_a - 1;
			while (checker->i > 0)
			{
				if (checker->a[checker->i] <= checker->chunk[chunk + 1]
					&& checker->a[checker->i] >= checker->chunk[chunk])
				{
					checker->nb1 = checker->max_a - checker->i;
					if (checker->nb1 <= checker->nb)
						return (checker->i);
					else
						return (checker->nb);
				}
				checker->i--;
			}
		}
		checker->i++;
	}
	return (0);
}

int	num_up(t_check *checker, unsigned long int pos)
{
	int	number;

	number = checker->a[pos];
	if (pos > checker->max_a / 2)
		while (checker->a[0] != number)
			reverserotatea(checker, 1);
	else
		while (checker->a[0] != number)
			rotatea(checker, 1);
	return (number);
}

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

int	biggest_b(t_check *checker)
{
	unsigned long int	i;
	int					nb;

	i = 0;
	nb = checker->b[i];
	while (i < checker->max_b)
	{
		if (checker->b[i] > nb)
			nb = checker->b[i];
		i++;
	}
	return (nb);
}

int	biggest_a(t_check *checker)
{
	unsigned long int	i;
	int					nb;

	i = 0;
	nb = checker->a[i];
	while (i < checker->max_a)
	{
		if (checker->a[i] > nb)
			nb = checker->a[i];
		i++;
	}
	return (nb);
}

int	next_front(t_check *checker, int nb)
{
	unsigned long int	i;
	int					next_nb;

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
	return (next_nb);
}

int	next_back(t_check *checker, int nb)
{
	unsigned long int	i;
	int					next_nb;

	next_nb = -1;
	i = 0;
	while (i < checker->max_b)
	{
		if (checker->b[i] < nb)
			if (checker->b[i] > next_nb)
				next_nb = checker->b[i];
		i++;
	}
	return (next_nb);
}

int	checkifsort(t_check *checker)
{
	unsigned long int	index;

	index = 0;
	while (index < checker->max_a - 1)
	{
		if (checker->a[index] > checker->a[index + 1])
			return (1);
		index++;
	}
	return (0);
}

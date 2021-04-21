/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_per_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:14:52 by jcluzet           #+#    #+#             */
/*   Updated: 2021/04/21 19:24:15 by jcluzet          ###   ########.fr       */
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
	int index;
	int temp;

	index = 0;
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

void		sortmultinumbers(t_check *checker)
{
	while (checker->max_a > 3)
	{
		smallestnumber(checker);
		if (checker->pos_a == 0)
		{
			pushb(checker);
		}
		else if (checker->pos_a < checker->max_a / 2)
			rotatea(checker);
		else
			reverserotatea(checker);
	}
	sort3numbers(checker);
	while (checker->max_b)
		pusha(checker);
}

int			checkifsort(t_check *checker)
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

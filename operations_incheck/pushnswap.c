/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushnswap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:15:09 by jcluzet           #+#    #+#             */
/*   Updated: 2021/04/29 03:27:09 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int	swapa(t_check *checker)
{
	int temp;

	if (checker->max_a < 2)
		return (0);
	temp = checker->a[0];
	checker->a[0] = checker->a[1];
	checker->a[1] = temp;
	return (0);
}

int	swapb(t_check *checker)
{
	int temp;

	if (checker->max_b < 2)
		return (0);
	temp = checker->b[0];
	checker->b[0] = checker->b[1];
	checker->b[1] = temp;
	return (0);
}

int	pusha(t_check *checker)
{
	unsigned long int index;

	index = checker->max_a - 1;
	if (checker->max_b < 1)
		return (0);
	while (index >= 0)
	{
		checker->a[index + 1] = checker->a[index];
		index--;
	}
	checker->a[0] = checker->b[0];
	index = 1;
	while (index < checker->max_b)
	{
		checker->b[index - 1] = checker->b[index];
		index++;
	}
	checker->max_b--;
	checker->max_a++;
	return (0);
}

int	pushb(t_check *checker)
{
	unsigned long int index;

	index = checker->max_b - 1;
	if (checker->max_a < 1)
		return (0);
	while (index >= 0)
	{
		checker->b[index + 1] = checker->b[index];
		index--;
	}
	checker->b[0] = checker->a[0];
	index = 1;
	while (index < checker->max_a)
	{
		checker->a[index - 1] = checker->a[index];
		index++;
	}
	checker->max_a--;
	checker->max_b++;
	return (0);
}

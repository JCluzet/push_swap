/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:14:44 by jcluzet           #+#    #+#             */
/*   Updated: 2021/04/29 17:54:54 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push.h"

int	rotatea(t_check *checker)
{
	unsigned long int	index;
	int					temp;

	index = 1;
	if (checker->max_a < 1)
		return (0);
	temp = checker->a[0];
	while (index < checker->max_a)
	{
		checker->a[index - 1] = checker->a[index];
		index++;
	}
	checker->a[index - 1] = temp;
	printf("ra\n");
	return (0);
}

int	reverserotatea(t_check *checker)
{
	int					temp;
	unsigned long int	index;

	index = checker->max_a - 1;
	if (checker->max_a < 1)
		return (0);
	temp = checker->a[index];
	while (index > 0)
	{
		checker->a[index] = checker->a[index - 1];
		index--;
	}
	checker->a[0] = temp;
	my_putstr("rra\n");
	return (0);
}

int	reverserotateb(t_check *checker)
{
	int					temp;
	unsigned long int	index;

	index = checker->max_b - 1;
	if (checker->max_b < 1)
		return (0);
	temp = checker->b[index];
	while (index > 0)
	{
		checker->b[index] = checker->b[index - 1];
		index--;
	}
	checker->b[0] = temp;
	my_putstr("rrb\n");
	return (0);
}

int	rotateb(t_check *checker)
{
	int					temp;
	unsigned long int	index;

	index = 0;
	if (checker->max_b < 1)
		return (0);
	temp = checker->b[0];
	while (index < checker->max_b)
	{
		checker->b[index - 1] = checker->b[index];
		index++;
	}
	checker->b[index - 1] = temp;
	my_putstr("srb\n");
	return (0);
}

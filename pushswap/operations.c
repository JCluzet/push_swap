/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:14:44 by jcluzet           #+#    #+#             */
/*   Updated: 2021/04/21 05:31:38 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/push.h"

int	swapa(t_check *checker)
{
	int temp;

	if (checker->max_a < 2)
		return (0);
	temp = checker->a[0];
	checker->a[0] = checker->a[1];
	checker->a[1] = temp;
	my_putstr("sa\n");
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
	my_putstr("sb\n");
	return (0);
}

int pusha(t_check *checker)
{
	int index;

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
	my_putstr("pa\n");
	return (0);
}

int pushb(t_check *checker)
{
	int index;

	index = checker->max_b;
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
	my_putstr("pb\n");
	return (0);
}

int rotatea(t_check *checker)
{
	int temp;
	int index;

	index = 1;
	if (checker->max_a < 1)
		return (0);
	temp = checker->a[0];
	while (index < checker->max_a)
	{
		checker->a[index-1] = checker->a[index];
		index++;
	}
	checker->a[index - 1] = temp;
	printf("ra\n");
	return (0);
}

int reverserotatea(t_check *checker)
{
	int temp;
	int index;

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

int reverserotateb(t_check *checker)
{
	int temp;
	int index;

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

int rotateb(t_check *checker)
{
	int temp;
	int index;

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


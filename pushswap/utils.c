/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:14:57 by jcluzet           #+#    #+#             */
/*   Updated: 2021/04/21 04:45:54 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/push.h"

int	ft_atoi(const char *str)
{
	int min;
	int nb;

	nb = 0;
	min = 0;
	while (*str && ((*str >= '\t' && *str <= '\r') || *str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			min++;
		str++;
	}
	while (*str && (*str <= '9' && *str >= '0'))
	{
		nb = nb * 10 + (*str - 48);
		str++;
	}
	return ((min % 2 == 0) ? nb : -nb);
}

int numcheck(char *str)
{
	int index;
	int temp;

	index = 0;
	temp = atoi(str);
	if (temp > 2147483647 || temp < -2147483647)
		return (-2);
	while (str[index])
	{
		if (! (str[index] <= '9' && str[index] >= '0') )
			return (-1);
		index++;
	}
	return (0);
}

int	checksamenum(t_check *checker)
{
	int index;
	int index2;

	index = 0;
	index2 = 0;
	while (index < checker->max_a)
	{
		while (index2 < checker->max_a)
		{
			if (checker->a[index] == checker->a[index2] && index2 != index)
				return (-1);
			index2++;
		}
		index2 = 0;
		index++;
	}
	return (0);
}

void smallestnumber(t_check *checker)
{
	int index;

	index = 1;
	checker->smallest_a = checker->a[0];
	checker->pos_a = 0;
	while (index < checker->max_a)
	{
		if (checker->a[index] < checker->smallest_a)
		{
			checker->smallest_a = checker->a[index];
			checker->pos_a = index;
		}
		index++;
	}
}

void	my_putstr(char *str)
{
	int index;
	char c;

	index = 0;
	while(str[index])
	{
		c = str[index];
		write(1, &str[index], 1);
		index++;
	}
}

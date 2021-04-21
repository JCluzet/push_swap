/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:15:34 by jcluzet           #+#    #+#             */
/*   Updated: 2021/04/21 04:03:36 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/checker.h"

int	stocktableau(t_check *checker, int argc, char **argv)
{
	int index;

	index = 0;

	checker->args = argc - 1;
	checker->a = malloc(checker->args * sizeof(int));
	checker->b = malloc(checker->args * sizeof(int));
	while (index < checker->args)
	{
		if (numcheck(argv[index+1]) == -1)
			return (-1);
		if (numcheck(argv[index+1]) == -2)
			return (-2);
		checker->a[index] = ft_atoi(argv[index+1]);
		checker->b[index] = 0;
		index++;
	}
	checker->max_a = checker->args;
	checker->max_b = 0;
	return (0);
}

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

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int numcheck(char *str)
{
	int index;
	double temp;

	index = 0;
	temp = atoi(str);
	if (temp > 2147483647 || temp < -2147483647)
		return (-2);
	while (str[index])
	{
		if (! (str[index] <= '9' && str[index] >= '0'))
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

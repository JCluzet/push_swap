/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:15:40 by jcluzet           #+#    #+#             */
/*   Updated: 2021/04/21 18:59:23 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	my_putstr(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		write(1, &str[index], 1);
		index++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int		numcheck(char *str)
{
	int		index;
	double	temp;

	index = 0;
	temp = atoi(str);
	if (temp > 2147483647 || temp < -2147483647)
		return (-2);
	while (str[index])
	{
		if (!(str[index] <= '9' && str[index] >= '0'))
			return (-1);
		index++;
	}
	return (0);
}

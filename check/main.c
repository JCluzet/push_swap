/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:15:40 by jcluzet           #+#    #+#             */
/*   Updated: 2021/04/29 04:44:56 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int		read_n_sort(t_check *checker)
{
	char				*buf;
	int					ret;

	ret = get_next_line(0, &buf);
	while (ret > 0)
	{
		if (dispatcheur(checker, buf) == -1)
			my_putstr("      --> Argument non reconnu\n");
		free(buf);
		ret = get_next_line(0, &buf);
		if (buf[0] == '\0')
			ret = -1;
	}
	free(buf);
	if (checkifsort(checker) == 1)
		my_putstr("KO\n");
	else
		my_putstr("OK\n");
	return (0);
}

int		checkifsort(t_check *checker)
{
	unsigned long int	index;

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

int		dispatcheur(t_check *checker, char *buf)
{
	if (ft_strcmp(buf, "sa") == 0)
		return (swapa(checker));
	else if (ft_strcmp(buf, "sb") == 0)
		return (swapb(checker));
	else if (ft_strcmp(buf, "ss") == 0)
		return (swapa(checker) && swapb(checker));
	else if (ft_strcmp(buf, "pa") == 0)
		return (pusha(checker));
	else if (ft_strcmp(buf, "pb") == 0)
		return (pushb(checker));
	else if (ft_strcmp(buf, "ra") == 0)
		return (rotatea(checker));
	else if (ft_strcmp(buf, "rb") == 0)
		return (rotateb(checker));
	else if (ft_strcmp(buf, "rr") == 0)
		return (rotatea(checker) && rotateb(checker));
	else if (ft_strcmp(buf, "rra") == 0)
		return (reverserotatea(checker));
	else if (ft_strcmp(buf, "rrb") == 0)
		return (reverserotateb(checker));
	else if (ft_strcmp(buf, "rrr") == 0)
		return (reverserotatea(checker) && reverserotateb(checker));
	return (-1);
}

int		main(int argc, char **argv)
{
	t_check				checkerr;
	int					pin;
	int					pin2;

	if (argc == 1)
		my_putstr("Error\nMissing arguments");
	if (argc == 1)
		return (0);
	pin = stocktableau(&checkerr, argc, argv);
	if ((pin2 = checkargs(&checkerr, pin)) == 0)
	{
		free(checkerr.a);
		free(checkerr.b);
		return (0);
	}
	if (pin2 == -1)
		return (0);
	read_n_sort(&checkerr);
	free(checkerr.a);
	free(checkerr.b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:14:44 by jcluzet           #+#    #+#             */
/*   Updated: 2021/06/24 16:27:33 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push.h"

int	rr(t_check *checker)
{
	rotatea(checker, 0);
	rotateb(checker, 0);
	my_putstr("rr\n");
	return (0);
}

int	rrr(t_check *checker)
{
	reverserotatea(checker, 0);
	reverserotateb(checker, 0);
	my_putstr("rrr\n");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:15:40 by jcluzet           #+#    #+#             */
/*   Updated: 2021/04/29 03:03:56 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void  ft_putnbr(int nb)
{
  if (nb < 0)
   {
     ft_putchar('-');
     nb = nb * -1;
   }
  if (nb >= 10)
   {
     ft_putnbr(nb / 10);
     ft_putnbr(nb % 10);
   }
  else
   {
     ft_putchar('0' + nb);
   }
}


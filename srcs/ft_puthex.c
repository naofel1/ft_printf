/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabentay <nabentay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:51:06 by nabentay          #+#    #+#             */
/*   Updated: 2021/12/05 21:53:01 by nabentay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

void	ft_mputhex(t_print *tab, unsigned int n)
{
	int	conv;

	conv = n % 16;
	if (n > 15)
		ft_mputhex(tab, n / 16);
	if (conv > 9)
	{
		conv = 'A' + (conv - 10);
		tab->tl += write(1, &conv, 1);
	}
	else
		ft_putnbr(tab, conv);
}

void	ft_puthex(t_print *tab, unsigned int n)
{
	int	conv;

	conv = n % 16;
	if (n > 15)
		ft_puthex(tab, n / 16);
	if (conv > 9)
	{
		conv = 'a' + (conv - 10);
		tab->tl += write(1, &conv, 1);
	}
	else
		ft_putnbr(tab, conv);
}

void	ft_puthex_ptr(t_print *tab, long long unsigned int n)
{
	int	conv;

	conv = n % 16;
	if (n > 15)
		ft_puthex_ptr(tab, n / 16);
	if (conv > 9)
	{
		conv = 'a' + (conv - 10);
		tab->tl += write(1, &conv, 1);
	}
	else
		ft_putnbr(tab, conv);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabentay <nabentay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:18:53 by nabentay          #+#    #+#             */
/*   Updated: 2021/12/05 21:58:31 by nabentay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putnbr(t_print *tab, int n)
{
	if (n == -2147483648)
		tab->tl += write(1, &"-2147483648", 11);
	else if (n < 0)
	{
		tab->tl += write(1, "-", 1);
		ft_putnbr(tab, -n);
	}
	else if (n > 9)
	{
		ft_putnbr(tab, n / 10);
		n = n % 10 + '0';
		tab->tl += write(1, &n, 1);
	}
	else
	{
		n += '0';
		tab->tl += write(1, &n, 1);
	}
}

void	ft_uputnbr(t_print *tab, unsigned int n)
{
	if (n > 9)
	{
		ft_putnbr(tab, n / 10);
		n = n % 10 + '0';
		tab->tl += write(1, &n, 1);
	}
	else
	{
		n += '0';
		tab->tl += write(1, &n, 1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabentay <nabentay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:57:10 by nabentay          #+#    #+#             */
/*   Updated: 2022/07/30 21:51:00 by nabentay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

void	ft_print_hex(t_print *tab)
{
	int	nb;

	nb = va_arg(tab->args, int);
	if (tab->sharp && nb)
	{
		tab->tl += write(1, &"0x", 2);
		tab->sharp = 0;
	}
	ft_puthex(tab, nb);
}

void	ft_print_hexx(t_print *tab)
{
	int	nb;

	nb = va_arg(tab->args, int);
	if (tab->sharp && nb)
	{
		tab->tl += write(1, &"0X", 2);
		tab->sharp = 0;
	}
	ft_mputhex(tab, nb);
}

void	ft_print_percent(t_print *tab)
{
	tab->tl += write(1, "%", 1);
}

void	ft_print_ptr(t_print *tab)
{
	void	*ptr;

	ptr = va_arg(tab->args, void *);
	ft_putptr(tab, ptr);
}

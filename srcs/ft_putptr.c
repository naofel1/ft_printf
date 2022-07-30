/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabentay <nabentay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:07:23 by nabentay          #+#    #+#             */
/*   Updated: 2022/07/30 21:49:40 by nabentay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putptr(t_print *tab, void *ptr)
{
	if (ptr == NULL)
	{
		tab->tl += write(1, &"(nil)", 5);
		return ;
	}
	tab->tl += write(1, &"0x", 2);
	ft_puthex_ptr(tab, (long unsigned)ptr);
}

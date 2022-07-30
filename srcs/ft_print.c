/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabentay <nabentay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:34:40 by nabentay          #+#    #+#             */
/*   Updated: 2022/07/24 21:12:26 by nabentay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_print_char(t_print *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	tab->tl += write(1, &c, 1);
}

void	ft_print_str(t_print *tab)
{
	char	*str;
	int		i;

	i = -1;
	str = va_arg(tab->args, char *);
	if (str == NULL)
	{
		tab->tl += write(1, "(null)", 6);
		return ;
	}
	while (str[++i])
		tab->tl += write(1, &str[i], 1);
}

void	ft_print_number(t_print *tab)
{
	int	nb;

	nb = va_arg(tab->args, int);
	if (tab->sign && nb >= 0)
		tab->tl += write(1, &"+", 1);
	else if (tab->sp && nb >= 0)
		tab->tl += write(1, &" ", 1);
	ft_putnbr(tab, nb);
}

void	ft_print_unumber(t_print *tab)
{
	unsigned int	nb;

	nb = va_arg(tab->args, unsigned int);
	ft_uputnbr(tab, nb);
}

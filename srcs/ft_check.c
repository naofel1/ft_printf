/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabentay <nabentay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:46:59 by nabentay          #+#    #+#             */
/*   Updated: 2021/12/06 01:43:00 by nabentay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_check(t_print *tab, const char *s, int i)
{
	while (s[i] == '+' || s[i] == ' ' || s[i] == '#')
	{
		if (s[i] == '+')
			tab->sign = 1;
		if (s[i] == ' ')
			tab->sp = 1;
		if (s[i] == '#')
			tab->sharp = 1;
		i++;
	}
	return (i);
}

int	ft_check_nb(t_print *tab, const char *s, int i)
{
	i = ft_check(tab, s, i);
	if (s[i] == 'c')
		ft_print_char(tab);
	else if (s[i] == 's')
		ft_print_str(tab);
	else if (s[i] == 'p')
		ft_print_ptr(tab);
	else if (s[i] == 'd' || s[i] == 'i')
		ft_print_number(tab);
	else if (s[i] == 'u')
		ft_print_unumber(tab);
	else if (s[i] == 'x')
		ft_print_hex(tab);
	else if (s[i] == 'X')
		ft_print_hexx(tab);
	else if (s[i] == '%')
		ft_print_percent(tab);
	else
	{
		tab->tl += write(1, " ", 1);
		i++;
	}
	return (i);
}

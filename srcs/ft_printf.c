/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabentay <nabentay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:22:52 by nabentay          #+#    #+#             */
/*   Updated: 2021/12/06 01:13:05 by nabentay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_print	*ft_initialise_tab(t_print *tab)
{
	tab->sign = 0;
	tab->tl = 0;
	tab->sharp = 0;
	tab->sp = 0;
	return (tab);
}

int	ft_printf(const char *s, ...)
{
	t_print	*tab;
	int		ret;
	int		i;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!s)
		return (-1);
	ft_initialise_tab(tab);
	va_start(tab->args, s);
	i = -1;
	ret = 0;
	while (s[++i])
	{
		if (s[i] == '%')
			i = ft_check_nb(tab, s, i + 1);
		else
			ret += write(1, &s[i], 1);
	}
	va_end(tab->args);
	ret += tab->tl;
	free (tab);
	return (ret);
}

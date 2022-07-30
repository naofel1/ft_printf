/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabentay <nabentay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:20:50 by nabentay          #+#    #+#             */
/*   Updated: 2022/07/30 22:08:32 by nabentay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_print
{
	va_list	args;
	int		tl;
	int		sign;
	int		sharp;
	int		sp;
}				t_print;

int		ft_printf(const char *s, ...);
void	ft_print_char(t_print *tab);
void	ft_print_str(t_print *tab);
int		ft_check(t_print *tab, const char *s, int i);
int		ft_check_nb(t_print *tab, const char *s, int i);
void	ft_print_number(t_print *tab);
void	ft_puthex(t_print *tab, unsigned int n);
void	ft_puthex_ptr(t_print *tab, long long unsigned int n);
void	ft_mputhex(t_print *tab, unsigned int n);
void	ft_print_hex(t_print *tab);
void	ft_print_hexx(t_print *tab);
void	ft_putnbr(t_print *tab, int n);
void	ft_print_unumber(t_print *tab);
void	ft_uputnbr(t_print *tab, unsigned int n);
void	ft_print_percent(t_print *tab);
void	ft_print_ptr(t_print *tab);
void	ft_putptr(t_print *tab, void *ptr);

#endif

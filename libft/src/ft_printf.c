/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:20:34 by bgauthie          #+#    #+#             */
/*   Updated: 2023/01/10 13:58:57 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	a;
	size_t	i;
	size_t	j;
	int		printed;

	printed = 0;
	va_start(a, str);
	j = ft_strlen(str);
	i = 0;
	while (i < j)
	{
		while (str[i] && str[i] != '%')
			ft_putchar_fd_pf(str[i++], &printed, 1);
		if (i + 1 < j)
		{
			get_type(str, a, &i, &printed);
			i++;
		}
		else
			i++;
	}
	va_end(a);
	return (printed);
}

void	get_type(const char *str, va_list a, size_t *i, int *printed)
{
	if (str[*i + 1] == 'c')
		ft_putchar_fd_pf(va_arg(a, int), printed, 1);
	if (str[*i + 1] == 's')
		ft_putstr_fd_pf(va_arg(a, char *), printed, 1);
	if (str[*i + 1] == 'p')
		ft_putptr_fd(va_arg(a, void *), "0123456789abcdef", printed, 1);
	if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
		ft_putnbr_base_fd(va_arg(a, int), "0123456789", printed, 1);
	if (str[*i + 1] == 'u')
		ft_putnbr_base_fd(va_arg(a, unsigned), "0123456789", printed, 1);
	if (str[*i + 1] == 'x')
		ft_putnbr_base_fd(va_arg(a, unsigned), "0123456789abcdef", printed, 1);
	if (str[*i + 1] == 'X')
		ft_putnbr_base_fd(va_arg(a, unsigned), "0123456789ABCDEF", printed, 1);
	if (str[*i + 1] == '%')
		ft_putchar_fd_pf('%', printed, 1);
	(*i) += 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:39:51 by bgauthie          #+#    #+#             */
/*   Updated: 2022/11/21 16:28:20 by bgauthie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenint(int nb)
{
	int	i;

	i = 1;
	while (nb / 10 != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static char	*ft_fill(char *a, int len, int n)
{
	if (n < 0)
	{
		a[0] = '-';
		a[len + 1] = '\0';
		n *= -1;
	}
	else
	{
		a[len] = '\0';
		len--;
	}
	if (n == 0)
		a[0] = '0';
	while (len != -1 && n != 0)
	{
		a[len] = n % 10 + 48;
		len--;
		n /= 10;
	}
	return (a);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*a;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_lenint(n);
	if (n < 0)
		a = malloc(sizeof(char) * len + 2);
	else
		a = malloc(sizeof(char) * len + 1);
	if (a == NULL)
		return (NULL);
	a = ft_fill(a, len, n);
	return (a);
}

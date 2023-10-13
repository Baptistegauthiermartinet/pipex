/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:08:23 by bgauthie          #+#    #+#             */
/*   Updated: 2022/11/25 16:37:54 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overflow(long long int n)
{
	if (n < 0)
		return (0);
	return (-1);
}

int	ft_atoi(const char *str)
{
	long long int	nbr;
	int				sgn;
	size_t			i;

	nbr = 0;
	sgn = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] != '+' && str[i] != '-' && ft_isdigit(str[i]) != 1)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sgn = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nbr != (nbr * 10 + str[i] - 48) / 10)
			return (ft_overflow(nbr));
		nbr = nbr * 10 + str[i] - 48;
		i++;
	}
	return (nbr * sgn);
}

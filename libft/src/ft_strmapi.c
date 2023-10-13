/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:39:05 by bgauthie          #+#    #+#             */
/*   Updated: 2022/11/22 14:07:39 by bgauthie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!f)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	j = 0;
	while (j < i)
	{
		new[j] = (*f)(j, s[j]);
		j++;
	}
	new[j] = '\0';
	return (new);
}

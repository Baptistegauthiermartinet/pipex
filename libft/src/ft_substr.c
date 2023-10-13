/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:21:42 by bgauthie          #+#    #+#             */
/*   Updated: 2022/11/23 17:11:09 by bgauthie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	s_size;
	size_t	i;

	s_size = ft_strlen(s);
	if (len == 0 || start >= s_size)
		return (ft_calloc(1, 1));
	if (len >= s_size - start)
		len = s_size - start;
	new = malloc(sizeof(char) * len + sizeof(char));
	if (!new)
		return (NULL);
	new[len] = '\0';
	i = 0;
	while (i < len)
	{
		new[i] = s[i + start];
		i++;
	}
	return (new);
}

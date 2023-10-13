/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:20:40 by bgauthie          #+#    #+#             */
/*   Updated: 2022/11/22 13:34:29 by bgauthie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	if (!*s1)
		return (ft_strdup(s1));
	while (*s1 && ft_strchr((char *)set, *s1))
		s1++;
	end = ft_strlen(s1);
	while (end && ft_strchr((char *)set, s1[end]))
		end--;
	return (ft_substr(s1, 0, end + 1));
}

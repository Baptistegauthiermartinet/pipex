/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:25:03 by bgauthie          #+#    #+#             */
/*   Updated: 2023/01/10 13:42:19 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_nocrash(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

size_t	ft_strchr_nl(const char *s, int c)
{
	size_t	i;

	if (!s || s[0] == '\0')
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		len;
	size_t	i;
	size_t	j;
	char	*new;

	len = ft_strlen_nocrash(s1) + ft_strlen_nocrash(s2);
	new = malloc(sizeof(char) * len + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	s_size;
	size_t	i;

	s_size = ft_strlen_nocrash(s);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:24:42 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/05 14:13:55 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*supp;
	char		*temp;
	char		*line;

	temp = NULL;
	line = NULL;
	if (fd < 0 || read(fd, temp, 0) < 0 || BUFFER_SIZE <= 0)
	{
		if (supp)
			free(supp);
		supp = NULL;
		return (NULL);
	}
	if (supp)
	{
		temp = join_and_free(temp, supp);
		free(supp);
	}
	temp = join_buffer(fd, temp);
	supp = stock_supp(temp);
	line = cut_temp(temp);
	if (temp)
		free(temp);
	return (line);
}

char	*join_and_free(char	*s1, char *s2)
{
	char	*new_line;

	if (!s1)
		s1 = ft_calloc(1, 1);
	if (!s1)
		return (NULL);
	new_line = ft_strjoin_gnl(s1, s2);
	if (s1)
		free(s1);
	return (new_line);
}

char	*join_buffer(int fd, char *str)
{
	char	*buffer;
	int		res;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	res = 1;
	while (!ft_strchr_nl(str, '\n') && res > 0)
	{
		res = read(fd, buffer, BUFFER_SIZE);
		if (res == -1)
		{
			free(buffer);
			if (str)
				free(str);
			return (NULL);
		}
		if (res == 0)
			break ;
		buffer[res] = '\0';
		str = join_and_free(str, buffer);
	}
	if (buffer)
		free(buffer);
	return (str);
}

char	*stock_supp(char *str)
{
	char	*new;
	size_t	i;
	size_t	start_idx;

	new = NULL;
	if (!str)
		return (new);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] != '\0')
		i++;
	start_idx = i;
	while (str[i] != '\0')
		i++;
	if (i == start_idx)
		return (NULL);
	new = ft_substr_gnl(str, start_idx, i - start_idx + 1);
	return (new);
}

char	*cut_temp(char	*str)
{
	size_t	i;
	size_t	j;
	char	*new;

	new = NULL;
	if (!str)
		return (new);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	new = malloc(sizeof(char) * i + sizeof(char));
	if (!new)
		return (NULL);
	j = 0;
	while (j < i)
	{
		new[j] = str[j];
		j++;
	}
	new[i] = '\0';
	return (new);
}

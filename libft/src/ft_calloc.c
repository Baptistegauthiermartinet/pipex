/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:23:19 by bgauthie          #+#    #+#             */
/*   Updated: 2023/01/10 15:23:22 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	if (count > 0 && (size != size * count / count))
		return (NULL);
	s = malloc(size * count);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, size * count);
	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:17:10 by bgauthie          #+#    #+#             */
/*   Updated: 2022/11/23 16:17:30 by bgauthie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	new = NULL;
	if (!lst || !del || !f)
		return (NULL);
	while (lst)
	{
		temp = ft_lstnew(f(lst -> content));
		if (!temp)
		{
			ft_lstclear(&temp, del);
			return (0);
		}
		ft_lstadd_back(&new, temp);
		lst = lst -> next;
	}
	return (new);
}

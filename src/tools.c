/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:44:03 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/13 18:11:28 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*is_access(t_data *data)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		if (!access(data->env[i], X_OK))
		{
			free(data->cmd_1[0]);	
			return (ft_strdup(data->env[i]));
		}
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:57:17 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/18 16:15:18 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*a virer*/
void	print_tab(char **tab)
{
	int i = 0;
	while (tab[i])
		ft_printf("%s\n", tab[i++]);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		i++;
	i--;
	while (i >= 0)
		free(tab[i--]);
	free(tab);
	return ;
}

void	free_struct(t_data *data)
{
	if (data->line)
		free(data->line);
	free_tab(data->env);
	free_tab(data->cmd_1);
	free_tab(data->cmd_2);
}

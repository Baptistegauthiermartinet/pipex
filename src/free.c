/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:57:17 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/19 16:38:39 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
	close(data->pipe[0]);
	close(data->pipe[1]);
}

void	print_error(char *msg, char *str, t_data *data)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	write(2, msg, ft_strlen(msg));
	if (data->pid_1 == 0 || data->pid_2 == 0)
		exit_son(data);
	exit(0);
}

void	print_perror(char *msg, t_data *data)
{
	perror(msg);
	if (data->pid_1 == 0)
		close(data->pipe[1]);
	if (data->pid_2 == 0)
		close(data->pipe[0]);
	if (data->pid_1 == 0 || data->pid_2 == 0)
		exit_son(data);
	exit(0);
}

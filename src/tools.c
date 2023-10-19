/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:44:03 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/19 15:18:15 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*if cmd file is reachable returns the cmd's path*/
char	*is_access(t_data *data, char **cmd)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		if (!access(data->env[i], X_OK))
		{
			free(cmd[0]);
			return (ft_strdup(data->env[i]));
		}
		i++;
	}
	data->valid = -1;
	return (cmd[0]);
}

/*Finds the line starting by 'PATH=/nfs' in environment and return the index*/
int	find_path_line(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (!ft_strncmp(tab[i], "PATH=/n", 7))
			return (i);
		i++;
	}
	return (0);
}

/*Trims the line, creates the env tab, creates the cmds tabs*/
void	trim_path_line(char **env, t_data *data, char **av)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strdup(env[find_path_line(env)]);
	data->line = ft_strtrim(str, "PATH=");
	free(str);
	data->env = ft_split(data->line, ':');
	data->cmd_1 = ft_split(av[2], ' ');
	data->cmd_2 = ft_split(av[3], ' ');
}

/*Adds cmd1 or cmd2 at the end of each tab's line*/
void	add_cmd_on_path(t_data *data, char *cmd)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		data->env[i] = join_and_free(data->env[i], "/");
		data->env[i] = join_and_free(data->env[i], cmd);
		i++;
	}
}

/*if arg already a valid path returns 1*/
int	is_access_path(char *str)
{
	if (str[0] == '/' && !access(str, X_OK))
		return (1);
	return (0);
}

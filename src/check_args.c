/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:37:01 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/13 17:59:47 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

bool	check_args(int ac, char **av)
{
	(void)av;
	if (ac != 5)
		return (false);
	return (true);
}

/*Finds the line starting by 'PATH=/nfs' in environment*/
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

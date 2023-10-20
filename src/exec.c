/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:10:42 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/20 13:15:26 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exit_son(t_data *data)
{
	if (data->infile_fd != -1)
		close(data->infile_fd);
	if (data->outfile_fd != -1)
		close(data->outfile_fd);
	free_struct(data);
	close(0);
	close(1);
	exit(0);
}

void	execute_pid_1(t_data *data)
{
	if (data->pid_1 == 0)
	{
		data->infile_fd = open(data->infile, O_RDONLY);
		if (data->infile_fd < 0)
			print_perror(data->infile, data);
		dup2(data->pipe[1], 1);
		close(data->pipe[0]);
		dup2(data->infile_fd, 0);
		if (is_access_path(data->cmd_1[0]) == 1)
			execve(data->cmd_1[0], data->cmd_1, data->env_d);
		else
		{
			add_cmd_on_path(data, data->cmd_1[0]);
			data->cmd_1[0] = is_access(data, data->cmd_1);
		}
		if (data->valid < 0)
			print_error(ERR_CMD, data->cmd_1[0], data);
		execve(data->cmd_1[0], data->cmd_1, data->env_d);
		exit_son(data);
	}
}

void	execute_pid_2(t_data *data)
{
	if (data->pid_2 == 0)
	{
		data->outfile_fd = open(data->outfile,
				O_TRUNC | O_CREAT | O_RDWR, 0000644);
		if (data->outfile_fd < 0)
			print_perror(data->outfile, data);
		dup2(data->pipe[0], 0);
		close(data->pipe[1]);
		dup2(data->outfile_fd, 1);
		if (is_access_path(data->cmd_2[0]) == 1)
			execve(data->cmd_2[0], data->cmd_2, data->env_d);
		else
		{
			add_cmd_on_path(data, data->cmd_2[0]);
			data->cmd_2[0] = is_access(data, data->cmd_2);
		}
		if (data->valid < 0)
			print_error(ERR_CMD, data->cmd_2[0], data);
		execve(data->cmd_2[0], data->cmd_2, data->env_d);
		exit_son(data);
	}
}

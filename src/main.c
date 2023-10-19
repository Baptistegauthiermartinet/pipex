/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:25:37 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/19 16:32:24 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	set_struct(t_data *data, char **env, char **av)
{
	data->env_d = env;
	data->infile_fd = -1;
	data->outfile_fd = -1;
	data->valid = 1;
	data->infile = av[1];

	data->outfile = av[4];
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (argc == 5)
	{
		set_struct(&data, env, argv);
		if (pipe(data.pipe) < 0)
			print_perror(ERR_PIPE, &data);
		trim_path_line(env, &data, argv);
		data.pid_1 = fork();
		execute_pid_1(&data);
		data.pid_2 = fork();
		execute_pid_2(&data);
		close(data.pipe[0]);
		close(data.pipe[1]);
		waitpid(data.pid_1, 0, 0);
		waitpid(data.pid_2, 0, 0);
		free_struct(&data);
		return (1);
	}
	return (ft_printf(ERR_INPUT));
}

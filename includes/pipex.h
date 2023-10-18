/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:21:57 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/18 18:50:05 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include "../libft/src/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <wait.h>
# include <stdio.h>

typedef struct s_data
{
	char	**cmd_1;
	char	**cmd_2;
	char	*line;
	char	**env;
	char	**env_d;
	char	*infile;
	char	*outfile;
	int		infile_fd;
	int		outfile_fd;
	int		pid_1;
	int		pid_2;
	int		pipe[2];
}				t_data;

/*free.c*/
void	free_tab(char **tab);
void	free_struct(t_data *data);
void	print_tab(char **tab);

/*tools.c*/
char	*is_access(t_data *data, char **cmd);
int		find_path_line(char **tab);
void	trim_path_line(char **env, t_data *data, char **av);
void	add_cmd_on_path(t_data *data, char *cmd);

/*exec.c*/
void	execute_pid_1(t_data *data);
void	execute_pid_2(t_data *data);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:21:57 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/19 16:22:43 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include "../libft/src/libft.h"
# include <fcntl.h>
# include <wait.h>
# include <stdio.h>

# define ERR_INPUT "Error : Wrong number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_CMD "Command not found\n"

typedef struct s_data
{
	char	**cmd_1;
	char	**cmd_2;
	char	*path_1;
	char	*path_2;
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
	int		valid;
}				t_data;

/*free.c*/
void	free_tab(char **tab);
void	free_struct(t_data *data);
void	print_tab(char **tab);
void	print_error(char *msg, char *str, t_data *data);
void	print_perror(char *msg, t_data *data);

/*tools.c*/
char	*is_access(t_data *data, char **cmd);
int		find_path_line(char **tab);
void	trim_path_line(char **env, t_data *data, char **av);
void	add_cmd_on_path(t_data *data, char *cmd);
int		is_access_path(char *str);

/*exec.c*/
void	execute_pid_1(t_data *data);
void	execute_pid_2(t_data *data);
void	exit_son(t_data *data);

#endif
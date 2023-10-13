/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:25:37 by bgauthie          #+#    #+#             */
/*   Updated: 2023/10/13 18:01:19 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (!check_args(argc, argv))
		return (ft_printf("Error\n"));
	trim_path_line(env, &data, argv);
	add_cmd_on_path(&data, data.cmd_1[0]);
	data.cmd_1[0] = is_access(&data);

//	print_tab(data.env);
	// int i =0;
	// while (data.cmd_1[i])
	// 	ft_printf("%s\n", data.cmd_1[i++]);
//	char *k[3] = {is_access(&data), "test", NULL};
//	execve(data.cmd_1[0], data.cmd_1, env);
	free_struct(&data);
	return (1);
}


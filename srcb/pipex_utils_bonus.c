/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execvp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:36:07 by mugurel           #+#    #+#             */
/*   Updated: 2023/02/02 23:36:08 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../lib/libft/libft.h"

char	*find_path(char **ev)
{
	int32_t i;

	i = 0;
	while (ev[i])
	{
		if (ft_strncmp(ev[i], "PATH", 4) == 0)
			return (ev[i] + 5);
		i++;
	}
	return (NULL);
}

char	*find_cmd_path(char **ev, char *command)
{
	int32_t	i;
	char		*pathvar;
 	char		**paths;
 	char		*cmd;
	pathvar = find_path(ev);
 	paths = ft_split(pathvar, ':'); 
	i = 0;
 	while (paths[i])
 	{
		pathvar = ft_strjoin(paths[i], "/");
		cmd = ft_strjoin(pathvar, ft_split(command, ' ')[0]);
		free(pathvar);
		if (access(cmd, X_OK) == 0)
		{
			free(paths);
			return (cmd);	
		}
		free(cmd);
		i++;
 	}
	free(paths);
 	return (NULL);
}

char **cmd_args(char *av, char **ev)
{
	char **args;

	args = ft_split(av, ' ');
	free(args[0]);
	args[0] = find_cmd_path(ev, av);
	return (args);
}

void	mtu_fork(char **av, char **ev, int32_t pi[2], int8_t pos)
{
	static int16_t cmd_id = 2;
	
	if (pos == 1)
	{
		dup2(pi[1], STDOUT_FILENO);
		close(pi[0]);
		close(pi[1]);
		ft_putstr_fd(ft_atoi(cmd_id), 2);
		cmd_id++;
		execve(find_cmd_path(ev, av[cmd_id]) , ft_split(av[cmd_id], ' '), ev);
	}
	else if (pos == 2)
	{
		dup2(pi[0], STDIN_FILENO);
		dup2(pi[1], STDOUT_FILENO);
		close(pi[0]);
		close(pi[1]);
		ft_putstr_fd(ft_atoi(cmd_id), 2);
		cmd_id++;
		execve(find_cmd_path(ev, av[cmd_id]), ft_split(av[cmd_id], ' '), ev);
	}
	else
	{
		dup2(pi[0], STDIN_FILENO);
		close(pi[1]);
		close(pi[0]);
		ft_putstr_fd(ft_split(av[cmd_id], ' ')[0], 1);
		ft_putstr_fd(ft_split(av[cmd_id], ' ')[1], 1);
		ft_putstr_fd(ft_atoi(cmd_id), 2);
		cmd_id++;
		execve(find_cmd_path(ev, av[cmd_id]), ft_split(av[cmd_id], ' '), ev);
	}
}

void	handle_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(errno);
}

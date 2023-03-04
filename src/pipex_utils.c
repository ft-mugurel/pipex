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
	int32_t	i;

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
	int32_t		i;
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

void	handle_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(errno);
}

void	exec_fork1(char **av, char **ev, int32_t pi[2], int32_t pid)
{
	if (pid == -1)
		handle_error(strerror(errno));
	if (pid == 0)
	{
		dup2(pi[1], STDOUT_FILENO);
		close(pi[0]);
		close(pi[1]);
		execve(find_cmd_path(ev, av[2]), ft_split(av[2], ' '), ev);
	}
}

void	exec_fork2(char **av, char **ev, int32_t pi[2], int32_t pid)
{
	if (pid == -1)
		handle_error(strerror(errno));
	if (pid == 0)
	{
		dup2(pi[0], STDIN_FILENO);
		close(pi[1]);
		close(pi[0]);
		execve(find_cmd_path(ev, av[3]), ft_split(av[3], ' '), ev);
	}
}

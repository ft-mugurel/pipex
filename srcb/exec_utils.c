/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:36:07 by mugurel           #+#    #+#             */
/*   Updated: 2023/02/02 23:36:08 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"
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
	int32_t	i;
	char	*pathvar;
	char	**paths;
	char	*cmd;

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

char	**cmd_args(char *av, char **ev)
{
	char	**args;

	args = ft_split(av, ' ');
	free(args[0]);
	args[0] = find_cmd_path(ev, av);
	return (args);
}

void	mtu_fork(char *av, char **ev)
{
	if (execve(find_cmd_path(ev, av), ft_split(av, ' '), ev) == -1)
		handle_error(strerror(errno));
}

void	cmd_pos(t_pipe *pip, char **av, char **ev)
{
	if (pip->i == 2)
	{
		if (dup2(pip->pi[1], STDOUT_FILENO) == -1)
			handle_error(strerror(errno));
		close_pipes(pip);
		mtu_fork(av[pip->i], ev);
	}
	else if (pip->i == pip->ac - 2)
	{
		if (dup2(pip->pi[(2 * (pip->i - 2)) - 2], STDIN_FILENO) == -1)
			handle_error(strerror(errno));
		close_pipes(pip);
		mtu_fork(av[pip->i], ev);
	}
	else
	{
		if (dup2(pip->pi[(2 * (pip->i - 2)) - 2], STDIN_FILENO) == -1)
			handle_error(strerror(errno));
		if (dup2(pip->pi[(2 * (pip->i - 2)) + 1], STDOUT_FILENO) == -1)
			handle_error(strerror(errno));
		close_pipes(pip);
		mtu_fork(av[pip->i], ev);
	}
}

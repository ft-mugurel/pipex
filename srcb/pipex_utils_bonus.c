/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:36:07 by mugurel           #+#    #+#             */
/*   Updated: 2023/02/02 23:36:08 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"
#include "../lib/libft/libft.h"

void	creat_pipes(t_pipe *pip)
{
	int	i;

	i = 0;
	while (i < pip->pi_num)
	{
		if (pipe(pip->pi + 2 * i) == -1)
		{
			free(pip->pi);
			handle_error(strerror(errno));
		}
		i++;
	}
}

void	close_pipes(t_pipe *pip)
{
	int	i;

	i = 0;
	while (i < (pip->pi_num * 2))
	{
		close(pip->pi[i]);
		i++;
	}
}

void	pipex_preparation(t_pipe *pip, int ac, char **av)
{
	int	error;

	pip->fd1 = open(av[1], O_RDONLY);
	error = dup2(pip->fd1, STDIN_FILENO);
	pip->fd2 = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	error = dup2(pip->fd2, STDOUT_FILENO);
	if (error == -1 || pip->fd1 == -1 || pip->fd2 == -1)
		handle_error(strerror(errno));
	pip->i = 2;
	pip->cmd_num = ac - 3;
	pip->pi_num = ac - 4;
	pip->pi = (int *)malloc(sizeof(int) * (pip->pi_num * 2));
	if (!pip->pi)
		handle_error("Allocation fail");
	creat_pipes(pip);
}

int	here_doc_check(char **av)
{
	if (ft_strncmp(av[1], "here_doc", 8))
		return (1);
	else
		return (0);
}

int	here_doc_check(char **av)
{
}

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

int	main(int ac, char **av, char **ev)
{
	int32_t	i;
	int32_t	error;
	int32_t	pid;
	int32_t	fd1;
	int32_t	fd2;
	t_pipe pip;

	if (ac < 5)
		handle_error("Usage => pipex file1 command1 command2 file2");
	fd1 = open(av[1], O_RDONLY);
	error = dup2(fd1, STDIN_FILENO);
	fd2 = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	error = dup2(fd2, STDOUT_FILENO);
	if (error == -1 || fd1 == -1 || fd2 == -1)
		handle_error(strerror(errno));
	pip.cmd_num = ac - 3;
	pip.pi_num = ac - 4;
	pip.pi = (int *)malloc(sizeof(int) * (pip.pi_num * 2));
	if(!pip.pi)
		handle_error("Allocation fail");
	creat_pipes(&pip);
	i = 2;
	while (i < ac - 1)
	{
		pid = fork();
		if (pid == -1)
			handle_error(strerror(errno));
		if (pid == 0)
		{
			if (i == 2)
			{
				dup2(pip.pi[1], STDOUT_FILENO);
				close_pipes(&pip);
				mtu_fork(av[i], ev);
			}
			else if (i == ac - 2)
			{
				dup2(pip.pi[(2 * (i - 2)) - 2], STDIN_FILENO);
				close_pipes(&pip);
				mtu_fork(av[i], ev);
			}
			else
			{
				dup2(pip.pi[(2 * (i - 2)) - 2], STDIN_FILENO);
				dup2(pip.pi[(2 * (i - 2)) + 1], STDOUT_FILENO);
				close_pipes(&pip);
				mtu_fork(av[i], ev);
			}
		}
		close(pid);
		i++;
	}
	close_pipes(&pip);
	close(fd1);
	close(fd2);
	waitpid(pid, NULL, 0);
	return (0);
}

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
	t_pipe	pip;

	if (ac < 5)
		handle_error("Usage => pipex file1 command1 command2 file2");
	if (!here_doc_check(av))
	{
		//here_doc fonction
	}
	else
	{
		pipex_preparation(&pip, ac, av);
		pip.ac = ac;
		while (pip.i < ac - 1)
		{
			pip.pid = fork();
			if (pip.pid == -1)
				handle_error(strerror(errno));
			if (pip.pid == 0)
			{
				cmd_pos(&pip, av, ev);
			}
			close(pip.pid);
			pip.i++;
		}
		close_pipes(&pip);
		close(pip.fd1);
		close(pip.fd2);
		waitpid(pip.pid, NULL, 0);
	}
	return (0);
}

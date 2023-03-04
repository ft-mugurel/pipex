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

#include "../include/pipex.h"
#include "../lib/libft/libft.h"

int	main(int ac, char **av, char **ev)
{
	int32_t	error;
	t_pipe	pip;

	if (ac < 5)
		handle_error("Usage => pipex file1 command1 command2 file2");
	error = pipe(pip.pi);
	pip.fd1 = open(av[1], O_RDONLY);
	error = dup2(pip.fd1, STDIN_FILENO);
	pip.fd2 = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	error = dup2(pip.fd2, STDOUT_FILENO);
	if (error == -1 || pip.fd1 == -1 || pip.fd2 == -1)
		handle_error(strerror(errno));
	pip.pid1 = fork();
	exec_fork1(av, ev, pip.pi, pip.pid1);
	pip.pid2 = fork();
	exec_fork2(av, ev, pip.pi, pip.pid2);
	close(pip.pi[0]);
	close(pip.pi[1]);
	waitpid(pip.pid1, NULL, 0);
	waitpid(pip.pid2, NULL, 0);
	return (0);
}

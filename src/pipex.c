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
	int32_t	pi[2];
	int32_t	pid1;
	int32_t	pid2;
	int32_t	fd1;
	int32_t	fd2;

	if (ac < 5)
		handle_error("Usage => pipex file1 command1 command2 file2");
	error = pipe(pi);
	fd1 = open(av[1], O_RDONLY);
	error = dup2(fd1, STDIN_FILENO);
	fd2 = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	error = dup2(fd2, STDOUT_FILENO);
	if (error == -1 || fd1 == -1 || fd2 == -1)
		handle_error(strerror(errno));
	pid1 = fork();
	if (pid1 == -1)
		handle_error(strerror(errno));
	if (pid1 == 0)
	{
		dup2(pi[1], STDOUT_FILENO);
		close(pi[0]);
		close(pi[1]);
		execve(find_cmd_path(ev, av[2]) , ft_split(av[2], ' '), ev);
	}
	pid2 = fork();
	if (pid2 == -1)
		handle_error(strerror(errno));
	if (pid2 == 0)
	{
		dup2(pi[0], STDIN_FILENO);
		close(pi[1]);
		close(pi[0]);
		execve(find_cmd_path(ev, av[3]), ft_split(av[3], ' '), ev);
	}
	close(pi[0]);
	close(pi[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

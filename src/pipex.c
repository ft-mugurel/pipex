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


void	handle_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(errno);
}

int	main(int ac, char **av, char **ev)
{
	int	error;
	int	pi[2];
	int	pid1;
	int	pid2;

	find_path(ev);
	if (ac < 4)
		handle_error("Usage => pipex file1 command1 command2 file2");
	error = pipe(pi);
	error = access(av[1], R_OK);
	error = access(av[ac], R_OK);
	if (error == -1)
		handle_error(strerror(errno));
	pid1 = fork();
	if (pid1 == -1)
		handle_error(strerror(errno));
	if (pid1 == 0)
	{
		dup2(pi[1], STDOUT_FILENO);
		close(pi[0]);
		close(pi[1]);
		execlp("ping", "ping", "-c", "5", "google.com", NULL);
	}
	pid2 = fork();
	if (pid2 == -1)
		handle_error(strerror(errno));
	if (pid2 == 0)
	{
		dup2(pi[0], STDIN_FILENO);
		close(pi[0]);
		close(pi[1]);
		execlp("grep", "grep", "rtt", NULL);
	}
	close(pi[0]);
	close(pi[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:36:07 by mugurel           #+#    #+#             */
/*   Updated: 2023/02/02 23:36:08 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>

typedef struct t_list
{
	int32_t	pi[2];
	int32_t	pid1;
	int32_t	pid2;
	int32_t	fd1;
	int32_t	fd2;
}			t_pipe;

char	*find_path(char **ev);
char	*find_cmd_path(char **ev, char *command);
void	handle_error(char *str);
void	exec_fork1(char **av, char **ev, int32_t pi[2], int32_t pid);
void	exec_fork2(char **av, char **ev, int32_t pi[2], int32_t pid);

#endif

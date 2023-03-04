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
	int32_t	*pi;
	int32_t	cmd_num;
	int32_t	pi_num;
	int32_t	pid;
	int32_t	fd1;
	int32_t	fd2;
}			t_pipe;

char	*find_path(char **ev);
char	*find_cmd_path(char **ev, char *command);
void	handle_error(char *str);
void	mtu_fork(char *av, char **ev);
void	creat_pipes(t_pipe *pip);
void	close_pipes(t_pipe *pip);

#endif

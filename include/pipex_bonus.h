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

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
	int32_t	i;
	int32_t	ac;
}			t_pipe;

char	*find_path(char **ev);
char	*find_cmd_path(char **ev, char *command);
void	cmd_pos(t_pipe *pip, char **av, char **ev);
void	handle_error(char *str);
void	mtu_fork(char *av, char **ev);
void	creat_pipes(t_pipe *pip);
void	close_pipes(t_pipe *pip);
void	pipex_preparation(t_pipe *pip, int ac, char **av);
int		here_doc_check(char **av);
void	pipex(int ac, char **av, char **ev, t_pipe pip);
void	here_doc(char **av);

#endif

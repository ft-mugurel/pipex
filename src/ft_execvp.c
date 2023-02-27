/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execvp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:36:07 by mugurel           #+#    #+#             */
/*   Updated: 2023/02/02 23:36:08 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../lib/libft/libft.h"

char	*find_path(char **ev)
{
	int i;

	i = 0;
	while (ev[i])
	{
		if (ft_strncmp(ev[i], "PATH", 4) == 0)
			return (ev[i]);
		i++;
	}
	return (1);
}

char	*find_cmd_path(char **ev, char *cmd)
{
	int		i;
	char	*pathvar;
 	char	**paths;
 	char	**cmdargs;
	pathvar = find_path(ev);
 	paths = ft_split(pathvar, ":"); 
 	cmdargs = ft_split(cmd, " ");
	i = 0;
 	while (mypaths[i])
 	{
 	    cmd = ft_join(paths[i], ag[2]);
 	    free(cmd);
			i++;
 	}
 	return (0);
}

void	execvp(char **ev, char *cmd)
{
}

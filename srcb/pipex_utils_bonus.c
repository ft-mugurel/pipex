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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:09:07 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/11/19 19:28:10 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pipes(t_minishell *s)
{
	pid_t	id;

	pipe(s->fd);
	id = fork();
	if (id == 0)
	{
		dup2(s->fd[WRITE_END], STDOUT_FILENO);
		ft_cases(s);
		exit(0);
	}
	else if (id > 0)
	{
		waitpid(id, &(s->status), 0);
		s->status = (s->status / 256);
		close(s->fd[WRITE_END]);
		dup2(s->fd[READ_END], STDIN_FILENO);
		close(s->fd[READ_END]);
	}
	else
	{
		perror("fork");
		exit(1);
	}
}

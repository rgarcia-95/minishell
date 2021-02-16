/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:25:56 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/12/15 20:31:47 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_redir_mayor_mayor(t_minishell *s, char *str)
{
	int	fd;

	fd = open(str, O_CREAT | O_APPEND | O_WRONLY, 0640);
	if (fd < 0)
		perror("open with >>");
	else
	{
		dup2(fd, 1);
		ft_cases(s);
		ft_reset_pipes(s);
	}
	close(fd);
	s->it = s->it->next;
}

static void	ft_redir_minor_pipe(t_minishell *s)
{
	pid_t	id;

	pipe(s->fd);
	id = fork();
	if (id == 0)
	{
		s->fd[READ_END] = open(s->it->content, O_RDONLY, 0640);
		dup2(s->fd[READ_END], STDIN_FILENO);
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

static void	ft_redir_minor_redirs(t_minishell *s, t_node *node)
{
	if (node->r_red_may)
		s->fd[WRITE_END] = open(node->next->content,
		O_CREAT | O_TRUNC | O_WRONLY, 0777);
	else
		s->fd[WRITE_END] = open(node->next->content,
		O_CREAT | O_APPEND | O_WRONLY, 0640);
	if (s->fd[WRITE_END] < 0)
		perror("redir with pipe");
	else
	{
		dup2(s->fd[READ_END], STDIN_FILENO);
		dup2(s->fd[WRITE_END], STDOUT_FILENO);
		ft_cases(s);
		close(s->fd[READ_END]);
		close(s->fd[WRITE_END]);
		s->it = s->it->next;
	}
}

void		ft_redir_minor(t_minishell *s)
{
	s->fd[READ_END] = open(s->it->content, O_RDONLY, 0640);
	if (s->fd[READ_END] < 0)
		perror("open with redir <");
	else
	{
		if (s->it->r_red_may || s->it->r_red_maymay)
			ft_redir_minor_redirs(s, s->it);
		else if (s->it->r_pipe)
			ft_redir_minor_pipe(s);
		else
		{
			dup2(s->fd[READ_END], 0);
			ft_cases(s);
			close(s->fd[READ_END]);
		}
	}
}

void		ft_redir_mayor(t_minishell *s, char *str)
{
	int	fd;

	fd = open(str, O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if (fd < 0)
		perror("open with >");
	else
	{
		dup2(fd, 1);
		ft_cases(s);
		ft_reset_pipes(s);
	}
	close(fd);
	s->it = s->it->next;
}

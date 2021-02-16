/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:05:31 by rgarcia-          #+#    #+#             */
/*   Updated: 2021/02/16 12:34:52 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_env(t_minishell *s)
{
	int	i;

	i = 0;
	while (s->env[i])
	{
		ft_putstr_fd(s->env[i++], 1);
		ft_putstr_fd("\n", 1);
	}
	s->status = 0;
}

void		ft_not_found(t_minishell *s)
{
	ft_putstr_fd("bash: ", 1);
	ft_putstr_fd(s->commands[0], 1);
	ft_putstr_fd(": command not found", 1);
	ft_putstr_fd("\n", 1);
	exit(127);
}

static void	ft_other_commands(t_minishell *s, int i, int j)
{
	pid_t	id;

	id = fork();
	if (id == 0)
		ft_aux_commands(s, i, j);
	else
	{
		signal(SIGINT, ft_signal_c1);
		signal(SIGQUIT, ft_signal_quit);
		waitpid(id, &(s->status), 0);
		s->status = (s->status / 256);
	}
}

void		ft_cases(t_minishell *s)
{
	if (!ft_strncmp(s->commands[0], "echo\0", 5))
		ft_echo(s, 0, 0);
	else if (!ft_strncmp(s->commands[0], "cd\0", 3))
		ft_cd(s);
	else if (!ft_strncmp(s->commands[0], "pwd\0", 4))
		ft_pwd(s);
	else if (!ft_strncmp(s->commands[0], "export\0", 7))
		ft_export(s, 0);
	else if (!ft_strncmp(s->commands[0], "unset\0", 6))
		ft_unset(s, 0);
	else if (!ft_strncmp(s->commands[0], "env\0", 4))
		ft_env(s);
	else if (!ft_strncmp(s->commands[0], "exit\0", 5))
		ft_exit(s, -1);
	else
		ft_other_commands(s, -1, -1);
}

void		ft_parse_commands(t_list_ms *list, t_minishell *s)
{
	s->it = list->first;
	while (s->it != NULL)
	{
		s->commands = ft_split_2(s->it->content);
		if (s->it->r_pipe)
			ft_pipes(s);
		else if (s->it->r_red_may || s->it->r_red_min
		|| s->it->r_red_maymay)
		{
			if (s->it->r_red_may)
				ft_redir_mayor(s, s->it->next->content);
			else if (s->it->r_red_min)
			{
				while (s->it->r_red_min)
					s->it = s->it->next;
				ft_redir_minor(s);
			}
			else if (s->it->r_red_maymay)
				ft_redir_mayor_mayor(s, s->it->next->content);
		}
		else if (s->commands[0])
			ft_cases(s);
		ft_free_matrix(s->commands);
		s->it = s->it->next;
	}
}

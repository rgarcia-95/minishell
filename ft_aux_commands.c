/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 17:07:47 by rgarcia-          #+#    #+#             */
/*   Updated: 2021/02/05 13:39:29 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_frees_aux_commands(char *arg)
{
	free(arg);
	arg = NULL;
}

static void	ft_check_j(int j, t_minishell *s)
{
	if (j != 0)
		ft_not_found(s);
}

static void	ft_aux_pwd(t_minishell *s)
{
	int	i;

	i = 0;
	s->pwd = NULL;
	while (s->env[i])
	{
		if (!ft_strncmp(s->env[i], "PWD=", 4))
			s->pwd = ft_strdup(s->env[i] + 4);
		i++;
	}
	if (s->pwd != NULL)
	{
		s->aux_path = ft_strjoin(s->pwd, &(s->commands[0][1]));
		free(s->pwd);
		s->pwd = NULL;
	}
}

static void	ft_aux_aux(t_minishell *s, int i)
{
	s->aux = ft_strjoin(s->path[i], "/");
	s->aux_path = ft_strjoin(s->aux, s->commands[0]);
	ft_frees_aux_commands(s->aux);
}

void		ft_aux_commands(t_minishell *s, int i, int j)
{
	while (s->path && s->path[++i])
	{
		if (s->commands[0][0] == '.' && s->commands[0][1] == '/')
		{
			ft_aux_pwd(s);
			if (!(j = execve(s->aux_path, s->commands, s->env)))
				break ;
			ft_frees_aux_commands(s->aux_path);
		}
		else if (s->commands[0][0] == '/')
		{
			if (!(j = execve(s->commands[0], s->commands, s->env)))
				break ;
		}
		else
		{
			ft_aux_aux(s, i);
			if (!(j = execve(s->aux_path, s->commands, s->env)))
				break ;
			ft_frees_aux_commands(s->aux_path);
		}
	}
	ft_check_j(j, s);
}

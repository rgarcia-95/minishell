/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:10:38 by javrodri          #+#    #+#             */
/*   Updated: 2021/02/02 15:39:53 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cd_error(t_minishell *s)
{
	ft_putstr_fd("bash: cd: ", 1);
	ft_putstr_fd(s->commands[1], 1);
	ft_putstr_fd(": No such file or directory\n", 1);
	s->status = 1;
}

static int	ft_export_pwd(t_minishell *s, char *var)
{
	int	i;

	i = 0;
	while (s->env[i])
	{
		if (ft_find_string(s->env[i], var, s, i))
			break ;
		i++;
	}
	free(var);
	var = NULL;
	return (0);
}

static void	ft_cd_2(t_minishell *s)
{
	if (s->commands[1] && (ft_strncmp(s->commands[1], "~", 1)))
	{
		if (chdir(s->commands[1]))
			cd_error(s);
		else
		{
			ft_export_pwd(s, s->old_pwd);
			s->status = 0;
		}
		s->cwd = getcwd(s->cwd, sizeof(s->cwd));
		s->pwd = ft_strjoin("PWD=", s->cwd);
	}
	else
	{
		if (chdir(s->home))
			cd_error(s);
		else
		{
			ft_export_pwd(s, s->old_pwd);
			s->status = 0;
		}
		s->pwd = ft_strjoin("PWD=", s->home);
	}
	ft_export_pwd(s, s->pwd);
}

void		ft_cd(t_minishell *s)
{
	s->pwd = NULL;
	s->cwd = NULL;
	s->old_cwd = NULL;
	s->old_pwd = NULL;
	s->old_cwd = getcwd(s->old_cwd, sizeof(s->old_cwd));
	s->old_pwd = ft_strjoin("OLDPWD=", s->old_cwd);
	free(s->old_cwd);
	s->old_cwd = NULL;
	ft_cd_2(s);
	free(s->cwd);
	s->cwd = NULL;
}

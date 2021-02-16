/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:53:51 by javrodri          #+#    #+#             */
/*   Updated: 2021/02/08 11:37:35 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_show_prompt(t_minishell *s)
{
	signal(SIGINT, ft_signal_c);
	signal(SIGQUIT, ft_signal_c);
	ft_putstr_fd(PROMPT, 1);
	s->line = NULL;
	if (!get_next_line(0, &(s->line)))
		ft_signal_d(1);
	s->aux_args = ft_split3(s->line);
	free(s->line);
	s->line = NULL;
}

int			ft_get_path(t_minishell *s)
{
	int	i;

	i = 0;
	s->path = NULL;
	s->home = NULL;
	s->status = 0;
	while (s->env[i])
	{
		if (!ft_strncmp(s->env[i], "PATH=", 5))
			s->path = ft_split(s->env[i] + 5, ':');
		if (!ft_strncmp(s->env[i], "HOME=", 5))
			s->home = ft_strdup(s->env[i] + 5);
		i++;
	}
	return (0);
}

static void	ft_fill_matrix(t_minishell *s, char **env)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j])
		{
			s->env[i][j] = env[i][j];
			j++;
		}
		s->env[i][j] = 0;
		i++;
	}
	s->env[i] = 0;
	ft_get_path(s);
}

static int	ft_malloc_matrix(t_minishell *s, char **env)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
		i++;
	if (!(s->env = malloc(sizeof(char *) * (i + 1))))
		return (-1);
	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j])
			j++;
		if (!(s->env[i] = malloc(sizeof(char) * (j + 1))))
			return (-1);
		i++;
	}
	ft_fill_matrix(s, env);
	return (0);
}

int			main(int argc, char **argv, char **env)
{
	t_minishell	*s;
	t_list_ms	*list;

	(void)argc;
	(void)argv;
	if (!(s = malloc(sizeof(t_minishell))))
		return (-1);
	ft_malloc_matrix(s, env);
	while (1)
	{
		s->i = 0;
		ft_show_prompt(s);
		while (s->aux_args[s->i])
		{
			ft_init_pipes(s);
			list = ft_fill_lists(s->aux_args[s->i], s);
			ft_parse_commands(list, s);
			ft_free_lists(list);
			ft_reset_pipes(s);
			s->i++;
		}
		ft_free_matrix(s->aux_args);
	}
	return (0);
}

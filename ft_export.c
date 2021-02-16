/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:43:22 by rgarcia-          #+#    #+#             */
/*   Updated: 2021/02/16 12:35:08 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_export_replace(t_minishell *s, char *arg, int j)
{
	int		i;
	char	**temp;

	i = 0;
	while (s->env[i])
		i++;
	if (!(temp = malloc(sizeof(char *) * (i + 1))))
		return (-1);
	i = 0;
	while (s->env[i])
	{
		if (i == j)
			temp[i] = ft_strdup(arg);
		else
			temp[i] = ft_strdup(s->env[i]);
		i++;
	}
	temp[i] = 0;
	ft_free_matrix(s->env);
	s->env = temp;
	return (0);
}

static int	ft_export_add(t_minishell *s, char *arg)
{
	int		i;
	char	**temp;

	i = 0;
	while (s->env[i])
		i++;
	if (!(temp = malloc(sizeof(char *) * (i + 2))))
		return (-1);
	i = 0;
	while (s->env[i])
	{
		temp[i] = ft_strdup(s->env[i]);
		i++;
	}
	temp[i] = ft_strdup(arg);
	i++;
	temp[i] = 0;
	ft_free_matrix(s->env);
	s->env = temp;
	return (0);
}

int			ft_find_string(char *s1, char *s2, t_minishell *s, int j)
{
	int	i;

	i = 0;
	while (s2[i] != '=')
		i++;
	if (!ft_strncmp(s1, s2, ++i))
	{
		ft_export_replace(s, s2, j);
		return (1);
	}
	return (0);
}

int			ft_export(t_minishell *s, int z)
{
	int	i;
	int	j;

	while (s->commands[++z])
	{
		i = -1;
		j = 0;
		if (ft_strchr(s->commands[z], '='))
		{
			while (s->env[++i])
			{
				if ((j = ft_find_string(s->env[i], s->commands[z], s, i)) == 1)
					break ;
			}
			if (j == 0)
				ft_export_add(s, s->commands[z]);
			if (s->home)
				free(s->home);
			if (s->path)
				ft_free_matrix(s->path);
			ft_get_path(s);
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:24:33 by rgarcia-          #+#    #+#             */
/*   Updated: 2021/02/16 12:35:58 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_unset_delete(t_minishell *s, int i)
{
	int		j;
	int		z;
	char	**temp;

	j = 0;
	while (s->env[j])
		j++;
	if (!(temp = malloc(sizeof(char *) * j)))
		return (-1);
	j = 0;
	z = 0;
	while (s->env[z])
	{
		if (z == i)
			z++;
		else
			temp[j++] = ft_strdup(s->env[z++]);
	}
	temp[j] = 0;
	ft_free_matrix(s->env);
	s->env = temp;
	return (0);
}

static int	ft_find_string_unset(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '=')
		i++;
	if (i == ft_strlen(s2))
		if (!ft_strncmp(s1, s2, i))
			return (1);
	return (0);
}

int			ft_unset(t_minishell *s, int z)
{
	int	i;

	while (s->commands[++z])
	{
		i = 0;
		while (s->env[i])
		{
			if (ft_find_string_unset(s->env[i], s->commands[z]))
			{
				ft_unset_delete(s, i);
				break ;
			}
			i++;
		}
		if (s->home)
			free(s->home);
		if (s->path)
			ft_free_matrix(s->path);
		ft_get_path(s);
	}
	return (0);
}

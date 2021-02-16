/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 19:44:23 by rgarcia-          #+#    #+#             */
/*   Updated: 2021/02/02 16:38:50 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_frees(t_minishell *s, char *aux, char *aux2)
{
	free(s->commands[1]);
	s->commands[1] = NULL;
	if (aux != NULL)
		s->commands[1] = ft_strjoin(aux2, aux);
	else
		s->commands[1] = ft_strdup(aux2);
	if (aux != NULL)
	{
		free(aux);
		aux = NULL;
	}
	free(aux2);
	aux2 = NULL;
}

static void	ft_aux_dollar_1(t_minishell *s, size_t i)
{
	char	*aux;
	char	*aux2;
	size_t	size;

	aux = NULL;
	aux2 = NULL;
	while (s->commands[1][++i])
	{
		if (s->commands[1][i] == '$' && s->commands[1][i + 1] == '?')
			break ;
	}
	aux = ft_strndup(s->commands[1], i);
	aux2 = ft_strjoin(aux, ft_itoa(s->status));
	size = ft_strlen(aux);
	free(aux);
	aux = NULL;
	if (s->commands[1][size + 2])
		aux = ft_strdup(&(s->commands[1][size + 2]));
	ft_frees(s, aux, aux2);
}

static void	ft_exit_dollar(t_minishell *s)
{
	char	*aux;

	aux = NULL;
	if (s->commands[1][0] == '$' && s->commands[1][1] == '?')
	{
		if (s->commands[1][2])
			aux = ft_strdup(&(s->commands[1][2]));
		free(s->commands[1]);
		s->commands[1] = NULL;
		if (aux != NULL)
			s->commands[1] = ft_strjoin(ft_itoa(s->status), aux);
		else
			s->commands[1] = ft_itoa(s->status);
		if (aux != NULL)
		{
			free(aux);
			aux = NULL;
		}
	}
	else
		ft_aux_dollar_1(s, -1);
}

static void	ft_exit_aux(t_minishell *s, int j)
{
	while (s->commands[1][++j])
	{
		if (!ft_isdigit(s->commands[1][j]))
		{
			ft_putstr_fd("bash: exit: ", 1);
			ft_putstr_fd(s->commands[1], 1);
			ft_putstr_fd(": numeric argument required\n", 1);
			exit(255);
		}
	}
	if (s->commands[2])
	{
		ft_putstr_fd("bash: exit: too many arguments\n", 1);
		exit(1);
	}
}

void		ft_exit(t_minishell *s, int j)
{
	int	i;

	ft_putstr_fd("exit\n", 1);
	if (s->commands[1])
	{
		while (j != 1)
		{
			if (ft_strnstr(s->commands[1], "$?", ft_strlen(s->commands[1])))
				ft_exit_dollar(s);
			else
				j = 1;
		}
		if (!ft_strncmp(s->commands[1], "-", 1))
			j++;
		i = ft_atoi(s->commands[1]);
		ft_exit_aux(s, j);
		exit(i);
	}
	exit(s->status);
}

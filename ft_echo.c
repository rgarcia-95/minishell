/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:59:19 by rgarcia-          #+#    #+#             */
/*   Updated: 2021/02/02 18:37:19 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_cut_string(t_minishell *s, char *str)
{
	int		i;
	int		j;
	char	*aux;

	i = 1;
	while (str[i] && (str[i] != ' ' && str[i] != '$'))
		i++;
	if (!(aux = malloc(sizeof(char) * (i))))
		return (0);
	j = i - 1;
	i = 0;
	while (i < j)
	{
		aux[i] = str[i + 1];
		i++;
	}
	aux[i] = '\0';
	s->dolar = ft_strjoin(aux, "=");
	free(aux);
	aux = NULL;
	return (1);
}

static void	ft_dollar_env(t_minishell *s, int j, char *str)
{
	int	i;

	ft_cut_string(s, str);
	i = ft_strlen(s->dolar);
	while (s->env[j])
	{
		if (!ft_strncmp(s->env[j], s->dolar, i))
		{
			ft_putstr_fd(&(s->env[j][i]), 1);
			break ;
		}
		j++;
	}
	s->dollar_z += i;
}

static void	ft_dollar_int(t_minishell *s)
{
	ft_putnbr_fd(s->status, 1);
	s->dollar_z += 2;
}

static void	ft_dollar(char *str, t_minishell *s)
{
	while (str[s->dollar_z] != '\0' && ft_strnstr(&(str[s->dollar_z]),
	"$", ft_strlen(&(str[s->dollar_z]))))
	{
		while (str[s->dollar_z] != '$' || (str[s->dollar_z] == '$' &&
		(str[s->dollar_z + 1] == ' ' || str[s->dollar_z + 1] == '\0')))
		{
			ft_write_ms(1, str[s->dollar_z]);
			s->dollar_z++;
		}
		if (str[s->dollar_z] == '$' && str[s->dollar_z + 1] == '?')
			ft_dollar_int(s);
		else
			ft_dollar_env(s, 0, &(str[s->dollar_z]));
		if (s->dolar != NULL)
		{
			free(s->dolar);
			s->dolar = NULL;
		}
	}
	if (str[s->dollar_z] != '\0')
		ft_putstr_fd(&(str[s->dollar_z]), 1);
}

void		ft_echo(t_minishell *s, int i, int flag)
{
	s->dolar = NULL;
	while (s->commands[++i])
	{
		s->dollar_z = 0;
		if (!ft_strncmp(s->commands[i], "-n\0", 3))
		{
			if (i == 1)
				flag = 1;
		}
		else
		{
			if (ft_strnstr(s->commands[i], "$", ft_strlen(s->commands[i])))
				ft_dollar(s->commands[i], s);
			else
				ft_putstr_fd(s->commands[i], 1);
			if (s->commands[i + 1])
				ft_putstr_fd(" ", 1);
		}
	}
	if (!flag)
		ft_putstr_fd("\n", 1);
	s->status = 0;
}

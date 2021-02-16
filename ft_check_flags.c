/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 18:24:28 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/11/11 18:09:49 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_check_end(int j, char *str, t_minishell *s)
{
	if (str[j] == '|')
		s->flags[1] = '1';
	else if (str[j] == '<')
		s->flags[3] = '1';
	else if (str[j] == '>')
	{
		if (str[j + 1] == '>')
			s->flags[7] = '1';
		else
			s->flags[5] = '1';
	}
}

static void	ft_check_start(int i, char *str, t_minishell *s)
{
	if (str[i] == '|')
		s->flags[0] = '1';
	else if (str[i] == '<')
		s->flags[2] = '1';
	else if (str[i] == '>')
	{
		if (str[i + 1] == '>')
			s->flags[6] = '1';
		else
			s->flags[4] = '1';
	}
}

void		ft_check_flags(int i, int j, char *str, t_minishell *s)
{
	int	z;

	z = 0;
	while (z < 8)
		s->flags[z++] = '0';
	ft_check_start(i, str, s);
	ft_check_end(j, str, s);
}

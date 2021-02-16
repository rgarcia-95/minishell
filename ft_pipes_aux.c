/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:43:17 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/11/19 19:06:01 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_pipes(t_minishell *s)
{
	s->save[0] = dup(STDIN_FILENO);
	s->save[1] = dup(STDOUT_FILENO);
}

void	ft_reset_pipes(t_minishell *s)
{
	dup2(s->save[0], STDIN_FILENO);
	dup2(s->save[1], STDOUT_FILENO);
}

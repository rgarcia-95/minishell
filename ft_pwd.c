/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 20:20:39 by javrodri          #+#    #+#             */
/*   Updated: 2021/02/08 11:36:31 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_pwd(t_minishell *s)
{
	char	*cwd;

	cwd = NULL;
	if ((cwd = getcwd(cwd, sizeof(cwd))) != NULL)
	{
		ft_putstr_fd(cwd, 1);
		ft_putstr_fd("\n", 1);
	}
	else
		perror("getcwd() error");
	free(cwd);
	cwd = NULL;
	s->status = 0;
	return (0);
}

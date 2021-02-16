/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:31:11 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/12/17 20:25:25 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_signal_c1(int sign)
{
	if (sign == SIGINT)
		ft_putstr_fd("\n", 1);
}

void	ft_signal_c(int sign)
{
	if (sign == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		ft_putstr_fd(PROMPT, 1);
	}
}

void	ft_signal_quit(int sign)
{
	if (sign == SIGQUIT)
		ft_putstr_fd("Quit: 3\n", 1);
}

void	ft_signal_d(int sign)
{
	if (sign == 1)
	{
		ft_putstr_fd("\n", 1);
		ft_putstr_fd(PROMPT, 1);
		ft_putstr_fd("exit\n", 1);
		exit(0);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 19:42:43 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/10 19:45:36 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_write(unsigned int num, int fd)
{
	char	c;

	if (num / 10 > 0)
		ft_write(num / 10, fd);
	c = num % 10 + '0';
	write(fd, &c, sizeof(c));
}

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		num = (unsigned int)(n * -1);
		write(fd, "-", sizeof(char));
	}
	else
		num = (unsigned int)n;
	ft_write(num, fd);
}

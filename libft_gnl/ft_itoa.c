/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:26:22 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/10 18:36:20 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nums(unsigned int n)
{
	int	aux;

	aux = 1;
	while (n >= 10)
	{
		n /= 10;
		aux++;
	}
	return (aux);
}

char		*ft_itoa(int n)
{
	int				i;
	int				size;
	char			*s;
	unsigned int	num;

	i = 0;
	if (n < 0)
		num = (unsigned int)(n * -1);
	else
		num = (unsigned int)n;
	size = ft_nums(num);
	if (!(s = (char *)malloc(sizeof(char) * (size + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	if (n < 0 && (s[i] = '-'))
		size++;
	i = size - 1;
	while (num >= 10)
	{
		s[i--] = (char)(num % 10 + '0');
		num /= 10;
	}
	s[i] = (char)(num % 10 + '0');
	s[size] = '\0';
	return (s);
}

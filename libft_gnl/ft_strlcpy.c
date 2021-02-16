/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 20:20:11 by rgarcia-          #+#    #+#             */
/*   Updated: 2021/02/05 12:10:30 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	if (dst != 0 || src != 0)
	{
		while (src[size] != '\0')
			size++;
		if (dstsize > 0)
		{
			while (i < (dstsize - 1) && src[i] != '\0')
			{
				dst[i] = src[i];
				i++;
			}
			dst[i] = '\0';
		}
		return (size);
	}
	return (0);
}

size_t	ft_strlcpy_split_2(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 1;
	size = 0;
	if (dst != 0 || src != 0)
	{
		while (src[size] != '\0')
			size++;
		if (dstsize > 0)
		{
			while (i < (dstsize - 1) && src[i] != '\0')
			{
				dst[i] = src[j++];
				i++;
			}
			dst[i] = '\0';
		}
		return (size);
	}
	return (0);
}

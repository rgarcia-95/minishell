/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:02:31 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/10 18:06:43 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (s1 != 0 && s2 != 0)
	{
		i = ft_strlen(s1) + ft_strlen(s2) + 1;
		if (!(str = (char *)malloc(i)))
			return (0);
		i = 0;
		while (s1[i] != '\0')
		{
			str[i] = (char)s1[i];
			i++;
		}
		j = 0;
		while (s2[j] != '\0')
		{
			str[i + j] = (char)s2[j];
			j++;
		}
		str[i + j] = '\0';
		return (str);
	}
	return (0);
}

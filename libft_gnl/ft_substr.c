/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:58:18 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/10 18:02:03 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (s != 0)
	{
		if (!(str = (char *)malloc(len + 1)))
			return (0);
		if (start > ft_strlen(s))
			return (ft_strdup(""));
		while (i < len && s[start] != '\0')
		{
			str[i] = (char)s[start];
			start++;
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (0);
}

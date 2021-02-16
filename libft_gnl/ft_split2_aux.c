/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:44:36 by javrodri          #+#    #+#             */
/*   Updated: 2021/02/05 13:41:50 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init_split2_1(t_split2_1 *t)
{
	t->i = 0;
	t->aux = 0;
	t->flag_cs = 0;
	t->flag_cd = 0;
}

void	ft_init_split2_2(t_split2_2 *t, char const *s)
{
	t->i = -1;
	t->num_w = ft_num_w_split_2(s, ' ');
}

char	*ft_aux_malloc(char const *s, char *str, int i)
{
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	if (s[0] == '"' || s[0] == '\'')
		ft_strlcpy_split_2(str, s, i + 1);
	else
		ft_strlcpy(str, s, i + 1);
	return (str);
}

char	**ft_aux_split_2(char **str, char const *s, t_split2_2 *t)
{
	while (++(t->i) < t->num_w)
	{
		while (*s == ' ')
			s++;
		if (!(str[t->i] = ft_malloc_split_2(s, ' ', 0)))
		{
			while (t->i > 0)
				free(str[(t->i)--]);
			free(str);
			return (0);
		}
		if (*s == '"' || *s == '\'')
			s += (ft_strlen(str[t->i]) + 2);
		else
			s += ft_strlen(str[t->i]);
	}
	str[t->i] = 0;
	free(t);
	t = NULL;
	return (str);
}

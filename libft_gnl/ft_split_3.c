/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 20:01:55 by javrodri          #+#    #+#             */
/*   Updated: 2021/02/04 12:38:57 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_multiline(int aux, int flag_cs, int flag_cd)
{
	if (flag_cs == 1 || flag_cd == 1)
	{
		ft_putstr_fd("Multiline not accepted\n", 1);
		aux = 0;
	}
	return (aux);
}

static void		aux_num_w(char const *str, t_split3 *t)
{
	if (str[t->i] == '"')
	{
		t->i++;
		t->flag_cd = 1;
		while (str[t->i] != '"')
			t->i++;
		if (str[t->i] == '"')
		{
			t->i++;
			t->flag_cd = 0;
		}
	}
	else if (str[t->i] == '\'')
	{
		t->i++;
		t->flag_cs = 1;
		while (str[t->i] != '\'')
			t->i++;
		if (str[t->i] == '\'')
		{
			t->i++;
			t->flag_cs = 0;
		}
	}
}

static int		ft_num_w(char const *str, char c)
{
	int			z;
	t_split3	*t;

	if (!(t = malloc(sizeof(t_split3))))
		return (-1);
	ft_init_split3(t);
	while (str[t->i] != '\0')
	{
		aux_num_w(str, t);
		if (str[t->i] == c && t->i > 0)
		{
			while (str[t->i + 1] == ' ')
				t->i++;
			if (str[t->i + 1] != '\0')
				t->aux++;
		}
		if (str[t->i] != '\0' && (str[t->i] != '"' && str[t->i] != '\''))
			t->i++;
	}
	z = ft_multiline(t->aux, t->flag_cs, t->flag_cd);
	free(t);
	t = NULL;
	return (z);
}

static char		*ft_malloc1(char const *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != c)
	{
		if (s[i] == '"')
		{
			i++;
			while (s[i] != '"')
				i++;
		}
		else if (s[i] == '\'')
		{
			i++;
			while (s[i] != '\'')
				i++;
		}
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	ft_strlcpy(str, s, i + 1);
	return (str);
}

char			**ft_split3(char const *s)
{
	int		i;
	int		num_w;
	char	**str;

	if (s == 0)
		return (0);
	i = -1;
	num_w = ft_num_w(s, ';');
	if (!(str = (char **)malloc(sizeof(char *) * (num_w + 1))))
		return (0);
	while (++i < num_w)
	{
		while (*s == ';')
			s++;
		if (!(str[i] = ft_malloc1(s, ';')))
		{
			while (i > 0)
				free(str[i--]);
			free(str);
			return (0);
		}
		s += ft_strlen(str[i]);
	}
	str[i] = 0;
	return (str);
}

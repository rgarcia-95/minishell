/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:59:07 by javrodri          #+#    #+#             */
/*   Updated: 2021/02/05 13:41:43 by rgarcia-         ###   ########.fr       */
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

static void		aux_num_w(char const *s, t_split2_1 *t)
{
	if (s[t->i] == '"')
	{
		t->i++;
		t->flag_cd = 1;
		while (s[t->i] != '"')
			t->i++;
		if (s[t->i++] == '"')
		{
			t->flag_cd = 0;
			t->aux++;
		}
	}
	else if (s[t->i] == '\'')
	{
		t->i++;
		t->flag_cs = 1;
		while (s[t->i] != '\'')
			t->i++;
		if (s[t->i++] == '\'')
		{
			t->flag_cs = 0;
			t->aux++;
		}
	}
}

int				ft_num_w_split_2(char const *s, char c)
{
	int			z;
	t_split2_1	*t;

	if (!(t = malloc(sizeof(t_split2_1))))
		return (-1);
	ft_init_split2_1(t);
	while (s[t->i] != '\0')
	{
		aux_num_w(s, t);
		while (s[t->i] == c)
			t->i++;
		if (s[t->i] != '\0' && (s[t->i] != '"' && s[t->i] != '\'')
		&& s[t->i] != c)
		{
			t->aux++;
			while (s[t->i] != '\0' && (s[t->i] != '"' && s[t->i] != '\'')
			&& s[t->i] != c)
				t->i++;
		}
	}
	z = ft_multiline(t->aux, t->flag_cs, t->flag_cd);
	free(t);
	t = NULL;
	return (z);
}

char			*ft_malloc_split_2(char const *s, char c, int i)
{
	char	*str;

	str = NULL;
	if (s[i] == '"' || s[i] == '\'')
	{
		i++;
		if (s[i - 1] == '"')
		{
			while (s[i] != '"')
				i++;
		}
		else
		{
			while (s[i] != '\'')
				i++;
		}
		i--;
	}
	else
	{
		while (s[i] && s[i] != c && (s[i] != '"' && s[i] != '\''))
			i++;
	}
	return (ft_aux_malloc(s, str, i));
}

char			**ft_split_2(char const *s)
{
	char		**str;
	t_split2_2	*t;

	if (s == 0)
		return (0);
	if (!(t = malloc(sizeof(t_split2_2))))
		return (0);
	ft_init_split2_2(t, s);
	if (!(str = (char **)malloc(sizeof(char *) * (t->num_w + 1))))
		return (0);
	return (ft_aux_split_2(str, s, t));
}

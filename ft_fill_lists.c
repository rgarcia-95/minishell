/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_lists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:49:31 by rgarcia-          #+#    #+#             */
/*   Updated: 2021/02/05 14:06:13 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_node		*ft_new_node(char *str, t_minishell *s)
{
	t_node	*node;

	if (!(node = malloc(sizeof(t_node))))
		return (0);
	node->content = ft_strdup(str);
	node->next = NULL;
	node->l_pipe = s->flags[0] - '0';
	node->r_pipe = s->flags[1] - '0';
	node->l_red_min = s->flags[2] - '0';
	node->r_red_min = s->flags[3] - '0';
	node->l_red_may = s->flags[4] - '0';
	node->r_red_may = s->flags[5] - '0';
	node->l_red_maymay = s->flags[6] - '0';
	node->r_red_maymay = s->flags[7] - '0';
	return (node);
}

static void			ft_add_back(t_list_ms *list, char *str, t_minishell *s)
{
	t_node	*new;
	t_node	*iterator;

	new = ft_new_node(str, s);
	iterator = NULL;
	if (list->first == NULL)
		list->first = new;
	else
	{
		iterator = list->first;
		while (iterator->next != NULL)
			iterator = iterator->next;
		iterator->next = new;
	}
	list->size++;
}

static t_list_ms	*ft_new_list(void)
{
	t_list_ms	*list;

	if (!(list = malloc(sizeof(t_list_ms))))
		return (0);
	list->first = NULL;
	list->size = 0;
	return (list);
}

static char			*ft_get_content(int i, int j, char *s)
{
	int	size;

	if (s[i] == '|' || s[i] == '<' || s[i] == '>')
		i++;
	while (s[i] == ' ')
		i++;
	if (s[j] == '|' || s[j] == '<' || s[j] == '>')
		j--;
	while (s[j] == ' ')
		j--;
	size = (j - i) + 1;
	return (ft_substr(s, i, size));
}

t_list_ms			*ft_fill_lists(char *str, t_minishell *s)
{
	int			i;
	int			j;
	t_list_ms	*list;

	i = 0;
	j = 0;
	list = ft_new_list();
	while (str[j])
	{
		if (str[j] == '|' || str[j] == '<' || str[j] == '>' ||
		str[j + 1] == '\0')
		{
			s->content = NULL;
			s->content = ft_get_content(i, j, str);
			ft_check_flags(i, j, str, s);
			ft_add_back(list, s->content, s);
			if (str[j] == '>' && str[j + 1] == '>')
				j++;
			i = j;
			free(s->content);
			s->content = NULL;
		}
		j++;
	}
	return (list);
}

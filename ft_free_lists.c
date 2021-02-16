/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:10:02 by rgarcia-          #+#    #+#             */
/*   Updated: 2021/02/02 15:31:13 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_destroy_node(t_node *node)
{
	free(node->content);
	node->content = NULL;
	free(node);
	node = NULL;
}

static void	ft_remove_back(t_list_ms *list)
{
	t_node	*pop;
	t_node	*prev_position;

	pop = list->first;
	prev_position = NULL;
	if (list->first != NULL)
	{
		if (list->size > 1)
		{
			while (pop->next != NULL)
			{
				prev_position = pop;
				pop = pop->next;
			}
			prev_position->next = NULL;
		}
		else
			list->first = NULL;
		ft_destroy_node(pop);
		list->size--;
	}
}

void		ft_free_lists(t_list_ms *list)
{
	while (list->first != NULL)
		ft_remove_back(list);
	free(list);
	list = NULL;
}

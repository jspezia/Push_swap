/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 17:30:03 by jspezia           #+#    #+#             */
/*   Updated: 2014/03/05 19:12:09 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_destroy(t_list_node **begin)
{
	t_list_node	*cursor;
	t_list_node	*node_to_free;

	cursor = *begin;
	while (cursor)
	{
		node_to_free = cursor;
		cursor = cursor->next;
		free(node_to_free);
	}
}

void	list_clear(t_list_node **begin)
{
	t_list_node	*cursor;

	cursor = *begin;
	while (cursor)
	{
		free(cursor->value);
		cursor = cursor->next;
	}
}

void	list_clear_destroy(t_list_node **begin)
{
	list_clear(begin);
	list_destroy(begin);
}

void	*list_remove(t_list_node **begin, t_list_node *node)
{
	void			*del_node_value;
	t_list_node		*cursor;

	del_node_value = NULL;
	if (node == *begin)
		*begin = (*begin)->next;
	else
	{
		cursor = *begin;
		while (cursor)
		{
			if (cursor->next == node)
			{
				cursor->next = node->next;
				break ;
			}
			cursor = cursor->next;
		}
	}
	del_node_value = node->value;
	free(node);
	return (del_node_value);
}

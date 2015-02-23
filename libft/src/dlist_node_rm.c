/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_node_rm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 10:32:36 by jspezia           #+#    #+#             */
/*   Updated: 2015/02/23 11:25:17 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dlist.h"

static void		dlist_remove_first(t_dlist *dlist, t_dlist_node *node)
{
	dlist->first = node->next;
	dlist->first->prev = NULL;
}

static void		dlist_remove_last(t_dlist *dlist, t_dlist_node *node)
{
	dlist->last = node->prev;
	dlist->last->next = NULL;
}

static void		dlist_remove_middle(t_dlist_node *node)
{
	t_dlist_node		*tmp_next;
	t_dlist_node		*tmp_prev;

	tmp_next = node->next;
	tmp_prev = node->prev;
	tmp_next->prev = tmp_prev;
	tmp_prev->next = tmp_next;
}

void			*dlist_remove(t_dlist *dlist, t_dlist_node *node)
{
	void	*del_node_value;

	del_node_value = NULL;
	if (dlist->first && dlist->last && node)
	{
		if (node == dlist->first && node == dlist->last)
		{
			dlist->first = NULL;
			dlist->last = NULL;
		}
		else if (node == dlist->first)
			dlist_remove_first(dlist, node);
		else if (node == dlist->last)
			dlist_remove_last(dlist, node);
		else
			dlist_remove_middle(node);
		dlist->count--;
		del_node_value = node->value;
		free(node);
	}
	return (del_node_value);
}

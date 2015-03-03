/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 10:32:18 by jspezia           #+#    #+#             */
/*   Updated: 2015/02/23 16:08:23 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "dlist.h"

t_dlist		*dlist_create(void)
{
	t_dlist	*dlist;

	dlist = ft_memalloc(sizeof(t_dlist));
	if (!dlist)
	{
		error_msg("dlist create malloc fail");
		return (NULL);
	}
	return (dlist);
}

void		dlist_destroy(t_dlist *dlist)
{
	t_dlist_node		*cur;

	cur = dlist->first;
	while (cur != NULL)
	{
		if (cur->prev)
			free(cur->prev);
		cur = cur->next;
	}
	free(dlist->last);
	free(dlist);
}

void		dlist_clear(t_dlist *dlist)
{
	t_dlist_node		*cur;

	cur = dlist->first;
	while (cur != NULL)
	{
		free(cur->value);
		cur = cur->next;
	}
}

void		dlist_clear_destroy(t_dlist *dlist)
{
	dlist_clear(dlist);
	dlist_destroy(dlist);
}

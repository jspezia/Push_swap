/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:40:09 by jspezia           #+#    #+#             */
/*   Updated: 2015/02/23 16:23:39 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dlist.h"
#include "push_swap.h"

void		sa(t_list_ps *dlist)
{
	t_dlist_node	*swap;

	ft_putendl("sa");
	swap = dlist->a->first->next;
	if (swap->next)
		swap->next->prev = dlist->a->first;
	dlist->a->first->next = swap->next;
	dlist->a->first->prev = swap;
	swap->next = swap->prev;
	swap->prev = NULL;
	dlist->a->first = swap;
}

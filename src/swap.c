/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:40:09 by jspezia           #+#    #+#             */
/*   Updated: 2015/02/23 16:33:44 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dlist.h"
#include "push_swap.h"

void		sa(t_list_ps *list)
{
	t_dlist_node	*swap;

	ft_putendl("sa");
	swap = list->a->first->next;
	if (swap->next)
		swap->next->prev = list->a->first;
	list->a->first->next = swap->next;
	list->a->first->prev = swap;
	swap->next = swap->prev;
	swap->prev = NULL;
	list->a->first = swap;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:40:09 by jspezia           #+#    #+#             */
/*   Updated: 2015/02/23 16:08:20 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dlist.h"

void		sa(t_dlist *dlist)
{
	t_dlist_node	*swap;

	ft_putendl("sa");
	swap = dlist->first->next;
	swap->next->prev = dlist->first;
	dlist->first->next = swap->next;
	dlist->first->prev = swap;
	swap->next = swap->prev;
	swap->prev = NULL;
	dlist->first = swap;
}

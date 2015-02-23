/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:40:09 by jspezia           #+#    #+#             */
/*   Updated: 2015/02/23 18:02:54 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap(t_dlist *stack)
{
	t_dlist_node	*node1;
	t_dlist_node	*node2;
	t_dlist_node	*node3;

	if (stack->count < 2)
		return ;
	node1 = stack->first;
	node2 = node1->next;
	node3 = node2->next;
	if (node3)
		node3->prev = node1;
	else
		stack->last = node1;
	node1->next =  node3;
	node1->prev = node2;
	node2->next = node1;
	node2->prev = NULL;
	stack->first = node2;
}

void		push(t_dlist *stack_1, t_dlist *stack_2)
{
	if (stack_2->count)
		dlist_push_front(stack_1, dlist_pop_front(stack_2));
}

void		rotate(t_dlist *stack)
{
	if (stack->count)
		dlist_push_back(stack, dlist_pop_front(stack));
}

void		reverse(t_dlist *stack)
{
	if (stack->count)
		dlist_push_front(stack, dlist_pop_back(stack));
}


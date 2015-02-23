/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 10:31:38 by jspezia           #+#    #+#             */
/*   Updated: 2015/02/23 15:40:38 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLIST_H
# define DLIST_H

typedef struct			s_dlist_node
{
	struct s_dlist_node	*next;
	struct s_dlist_node	*prev;
	void				*value;
}						t_dlist_node;

typedef struct			s_dlist
{
	int				count;
	t_dlist_node	*first;
	t_dlist_node	*last;
}						t_dlist;

t_dlist					*dlist_create(void);
void					dlist_destroy(t_dlist *dlist);
void					dlist_clear(t_dlist *dlist);
void					dlist_clear_destroy(t_dlist *dlist);

void					dlist_push_back(t_dlist *dlist, void *value);
void					*dlist_pop_back(t_dlist *dlist);
void					dlist_push_front(t_dlist *dlist, void *value);
void					*dlist_pop_front(t_dlist *dlist);

void					*dlist_remove(t_dlist *dlist, t_dlist_node *node);

#endif

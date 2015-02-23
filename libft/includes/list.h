/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 16:27:03 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/24 18:55:32 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>
# include "libft.h"

typedef struct			s_list_node
{
	void				*value;
	struct s_list_node	*next;
}						t_list_node;

t_list_node				*list_push_back(t_list_node **begin, void *value);
void					*list_pop_back(t_list_node **begin);
void					list_push_front(t_list_node **begin, void *value);
void					*list_pop_front(t_list_node **begin);

void					list_destroy(t_list_node **begin);
void					list_clear(t_list_node **begin);
void					list_clear_destroy(t_list_node **begin);
void					*list_remove(t_list_node **begin, t_list_node *node);

#endif

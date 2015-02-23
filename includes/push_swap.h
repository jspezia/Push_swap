/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:49:56 by jspezia           #+#    #+#             */
/*   Updated: 2015/02/23 18:18:27 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include "dlist.h"
#include <stdlib.h>
#include <unistd.h>

void		swap(t_dlist *stack);
void		push(t_dlist *stack_1, t_dlist *stack_2);
void		rotate(t_dlist *stack);
void		reverse(t_dlist *stack);

/*
**		print.c
*/
void		ft_print_dlist(t_dlist *dlist);

/*
**		parser.c
*/
void		fill_stack(t_dlist *stack, char *av[]);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:12:15 by fli               #+#    #+#             */
/*   Updated: 2024/07/06 18:24:00 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sb(t_pile *pile_b)
{
	t_pile	*first;
	t_pile	*second;
	t_pile	*third;

	if (pile_b->next == NULL || pile_b == NULL)
		return ;
	first = pile_b;
	second = pile_b->next;
	third = pile_b->next->next;
	pile_b = second;
	pile_b->prev = NULL;
	pile_b->next = first;
	first->prev = second;
	first->next = third;
	third->prev = first;
}

void	pb(t_pile *pile_a, t_pile *pile_b)
{
	t_pile	*a_first;
	t_pile	*a_second;
	t_pile	*b_first;

	if (pile_a == NULL)
		return ;
	a_first = pile_a;
	a_second = pile_a->next;
	b_first = pile_b;
	pile_b = a_first;
	pile_b->prev = NULL;
	pile_b->next = b_first;
	b_first->prev = pile_b;
	pile_a = a_second;
	pile_a->prev = NULL;
}

void	rb(t_pile *pile_b)
{
	t_pile	*b_first;
	t_pile	*b_second;
	t_pile	*b_last;

	if (pile_b == NULL)
		return ;
	b_first = pile_b;
	b_second = pile_b->next;
	b_last = lstlast_pushswap(pile_b);
	pile_b = b_second;
	pile_b->prev = NULL;
	b_last->next = b_first;
	b_first->prev = b_last;
	b_first->next = NULL;
}

void	rrb(t_pile *pile_b)
{
	t_pile	*b_first;
	t_pile	*b_last;
	t_pile	*b_penultimate;

	if (pile_b == NULL)
		return ;
	b_first = pile_b;
	b_last = lstlast_pushswap(pile_b);
	b_penultimate = b_last->prev;
	pile_b = b_last;
	pile_b->prev = NULL;
	pile_b->next = b_first;
	b_first->prev = b_last;
	b_penultimate->next = NULL;
}

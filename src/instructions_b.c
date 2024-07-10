/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:12:15 by fli               #+#    #+#             */
/*   Updated: 2024/07/10 09:38:20 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sb(t_pile **pile_b)
{
	t_pile	*first;
	t_pile	*second;
	t_pile	*third;

	if (pile_b == NULL || *pile_b == NULL || (*pile_b)->next == NULL)
		return ;
	first = *pile_b;
	second = first->next;
	third = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third != NULL)
		third->prev = first;
	*pile_b = second;
	second->position = 1;
	first->position = 2;
	write(1, "sb\n", 3);
}

void	pb(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*a_first;
	t_pile	*a_second;
	t_pile	*b_first;

	if (pile_a == NULL || *pile_a == NULL)
		return ;
	a_first = *pile_a;
	a_second = a_first->next;
	b_first = *pile_b;
	*pile_b = a_first;
	a_first->prev = NULL;
	a_first->next = b_first;
	if (b_first != NULL)
		b_first->prev = a_first;
	*pile_a = a_second;
	if (a_second != NULL)
		a_second->prev = NULL;
	p_pupdate(pile_a, pile_b);
	write(1, "pb\n", 3);
}

void	rb(t_pile **pile_b)
{
	t_pile	*b_first;
	t_pile	*b_second;
	t_pile	*b_last;

	if (pile_b == NULL || *pile_b == NULL || (*pile_b)->next == NULL)
		return ;
	b_first = *pile_b;
	b_second = b_first->next;
	b_last = lstlast_pushswap(*pile_b);
	*pile_b = b_second;
	b_second->prev = NULL;
	b_last->next = b_first;
	b_first->prev = b_last;
	b_first->next = NULL;
	o_pupdate(pile_b);
	write(1, "rb\n", 3);
}

void	rrb(t_pile **pile_b)
{
	t_pile	*b_first;
	t_pile	*b_last;
	t_pile	*b_penultimate;

	if (pile_b == NULL || *pile_b == NULL || (*pile_b)->next == NULL)
		return ;
	b_first = *pile_b;
	b_last = lstlast_pushswap(*pile_b);
	b_penultimate = b_last->prev;
	*pile_b = b_last;
	b_last->prev = NULL;
	b_last->next = b_first;
	b_first->prev = b_last;
	if (b_penultimate != NULL)
		b_penultimate->next = NULL;
	o_pupdate(pile_b);
	write(1, "rrb\n", 4);
}

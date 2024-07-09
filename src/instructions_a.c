/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:12:15 by fli               #+#    #+#             */
/*   Updated: 2024/07/09 10:35:58 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_pile **pile_a)
{
	t_pile	*first;
	t_pile	*second;
	t_pile	*third;

	if (pile_a == NULL || *pile_a == NULL || (*pile_a)->next == NULL)
		return ;
	first = *pile_a;
	second = (*pile_a)->next;
	third = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third != NULL)
		third->prev = first;
	*pile_a = second;
	second->position = 1;
	first->position = 2;
	write(1, "sa\n", 4);
}

void	pa(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*a_first;
	t_pile	*b_first;
	t_pile	*b_second;

	if (pile_b == NULL || *pile_b == NULL)
		return ;
	a_first = *pile_a;
	b_first = *pile_b;
	b_second = b_first->next;
	*pile_a = b_first;
	b_first->prev = NULL;
	b_first->next = a_first;
	if (a_first != NULL)
		a_first->prev = b_first;
	*pile_b = b_second;
	if (b_second != NULL)
		b_second->prev = NULL;
	p_pupdate(pile_a, pile_b);
	write(1, "pa\n", 4);
}

void	ra(t_pile **pile_a)
{
	t_pile	*a_first;
	t_pile	*a_second;
	t_pile	*a_last;

	if (pile_a == NULL || *pile_a == NULL || (*pile_a)->next == NULL)
		return ;
	a_first = *pile_a;
	a_second = a_first->next;
	a_last = lstlast_pushswap(*pile_a);
	*pile_a = a_second;
	a_second->prev = NULL;
	a_last->next = a_first;
	a_first->prev = a_last;
	a_first->next = NULL;
	o_pupdate(pile_a);
	write(1, "ra\n", 4);
}

void	rra(t_pile **pile_a)
{
	t_pile	*a_first;
	t_pile	*a_last;
	t_pile	*a_penultimate;

	if (pile_a == NULL || *pile_a == NULL || (*pile_a)->next == NULL)
		return ;
	a_first = *pile_a;
	a_last = lstlast_pushswap(*pile_a);
	a_penultimate = a_last->prev;
	*pile_a = a_last;
	a_last->prev = NULL;
	a_last->next = a_first;
	a_first->prev = a_last;
	if (a_penultimate != NULL)
		a_penultimate->next = NULL;
	o_pupdate(pile_a);
	write(1, "rra\n", 5);
}

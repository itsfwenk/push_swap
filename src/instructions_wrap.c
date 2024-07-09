/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_wrap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:22:42 by fli               #+#    #+#             */
/*   Updated: 2024/07/09 14:28:56 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	s_wp(t_pile **pile_b)
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
}

void	r_wp(t_pile **pile_b)
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
}

void	rr_wp(t_pile **pile_b)
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
}

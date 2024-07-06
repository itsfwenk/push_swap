/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:12:15 by fli               #+#    #+#             */
/*   Updated: 2024/07/06 15:26:59 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_pile *pile_a)
{
	t_pile	*first;
	t_pile	*second;
	t_pile	*third;

	if (pile_a->next == NULL || pile_a == NULL)
		return ;
	first = pile_a;
	second = pile_a->next;
	third = pile_a->next->next;
	pile_a = second;
	pile_a->prev = NULL;
	pile_a->next = first;
	first->prev = second;
	first->next = third;
	third->prev = first;
}

void	pa(t_pile *pile_a, t_pile *pile_b)
{
	t_pile	*a_first;
	t_pile	*b_first;
	t_pile	*b_second;

	if (pile_b == NULL)
		return ;
	a_first = pile_a;
	b_first = pile_b;
	b_second = pile_b->next;
	pile_a = b_first;
	pile_a->prev = NULL;
	pile_a->next = a_first;
	pile_b = b_second;
	pile_b->prev = NULL;
}

void	ra(t_pile *pile_a)
{
	t_pile	*a_first;
	t_pile	*a_second;
	t_pile	*a_last;

	a_first = pile_a;
	a_second = pile_a->next;
	a_last = ft_lstlast_push_swap(pile_a);

	pile_a = a_second;
	pile_a->prev = NULL;
	a_last->next = a_first;
	a_first->prev = a_last;
	a_first->next = NULL;
}

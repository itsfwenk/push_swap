/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:40:24 by fli               #+#    #+#             */
/*   Updated: 2024/07/11 10:59:05 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_pile	**pile_a)
{
	t_pile	*current;

	current = *pile_a;
	if (current->rank != 1)
		return (FALSE);
	while (current->next != NULL)
	{
		if (current->rank > (current->next)->rank)
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}

t_pile	*get_cheapest(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*cheapest;
	t_pile	*temp;

	temp = *pile_b;
	cheapest = *pile_b;
	while (temp != NULL)
	{
		if (count_move(cheapest, pile_a, pile_b)
			> count_move(temp, pile_a, pile_b))
			cheapest = temp;
		temp = temp->next;
	}
	return (cheapest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:58:05 by fli               #+#    #+#             */
/*   Updated: 2024/07/07 19:03:25 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_sort(t_pile	**pile)
{
	t_pile	*current;

	current = *pile;
	if (current->rank != 1)
		return (FALSE);
	while (current != NULL)
	{
		if (current->rank > (current->next)->rank)
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}

void	sort_three(t_pile **pile_a)
{
	while (check_sort(pile_a) != TRUE)
	{
		if ((*pile_a)->next->rank > (*pile_a)->rank && (*pile_a)->next->rank < (*pile_a)->next->next->rank) // 3 2 1 -> 2 1 3
			ra(pile_a);
		if ((*pile_a)->rank < (*pile_a)->next->rank && (*pile_a)->rank < (*pile_a)->next->next->rank) // 1 3 2 -> 2 1 3
			rra(pile_a);
		if ((*pile_a)->rank > (*pile_a)->next->rank && (*pile_a)->rank < (*pile_a)->next->next->rank) // 2 1 3
			sa(pile_a);
		if ((*pile_a)->rank < (*pile_a)->next->rank && (*pile_a)->rank > (*pile_a)->next->next->rank) // 2 3 1
			rra(pile_a);
		if ((*pile_a)->next->rank < (*pile_a)->rank && (*pile_a)->next->rank < (*pile_a)->next->next->rank) // 3 1 2
			ra(*pile_a);
	}
}

void	bymedian(int tab_len, int *num_tab, t_pile **pile_a, t_pile **pile_b)
{
	int	median_rank;
	int	crank;

	median_rank = (tab_len / 2) + 1;
	while (lstsize_pushswap(pile_a) > 3)
	{
		crank = (*pile_a)->rank;
		if (crank == tab_len || crank == tab_len - 1 || crank == tab_len - 2)
			ra(pile_a);
		else
		{
			if ((*pile_a)->rank > median_rank)
				pb(pile_a, pile_b);
			else
			{
				pb(pile_a, pile_b);
				rb(pile_b);
			}
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:58:05 by fli               #+#    #+#             */
/*   Updated: 2024/07/11 11:05:34 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_sort_three(t_pile	**pile)
{
	t_pile	*current;

	current = *pile;
	while (current->next != NULL)
	{
		if (current->rank > (current->next)->rank)
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}

void	sort_three(t_pile **pile_a)
{
	while (check_sort_three(pile_a) != TRUE)
	{
		if ((*pile_a)->next->rank < (*pile_a)->rank
			&& (*pile_a)->next->rank > (*pile_a)->next->next->rank)
			ra(pile_a);
		if ((*pile_a)->rank < (*pile_a)->next->rank
			&& (*pile_a)->rank < (*pile_a)->next->next->rank)
			rra(pile_a);
		if ((*pile_a)->rank > (*pile_a)->next->rank
			&& (*pile_a)->rank < (*pile_a)->next->next->rank)
			sa(pile_a);
		if ((*pile_a)->rank < (*pile_a)->next->rank
			&& (*pile_a)->rank > (*pile_a)->next->next->rank)
			rra(pile_a);
		if ((*pile_a)->next->rank < (*pile_a)->rank
			&& (*pile_a)->next->rank < (*pile_a)->next->next->rank)
			ra(pile_a);
	}
}

static void	below(int tab_len, t_pile **pile_a, t_pile **pile_b)
{
	int	median_rank;

	median_rank = (tab_len / 2) + 1;
	if ((*pile_a)->rank > median_rank)
		pb(pile_a, pile_b);
	else
	{
		pb(pile_a, pile_b);
		rb(pile_b);
	}
}

static void	above(int tab_len, t_pile **pile_a, t_pile **pile_b)
{
	int	median_rank;

	median_rank = (tab_len / 2) + 1;
	while (lstsize_pushswap(*pile_a) > tab_len / 2)
	{
		if ((*pile_a)->rank < median_rank)
			bysmolmedian(median_rank, tab_len, pile_a, pile_b);
		else
			ra(pile_a);
	}
	bybigmedian(median_rank, tab_len, pile_a, pile_b);
}

void	bymedian(int tab_len, t_pile **pile_a, t_pile **pile_b)
{
	int	crank;

	while (lstsize_pushswap(*pile_a) > 3)
	{
		crank = (*pile_a)->rank;
		if (crank == tab_len || crank == tab_len - 1 || crank == tab_len - 2)
			ra(pile_a);
		else
		{
			if (tab_len < 90)
				below(tab_len, pile_a, pile_b);
			else
				above(tab_len, pile_a, pile_b);
		}
	}
	sort_three(pile_a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:58:05 by fli               #+#    #+#             */
/*   Updated: 2024/07/10 18:18:04 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_sort(t_pile	**pile_a)
{
	t_pile	*current;

	current = *pile_a;
	if (current == NULL)
		return (FALSE);
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
		if ((*pile_a)->next->rank < (*pile_a)->rank && (*pile_a)->next->rank > (*pile_a)->next->next->rank) // 3 2 1 -> 2 1 3
			ra(pile_a);
		if ((*pile_a)->rank < (*pile_a)->next->rank && (*pile_a)->rank < (*pile_a)->next->next->rank) // 1 3 2 -> 2 1 3
			rra(pile_a);
		if ((*pile_a)->rank > (*pile_a)->next->rank && (*pile_a)->rank < (*pile_a)->next->next->rank) // 2 1 3
			sa(pile_a);
		if ((*pile_a)->rank < (*pile_a)->next->rank && (*pile_a)->rank > (*pile_a)->next->next->rank) // 2 3 1
			rra(pile_a);
		if ((*pile_a)->next->rank < (*pile_a)->rank && (*pile_a)->next->rank < (*pile_a)->next->next->rank) // 3 1 2
			ra(pile_a);
	}
}

void	bymedian(int tab_len, t_pile **pile_a, t_pile **pile_b)
{
	int	median_rank;
	int	crank;

	median_rank = (tab_len / 2) + 1;
	while (lstsize_pushswap(*pile_a) > 3)
	{
		crank = (*pile_a)->rank;
		if (crank == tab_len || crank == tab_len - 1 || crank == tab_len - 2)
			ra(pile_a);
		else
		{
			if (tab_len < 90)
			{
				if ((*pile_a)->rank > median_rank)
					pb(pile_a, pile_b);
				else
				{
					pb(pile_a, pile_b);
					rb(pile_b);
				}
			}
			// else if (tab_len == 100)
			// {
			// 	while (lstsize_pushswap(*pile_a) > tab_len / 2)
			// 	{
			// 		if ((*pile_a)->rank < median_rank)
			// 			bysmolmedian(median_rank, tab_len, pile_a, pile_b);
			// 		else
			// 			ra(pile_a);
			// 	}
			// 	pb(pile_a, pile_b);
			// }
			else
			{
				while (lstsize_pushswap(*pile_a) > tab_len / 2)
				{
					if ((*pile_a)->rank < median_rank)
						bysmolmedian(median_rank, tab_len, pile_a, pile_b);
					else
						ra(pile_a);
				}
				bybigmedian(median_rank, tab_len, pile_a, pile_b);
			}
		}
	}
	sort_three(pile_a);
}

t_pile	*get_cheapest(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*cheapest;
	t_pile	*temp;

	temp = *pile_b;
	cheapest = *pile_b;
	while (temp != NULL)
	{
		if (count_move(cheapest, pile_a, pile_b) > count_move(temp, pile_a, pile_b))
			cheapest = temp;
		temp = temp->next;
	}
	return (cheapest);
}

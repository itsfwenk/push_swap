/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:22:15 by fli               #+#    #+#             */
/*   Updated: 2024/07/10 16:34:45 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bybigmedian(int median_rank, int tab_len, t_pile **pile_a, t_pile **pile_b)
{
	int	big_median_rank;
	int	crank;

	crank = (*pile_a)->rank;
	if (crank == tab_len || crank == tab_len - 1 || crank == tab_len - 2)
	{
		ra(pile_a);
		return ;
	}
	big_median_rank = (tab_len / 2) + 1 + ((median_rank / 2) + 1);
	if ((*pile_a)->rank > big_median_rank)
	{
		pb(pile_a, pile_b);
		rb(pile_b);
	}
	else
	{
		pb(pile_a, pile_b);
		// rb(pile_b);
	}
}

void	bysmolmedian(int median_rank, int tab_len, t_pile **pile_a, t_pile **pile_b)
{
	int	smol_median_rank;
	int	crank;

	crank = (*pile_a)->rank;
	if (crank == tab_len || crank == tab_len - 1 || crank == tab_len - 2)
	{
		ra(pile_a);
		return ;
	}
	smol_median_rank = (tab_len / 2) + 1 - (median_rank / 2) + 1;
	if ((*pile_a)->rank > smol_median_rank)
		pb(pile_a, pile_b);
	else
	{
		pb(pile_a, pile_b);
		rb(pile_b);
	}
}

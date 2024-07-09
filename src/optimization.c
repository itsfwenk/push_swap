/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:22:15 by fli               #+#    #+#             */
/*   Updated: 2024/07/09 17:34:28 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bybigmedian(int tab_len, t_pile **pile_a, t_pile **pile_b)
{
	int	big_median_rank;

	big_median_rank = (tab_len / 2) + 1 + ((tab_len / 2) + 1);
	if ((*pile_a)->rank > big_median_rank)
		pb(pile_a, pile_b);
	else
	{
		pb(pile_a, pile_b);
		rb(pile_b);
	}
}

void	bysmolmedian(int tab_len, t_pile **pile_a, t_pile **pile_b)
{
	int	smol_median_rank;

	smol_median_rank = (tab_len / 2) + 1 - ((tab_len / 2) + 1);
	if ((*pile_a)->rank < smol_median_rank)
		pb(pile_a, pile_b);
	else
	{
		pb(pile_a, pile_b);
		rb(pile_b);
	}
}

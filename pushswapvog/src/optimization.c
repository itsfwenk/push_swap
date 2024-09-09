/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:22:15 by fli               #+#    #+#             */
/*   Updated: 2024/07/11 10:32:02 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bybigmedian(int median_rank, int tab_len, t_pile **p_a, t_pile **p_b)
{
	int	big_median_rank;
	int	crank;

	crank = (*p_a)->rank;
	if (crank == tab_len || crank == tab_len - 1 || crank == tab_len - 2)
	{
		ra(p_a);
		return ;
	}
	big_median_rank = (tab_len / 2) + 1 + ((median_rank / 2) + 1);
	if ((*p_a)->rank > big_median_rank)
	{
		pb(p_a, p_b);
		rb(p_b);
	}
	else
		pb(p_a, p_b);
}

void	bysmolmedian(int median_rank, int tab_len, t_pile **p_a, t_pile **p_b)
{
	int	smol_median_rank;
	int	crank;

	crank = (*p_a)->rank;
	if (crank == tab_len || crank == tab_len - 1 || crank == tab_len - 2)
	{
		ra(p_a);
		return ;
	}
	smol_median_rank = (tab_len / 2) + 1 - (median_rank / 2) + 2;
	if ((*p_a)->rank > smol_median_rank)
		pb(p_a, p_b);
	else
	{
		pb(p_a, p_b);
		rb(p_b);
	}
}

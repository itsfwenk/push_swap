/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_median.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:17:37 by fli               #+#    #+#             */
/*   Updated: 2024/07/07 16:39:16 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	median_even(int *num_tab, int tab_len, t_pile **pile_a)
{
	int	i;
	int	median;
	int	median_rank;
	t_pile *current;

	i = 0;
	median_rank = (tab_len / 2);
	current = *pile_a;
	while(current != NULL)
	{
		if (current->rank == median_rank)
		{
			median = current->nb;
			return (median);
		}
		current = current->next;
	}
}

static int	median_odd(int *num_tab, int tab_len, t_pile **pile_a)
{
	int	i;
	int	median;
	int	median_rank;
	t_pile *current;

	i = 0;
	median_rank = (tab_len / 2) + 1;
	current = *pile_a;
	while(current != NULL)
	{
		if (current->rank == median_rank)
		{
			median = current->nb;
			return (median);
		}
		current = current->next;
	}
}

int	found_median(int argc, char **argv, int *num_tab, t_pile **pile_a)
{
	int	i;
	int	tab_len;
	int	median;

	i = 0;
	tab_len = count_entry(argc, argv);
	if (tab_len % 2 == 0)
		median = median_even(num_tab, tab_len, pile_a);
	else
		median = median_odd(num_tab, tab_len, pile_a);
	return (median);
}

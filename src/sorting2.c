/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:45:32 by fli               #+#    #+#             */
/*   Updated: 2024/07/09 12:18:33 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rr_rrr(t_pile *cheap, t_pile *put_top, t_pile **p_a, t_pile **p_b)
{
	if (r_cheaper(put_top, p_a) == TRUE)
	{
		if (r_cheaper(cheap, p_b) == TRUE)
		{
			while (*p_a != put_top || *p_b != cheap)
				{
					rr(p_a, p_b);
					if (*p_a != put_top || *p_b != cheap)
						break;
				}
		}
	}
	if (r_cheaper(put_top, p_a) == FALSE)
	{
		if (r_cheaper(cheap, p_b) == FALSE)
		{
			while (*p_a != put_top || *p_b != cheap)
				{
					rr(p_a, p_b);
					if (*p_a != put_top || *p_b != cheap)
						break;
				}
		}
	}
}

static void	r_or_rr(t_pile *to_top, t_pile **pile)
{
	if (r_cheaper(to_top, pile) == TRUE)
	{
		while (*pile != to_top)
		{
			if (to_top->pile == 'a')
				ra(pile);
			else
				rb(pile);
		}
	}
	else
	{
		while (*pile != to_top)
		{
			if (to_top->pile == 'a')
				rra(pile);
			else
				rrb(pile);
		}
	}
}

void	sort(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*cheapest;
	t_pile *to_put_top_a;

	// int	i = 1;
	// print_list_content(pile_a, pile_b);
	while ((*pile_b) != NULL)
	{
		cheapest = get_cheapest(pile_a, pile_b);
		to_put_top_a = get_to_put_top_a(cheapest, pile_a);
		if (r_cheaper(to_put_top_a, pile_a) == r_cheaper(cheapest, pile_b))
			rr_rrr(cheapest, to_put_top_a, pile_a, pile_b);
		while (*pile_a != to_put_top_a)
			r_or_rr(to_put_top_a, pile_a);
		while (*pile_b != cheapest)
			r_or_rr(cheapest, pile_b);
		pa(pile_a, pile_b);
		// dprintf(2, "tour : %d\n", i++);
		// print_list_content(pile_a, pile_b);
	}
	// if (check_sort(pile_a) == FALSE)
	// 	dprintf(2, "NOT SORTED\n");
}

/* void	sort(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*cheapest;
	t_pile *to_put_top_a;

	// int	i = 1;
	// print_list_content(pile_a, pile_b);
	while ((*pile_b) != NULL)
	{
		cheapest = get_cheapest(pile_a, pile_b);
		to_put_top_a = get_to_put_top_a(cheapest, pile_a);
		if (r_cheaper(to_put_top_a, pile_a) == r_cheaper(cheapest, pile_b))
			rr_rrr(cheapest, to_put_top_a, pile_a, pile_b);
		else
		{
			r_or_rr(to_put_top_a, pile_a);
			r_or_rr(cheapest, pile_b);
		}
		pa(pile_a, pile_b);
		// dprintf(2, "tour : %d\n", i++);
		// print_list_content(pile_a, pile_b);
	}
	// if (check_sort(pile_a) == FALSE)
	// 	dprintf(2, "NOT SORTED\n");
} */

// void	prep_push(t_pile **pile_a, t_pile **pile_b)
// {
// 	t_pile	*cheapest;
// 	t_pile *to_put_top_a;

// 	cheapest = get_cheapest(pile_a, pile_b);
// 	to_put_top_a = get_to_put_top_a(cheapest, pile_a);
// 	if (r_cheaper(to_put_top_a, pile_a) == r_cheaper(cheapest, pile_b))
// 		rr_rrr(cheapest, to_put_top_a, pile_a, pile_b);
// 	else
// 	{
// 		r_or_rrr(to_put_top_a, pile_a);
// 		r_or_rrr(cheapest, pile_b);
// 	}
// }

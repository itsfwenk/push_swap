/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:45:32 by fli               #+#    #+#             */
/*   Updated: 2024/07/10 22:21:46 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rr_rrr(t_pile *cheap, t_pile *put_top, t_pile **p_a, t_pile **p_b)
{
	if (r_cheaper(put_top, p_a) == TRUE)
	{
		if (r_cheaper(cheap, p_b) == TRUE)
		{
			rr(p_a, p_b);
			return ;
		}
	}
	else
	{
		if (r_cheaper(cheap, p_b) == FALSE)
		{
			rrr(p_a, p_b);
			return ;
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

static t_pile	*find_first(t_pile **pile_a)
{
	t_pile	*temp;

	temp = *pile_a;
	while (temp != NULL && temp->rank != 1)
		temp = temp->next;
	return (temp);
}

void	sort_last(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*to_put_top_a;

	to_put_top_a = *pile_a;
	while (to_put_top_a->rank != (*pile_b)->rank + 1)
		to_put_top_a = to_put_top_a->next;
	while ((*pile_a)->rank != (*pile_b)->rank + 1)
		r_or_rr(to_put_top_a, pile_a);
	pa(pile_a, pile_b);
}

void	sort(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*cheapest;
	t_pile	*to_put_top_a;

	while ((*pile_b)->next != NULL)
	{
		cheapest = get_cheapest(pile_a, pile_b);
		to_put_top_a = get_to_put_top_a(cheapest, pile_a);

		if (r_cheaper(to_put_top_a, pile_a) == r_cheaper(cheapest, pile_b))
		{
			while ((*pile_a) != to_put_top_a && (*pile_b) != cheapest)
				rr_rrr(cheapest, to_put_top_a, pile_a, pile_b);
		}
		if (*pile_a != to_put_top_a)
		{
			r_or_rr(to_put_top_a, pile_a);
		}
		if (*pile_b != cheapest)
		{
			r_or_rr(cheapest, pile_b);
		}
		pa(pile_a, pile_b);
	}
	sort_last(pile_a, pile_b);
	while ((*pile_a)->rank != 1)
	{
		if (r_cheaper(find_first(pile_a), pile_a) == TRUE)
			ra(pile_a);
		else
			rra(pile_a);
	}
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

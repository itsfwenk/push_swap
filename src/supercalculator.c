/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supercalculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:16:35 by fli               #+#    #+#             */
/*   Updated: 2024/07/08 16:04:50 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	r_cheaper(t_pile *to_put_top, t_pile **pile)
{
	int	r_moves;
	int	rr_moves;
	t_pile *temp;

	temp = *pile;
	r_moves = 0;
	while (to_put_top->position > temp->position)
	{
		r_moves++;
		temp = temp->next;
	}
	temp = to_put_top;
	rr_moves = 0;
	while (temp != NULL)
	{
		rr_moves++;
		temp = temp->next;
	}
	if (r_moves < rr_moves)
		return (TRUE);
	else
		return (FALSE);
}

static t_pile	*get_to_put_top_a(t_pile *to_sort, t_pile **pile_a)
{
	t_pile	*to_put_top_a;

	to_put_top_a = *pile_a;
	while (to_put_top_a->position < to_sort->position)
	{
		to_put_top_a = to_put_top_a->next;
	}
	return (to_put_top_a);
}

static int	move_to_top(t_pile *to_sort, t_pile **pile)
{
	int		move;

	move = 0;
	if (r_cheaper(to_sort, pile) == TRUE)
		move = to_sort->position - 1;
	else
		move = lstsize_pushswap(*pile) - to_sort->position + 1;
	return (move);
}

int	count_move(t_pile *to_sort, t_pile **pile_a, t_pile **pile_b)
{
	int		moves;
	int		move_a;
	int		move_b;
	t_pile *to_put_top_a;

	to_put_top_a = get_to_put_top_a(to_sort, pile_a);
	move_a = move_to_top(to_put_top_a, pile_a);
	move_b = move_to_top(to_sort, pile_b);
	if (r_cheaper(to_put_top_a, pile_a) == r_cheaper(to_sort, pile_b))
		moves = ((move_a + move_b) / 2) + v_abs(move_a - move_b) + 1;
	else
		moves = move_a + move_b + 1;
}

// int	count_move_a(t_pile *to_sort, t_pile **pile_a, t_pile **pile_b)
// {
// 	int		move_a;
// 	t_pile *temp;

// 	move_a = 0;
// 	if (r_cheaper(get_to_put_top_a(to_sort, pile_a), pile_a) == TRUE)
// 	{
// 		temp = *pile_a;
// 		while (to_sort->position < temp->position)
// 		{
// 			move_a++;
// 			temp = temp->next;
// 		}
// 	}
// 	else
// 	{
// 		temp = get_to_put_top_a(to_sort, pile_a);
// 		while (temp != NULL)
// 		{
// 			move_a++;
// 			temp = temp->next;
// 		}
// 	}
// 	return (move_a);
// }



// int	rrcount_move(t_pile *current, t_pile **pile_a, t_pile **pile_b)
// {
// 	int		moves;
// 	int		ra;
// 	int		rb;
// 	t_pile *temp;

// 	ra = 0;
// 	temp = *pile_a;
// 	while (current->position < temp->position)
// 		ra++;
// 	rb = current->position;
// 	moves = ((ra + rb) / 2) + v_abs(ra - rb) + 1;

// }

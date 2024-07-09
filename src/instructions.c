/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:25:59 by fli               #+#    #+#             */
/*   Updated: 2024/07/09 10:35:30 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ss(t_pile **pile_a, t_pile **pile_b)
{
	sa(pile_a);
	sb(pile_b);
	write(1, "ss\n", 4);
}

void	rr(t_pile **pile_a, t_pile **pile_b)
{
	ra(pile_a);
	rb(pile_b);
	write(1, "rr", 4);
}

void	rrr(t_pile **pile_a, t_pile **pile_b)
{
	rra(pile_a);
	rrb(pile_b);
	write(1, "rrr", 5);
}

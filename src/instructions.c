/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:25:59 by fli               #+#    #+#             */
/*   Updated: 2024/07/10 09:38:23 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ss(t_pile **pile_a, t_pile **pile_b)
{
	s_wp(pile_a);
	s_wp(pile_b);
	write(1, "ss\n", 3);
}

void	rr(t_pile **pile_a, t_pile **pile_b)
{
	r_wp(pile_a);
	r_wp(pile_b);
	write(1, "rr\n", 3);
}

void	rrr(t_pile **pile_a, t_pile **pile_b)
{
	rr_wp(pile_a);
	rr_wp(pile_b);
	write(1, "rrr\n", 4);
}

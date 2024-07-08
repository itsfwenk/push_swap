/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:02:11 by fli               #+#    #+#             */
/*   Updated: 2024/07/08 17:07:18 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	p_pupdate(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*temp_a;
	t_pile	*temp_b;
	int		p;

	p = 1;
	temp_a = *pile_a;
	temp_b = *pile_b;
	(*pile_a)->pile = (*pile_a)->next->pile;
	(*pile_b)->pile = (*pile_b)->next->pile;
	while (temp_a != NULL || temp_b != NULL)
	{
		if (temp_a != NULL)
		{
			temp_a->position = p;
			temp_a = temp_a->next;
		}
		if (temp_b != NULL)
		{
			temp_b->position = p;
			temp_b = temp_b->next;
		}
		p++;
	}
}

void	o_pupdate(t_pile **pile)
{
	t_pile	*temp;

	int		p;

	p = 1;
	while (temp != NULL)
	{
		temp->position = p;
		temp = temp->next;
		p++;
	}
}

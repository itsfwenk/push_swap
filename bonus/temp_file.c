/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:52:23 by fli               #+#    #+#             */
/*   Updated: 2024/07/09 10:59:24 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_list_content(t_pile **pile_a,t_pile **pile_b)
{
	t_pile	*temp;

	temp = *pile_a;
	dprintf(2, "PILE A\n");
	while (temp != NULL)
	{
		dprintf(2, "rank %d num %d\n", temp->rank, temp->nb);
		temp = temp->next;
	}
	temp = *pile_b;
	dprintf(2, "PILE B\n");
	while (temp != NULL)
	{
		dprintf(2, "rank %d num %d\n", temp->rank, temp->nb);
		temp = temp->next;
	}
}

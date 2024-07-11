/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:58:05 by fli               #+#    #+#             */
/*   Updated: 2024/07/11 10:11:18 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_sort(t_pile	**pile_a)
{
	t_pile	*current;

	current = *pile_a;
	if (current == NULL)
		return (FALSE);
	if (current->rank != 1)
		return (FALSE);
	while (current->next != NULL)
	{
		if (current->rank > (current->next)->rank)
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}

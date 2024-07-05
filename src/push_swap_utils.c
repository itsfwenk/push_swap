/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:42:22 by fli               #+#    #+#             */
/*   Updated: 2024/07/05 17:58:27 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_split(char	**split_tab)
{
	int	i;

	i = 0;
	while (split_tab[i] != 0)
	{
		free(split_tab[i]);
		i++;
	}
	free(split_tab);
}

int	num_tab_check_double(int num, int *num_tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (num == num_tab[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

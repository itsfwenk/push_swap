/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:42:22 by fli               #+#    #+#             */
/*   Updated: 2024/07/11 10:24:44 by fli              ###   ########.fr       */
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
	while (i < n - 1)
	{
		if (num == num_tab[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	count_entry(int argc, char **argv)
{
	int		n_entry;
	char	**entry;

	n_entry = 0;
	if (argc == 2)
	{
		entry = ft_split(argv[1], ' ');
		if (entry == NULL)
			return (-1);
		while (entry[n_entry] != 0)
			n_entry++;
	}
	else
		n_entry = argc - 1;
	if (argc == 2)
		free_split(entry);
	return (n_entry);
}

int	get_rank(int tab_len, int *num_tab, t_pile *new_nod)
{
	int		i;
	int		rank;

	rank = 0;
	i = 0;
	while (i < tab_len)
	{
		if (new_nod->nb > num_tab[i])
			rank++;
		i++;
	}
	return (rank + 1);
}

int	v_abs(int value)
{
	if (value < 0)
		return (value * -1);
	else
		return (value);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:16:01 by fli               #+#    #+#             */
/*   Updated: 2024/07/07 16:15:44 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	create_pile_a(int argc, char **argv, t_pile **pile_a, int *num_tab)
{
	int		i;
	t_pile	*new_nod;

	i = 0;
	while (i < count_entry(argc, argv))
	{
		new_nod = lstnew_pushswap(num_tab[i]);
		if (new_nod == NULL)
			return (lstclear_pushswap(pile_a), FALSE);
		lstaddback_pushswap(pile_a, new_nod);
		new_nod->rank = get_rank(argc, argv, num_tab, new_nod);
		i++;
	}
	return (TRUE);
}

int	main(int argc, char **argv)
{
	int	*num_tab; //malloced
	t_pile	*pile_a; //malloced
	t_pile	*pile_b;

	if (argc <= 1)
		return (0);
	num_tab = parsing(argc, argv);
	if (num_tab == NULL)
		return (write(2, "Error\n", 7), 0);
	if (create_pile_a(argc, argv, &pile_a, num_tab) == FALSE)
		return (-1);
}

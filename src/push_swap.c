/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:16:01 by fli               #+#    #+#             */
/*   Updated: 2024/07/06 18:29:36 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	create_pile_a(int argc, char **argv, t_pile **pile_a, int *num_tab)
{
	int		i;
	t_pile	*new;

	i = 0;
	while (i < count_entry(argc, argv))
	{
		new = lstnew_pushswap(num_tab[i]);
		if (new == NULL)
			return (lstclear_pushswap(pile_a), NULL);
		lstaddback_pushswap(pile_a, new);
		i++;
	}
	return ;
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
	create_pile_a(argc, argv, &pile_a, num_tab);
	// int i = 0;
	// while (i < argc)
	// {
	// 	dprintf(2, "%s\n", argv[i]);
	// 	i++;
	// }
}

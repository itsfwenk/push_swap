/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:16:01 by fli               #+#    #+#             */
/*   Updated: 2024/07/16 16:53:21 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	create_pile_a(int tab_len, t_pile **pile_a, int *num_tab)
{
	int		i;
	t_pile	*new_nod;

	i = 0;
	while (i < tab_len)
	{
		new_nod = lstnew_pushswap(num_tab[i]);
		if (new_nod == NULL)
			return (lstclear_pushswap(pile_a), FALSE);
		lstaddback_pushswap(pile_a, new_nod);
		if (new_nod->prev != NULL)
			new_nod->position = new_nod->prev->position + 1;
		new_nod->rank = get_rank(tab_len, num_tab, new_nod);
		i++;
	}
	return (TRUE);
}

static void	sort_two(t_pile **pile_a, int **num_tab)
{
	if ((*pile_a)->nb < (*pile_a)->next->nb)
	{
		lstclear_pushswap(pile_a);
		free(*num_tab);
		exit(EXIT_SUCCESS);
	}
	else
	{
		sa(pile_a);
		lstclear_pushswap(pile_a);
		free(*num_tab);
		exit(EXIT_SUCCESS);
	}
}

static void	tab_three(t_pile **pile_a, int **num_tab)
{
	sort_three(pile_a);
	lstclear_pushswap(pile_a);
	free(*num_tab);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	int		tab_len;
	int		*num_tab;
	t_pile	*pile_a;
	t_pile	*pile_b;

	if (argc <= 1)
		return (0);
	num_tab = parsing(argc, argv);
	if (num_tab == NULL)
		return (write(2, "Error\n", 7), 0);
	tab_len = count_entry(argc, argv);
	if (tab_len <= 1)
		return (free(num_tab), 0);
	pile_a = NULL;
	if (create_pile_a(tab_len, &pile_a, num_tab) == FALSE)
		return (-1);
	if (tab_len == 3)
		tab_three(&pile_a, &num_tab);
	if (tab_len == 2)
		sort_two(&pile_a, &num_tab);
	pile_b = NULL;
	bymedian(tab_len, &pile_a, &pile_b);
	sort(&pile_a, &pile_b);
	lstclear_pushswap(&pile_a);
	free(num_tab);
}

	// while (pile_a != NULL)
	// {
	// 	dprintf(2, "rank %d num %d\n", pile_a->rank, pile_a->nb);
	// 	pile_a = pile_a->next;
	// }

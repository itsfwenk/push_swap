/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:59:56 by fli               #+#    #+#             */
/*   Updated: 2024/07/10 17:43:35 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	create_pile_a(int tab_len, t_pile **pile_a, int *num_tab)
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

static void	do_instructs(char *instruct, t_pile **pile_a, t_pile **pile_b)
{
	if (ft_strncmp(instruct, "sa\n", ft_strlen("sa\n") == 1))
		sa(pile_a);
	if (ft_strncmp(instruct, "pa\n", ft_strlen("pa\n") == 1))
		pa(pile_a, pile_b);
	if (ft_strncmp(instruct, "ra\n", ft_strlen("ra\n") == 1))
		ra(pile_a);
	if (ft_strncmp(instruct, "rra\n", ft_strlen("rra\n") == 1))
		rra(pile_a);
	if (ft_strncmp(instruct, "sb\n", ft_strlen("sb\n") == 1))
		sb(pile_b);
	if (ft_strncmp(instruct, "pb\n", ft_strlen("pb\n") == 1))
		pb(pile_a, pile_b);
	if (ft_strncmp(instruct, "rb\n", ft_strlen("rb\n") == 1))
		rb(pile_b);
	if (ft_strncmp(instruct, "rrb\n", ft_strlen("rrb\n") == 1))
		rrb(pile_b);
	if (ft_strncmp(instruct, "ss\n", ft_strlen("ss\n") == 1))
		ss(pile_a, pile_b);
	if (ft_strncmp(instruct, "rr\n", ft_strlen("rr\n") == 1))
		rr(pile_a, pile_b);
	if (ft_strncmp(instruct, "rrb\n", ft_strlen("rrb\n") == 1))
		rrr(pile_a, pile_b);
}

static void	get_instructs(t_pile **pile_a, t_pile **pile_b)
{
	char 	*instruct;

	instruct = get_next_line(0);
	while (ft_strncmp(instruct, "stop\n", ft_strlen("stop\n")) != 0)
	{
		if (instruct == NULL)
			break ;
		do_instructs(instruct, pile_a, pile_b);
		free(instruct);
		instruct = get_next_line(0);
	}
	free(instruct);
	get_next_line(-1);
	return ;
}

int	main(int argc, char **argv)
{
	int	tab_len;
	int	*num_tab;
	t_pile	*pile_a;
	t_pile	*pile_b;

	if (argc <= 1)
		return (0);
	num_tab = parsing(argc, argv);
	if (num_tab == NULL)
		return (write(2, "Error\n", 7), 0);
	tab_len = count_entry(argc, argv);
	if (tab_len == -1)
		return (0);
	pile_a = NULL;
	if (create_pile_a(tab_len, &pile_a, num_tab) == FALSE)
		return (-1);
	pile_b = NULL;
	get_instructs(&pile_a, &pile_b);
	lstclear_pushswap(&pile_a);
	free(num_tab);
	if (check_sort(&pile_a) == TRUE && pile_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

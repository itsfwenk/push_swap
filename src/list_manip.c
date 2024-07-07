/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:25:21 by fli               #+#    #+#             */
/*   Updated: 2024/07/07 16:13:09 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile	*lstlast_pushswap(t_pile *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_pile	*lstnew_pushswap(int nb)
{
	t_pile	*new_nod;

	new_nod = malloc(sizeof(t_pile));
	if (new_nod == NULL)
		return (NULL);
	new_nod->nb = nb;
	new_nod->rank = 0;
	new_nod->prev = NULL;
	new_nod->next = NULL;
	return (new_nod);
}

void	lstaddback_pushswap(t_pile **lst, t_pile *new)
{
	t_pile	*last;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last != NULL)
	{
		if ((last->next) == NULL)
		{
			last->next = new;
			new->prev = last;
			return ;
		}
		last = last->next;
	}
}

void	lstclear_pushswap(t_pile **lst)
{
	t_pile	*temp;

	if (!lst || !*lst)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}

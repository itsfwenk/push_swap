/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:17:47 by fli               #+#    #+#             */
/*   Updated: 2024/07/06 18:28:01 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"

# ifndef TRUE
#  define TRUE 1

# endif

# ifndef FALSE
#  define FALSE 0

# endif

typedef struct s_pile
{
	int				nb;
	struct s_pile	*prev;
	struct s_pile	*next;
}	t_pile;

/******************* PUSH_SWAP *******************/

void	create_pile_a(int argc, char **argv, t_pile **pile_a, int *num_tab);

/******************* PARSING *******************/

int		*parsing(int argc, char **argv);

/******************* LIST_MANIP *******************/

t_pile	*lstlast_pushswap(t_pile *lst);

t_pile	*lstnew_pushswap(int nb);

void	lstaddback_pushswap(t_pile **lst, t_pile *new);

void	lstclear_pushswap(t_pile **lst);

/******************* UTILS *******************/

void	free_split(char	**split_tab);

int		num_tab_check_double(int num, int *num_tab, int n);

int		count_entry(int argc, char **argv);

/******************* INSTRUCTIONS *******************/

void	sa(t_pile *pile_a);

void	pa(t_pile *pile_a, t_pile *pile_b);

void	ra(t_pile *pile_a);

void	sb(t_pile *pile_b);

void	pb(t_pile *pile_a, t_pile *pile_b);

void	rb(t_pile *pile_b);

void	ss(t_pile *pile_a, t_pile *pile_b);

void	rr(t_pile *pile_a, t_pile *pile_b);

void	rrr(t_pile *pile_a, t_pile *pile_b);

#endif

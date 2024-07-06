/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:17:47 by fli               #+#    #+#             */
/*   Updated: 2024/07/06 17:34:22 by fli              ###   ########.fr       */
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

/******************* PARSING *******************/

int		*parsing(int argc, char **argv);

/******************* LIST_MANIP *******************/

t_pile	*ft_lstlast_push_swap(t_pile *lst);

/******************* UTILS *******************/

void	free_split(char	**split_tab);

int		num_tab_check_double(int num, int *num_tab, int n);

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

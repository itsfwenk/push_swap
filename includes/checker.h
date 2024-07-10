/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:02:51 by fli               #+#    #+#             */
/*   Updated: 2024/07/10 17:16:38 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"
# include "get_next_line.h"

# ifndef TRUE
#  define TRUE 1

# endif

# ifndef FALSE
#  define FALSE 0

# endif

typedef struct s_pile
{
	int				nb;
	int				rank;
	int				position;
	char			pile;
	struct s_pile	*prev;
	struct s_pile	*next;
}	t_pile;

/******************* PUSH_SWAP *******************/

int		create_pile_a(int tab_len, t_pile **pile_a, int *num_tab);

/******************* PARSING *******************/

int		*parsing(int argc, char **argv);

/******************* LIST_MANIP *******************/

t_pile	*lstlast_pushswap(t_pile *lst);

t_pile	*lstnew_pushswap(int nb);

void	lstaddback_pushswap(t_pile **lst, t_pile *new);

void	lstclear_pushswap(t_pile **lst);

int		lstsize_pushswap(t_pile *lst);

/******************* UTILS *******************/

void	free_split(char	**split_tab);

int		num_tab_check_double(int num, int *num_tab, int n);

int		count_entry(int argc, char **argv);

int		get_rank(int tab_len, int *num_tab, t_pile *new_nod);

int		found_median(int tab_len, t_pile **pile_a);

int		v_abs(int value);

/******************* INSTRUCTIONS *******************/

void	sa(t_pile **pile_a);

void	pa(t_pile **pile_a, t_pile **pile_b);

void	ra(t_pile **pile_a);

void	rra(t_pile **pile_a);

void	sb(t_pile **pile_b);

void	pb(t_pile **pile_a, t_pile **pile_b);

void	rb(t_pile **pile_b);

void	rrb(t_pile **pile_b);

void	ss(t_pile **pile_a, t_pile **pile_b);

void	rr(t_pile **pile_a, t_pile **pile_b);

void	rrr(t_pile **pile_a, t_pile **pile_b);

void	s_wp(t_pile **pile_b);

void	r_wp(t_pile **pile_b);

void	rr_wp(t_pile **pile_b);

/******************* SORTING *******************/

int		check_sort(t_pile	**pile_a);

void	sort_three(t_pile **pile_a);

void	bymedian(int tab_len, t_pile **pile_a, t_pile **pile_b);

t_pile	*get_cheapest(t_pile **pile_a, t_pile **pile_b);

/******************* SORTING_2 *******************/

void	sort(t_pile **pile_a, t_pile **pile_b);

/******************* SUPERCALCULATOR *******************/

int		r_cheaper(t_pile *to_put_top, t_pile **pile);

t_pile	*get_to_put_top_a(t_pile *to_sort, t_pile **pile_a);

int		move_to_top(t_pile *to_sort, t_pile **pile);

int		count_move(t_pile *to_sort, t_pile **pile_a, t_pile **pile_b);

/******************* LST_UPDATE *******************/

void	p_pupdate(t_pile **pile_a, t_pile **pile_b);

void	o_pupdate(t_pile **pile);

/******************* OPTIMIZATION *******************/

void	bybigmedian(int median_rank, int tab_len, t_pile **pile_a, t_pile **pile_b);

void	bysmolmedian(int median_rank, int tab_len, t_pile **pile_a, t_pile **pile_b);

/******************* TEMP_FILE *******************/

void	print_list_content(t_pile **pile_a,t_pile **pile_b);

#endif

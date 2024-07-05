/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:17:47 by fli               #+#    #+#             */
/*   Updated: 2024/07/05 18:00:29 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
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

/******************* UTILS *******************/

void	free_split(char	**split_tab);

int		num_tab_check_double(int num, int *num_tab, int n);

#endif

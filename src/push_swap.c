/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:16:01 by fli               #+#    #+#             */
/*   Updated: 2024/07/06 17:53:41 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int	*num_tab; //malloced

	if (argc <= 1)
		return (0);
	num_tab = parsing(argc, argv);
	if (num_tab == NULL)
		return (write(2, "Error\n", 7), 0);

	// int i = 0;
	// while (i < argc)
	// {
	// 	dprintf(2, "%s\n", argv[i]);
	// 	i++;
	// }
}

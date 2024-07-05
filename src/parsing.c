/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:15:57 by fli               #+#    #+#             */
/*   Updated: 2024/07/05 17:57:50 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_entry(int n_entry, char **entry)
{
	int	i;
	int	j;

	i = 0;
	while (i < n_entry)
	{
		j = 0;
		if (entry[i][j] == '-' || entry[i][j] == '+')
		{
			j++;
			if (ft_isdigit(entry[i][j] == FALSE))
				return (FALSE);
		}
		while(entry[i][j] != '\0')
		{
			if (ft_isdigit(entry[i][j]) == FALSE)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

static int	*atoi_tab(int n_entry, char **entry)
{
	int	i;
	int	num;
	int	*num_tab;

	num_tab = malloc(n_entry * sizeof(int));
	if (num_tab == NULL)
		return (NULL);
	i = 0;
	while (i < n_entry)
	{
		num = ft_atoi(entry[i]);
		if (num_tab_check_double(num, num_tab, i + 1) == TRUE)
			return (free(num_tab), NULL);
		num_tab[i] = num;
		i++;
	}
	return (num_tab);
}

static void	free_entry(int argc, char	**entry)
{
	if (argc == 2)
		free_split(entry);
}

int	*parsing(int argc, char **argv)
{
	int		n_entry;
	char	**entry;
	int		*num_tab;

	n_entry = 0;
	if (argc == 2)
	{
		entry = ft_split(argv[1], ' ');
		if (entry == NULL)
			return (NULL);
		while (entry[n_entry] != 0)
			n_entry++;
	}
	else
	{
		entry = ++argv;
		n_entry = argc - 1;
	}
	if (check_entry(n_entry, entry) == FALSE)
		return (free_entry(argc, entry), NULL);
	num_tab = atoi_tab(n_entry, entry);
		return (free_entry(argc, entry), NULL);
	free_entry(argc, entry);
	return (num_tab);
}

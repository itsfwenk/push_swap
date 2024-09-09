/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:15:57 by fli               #+#    #+#             */
/*   Updated: 2024/07/14 11:54:41 by fli              ###   ########.fr       */
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
		while (entry[i][j] != '\0')
		{
			if (ft_isdigit(entry[i][j]) == FALSE)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

static long	ft_atol(const char *nptr)
{
	int			i;
	long		nbr;
	long		sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (nptr [i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
		{
			nbr = nbr * 10;
			nbr = nbr + (nptr[i++] - '0');
		}
	}
	return (sign * nbr);
}

static int	*atol_tab(int n_entry, char **entry)
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
		num = ft_atol(entry[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (free(num_tab), NULL);
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
		if (entry[0] == NULL)
			return (free(entry), NULL);
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
	num_tab = atol_tab(n_entry, entry);
	free_entry(argc, entry);
	return (num_tab);
}

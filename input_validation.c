/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:05:36 by tbui-quo          #+#    #+#             */
/*   Updated: 2023/08/22 15:51:59 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_valid_input(char *argv[], int size)
{
	size_t	index;

	index = 1;

	if (is_not_a_duplicate(argv, size))
		return (false);
	while (argv[index] != NULL)
	{
		if (is_valid_number(argv[index]))
			return (false);
		index++;
	}

	return (true);
}

bool	is_valid_start_character(char c)
{
	return (c == '+' || c == '-' || (c >= '0' && c <= '9'));
}

bool	is_valid_digit(char c)
{
	return (c >= '0' && c <= '9');
}
// maybe sign in separate function

bool	is_valid_number(char *str_nbr)
{
	if (!is_valid_start_character(*str_nbr))
		return (false);

	if ((*str_nbr == '+' || *str_nbr == '-') && !is_valid_digit(str_nbr[1]))
		return (false);

	while (*++str_nbr)
	{
		if (!is_valid_digit(*str_nbr))
			return (false);
	}
	return (true);
}

bool	is_not_a_duplicate(char *argv[], int size)
{
	size_t	outer_index;
	size_t	inner_index;

	outer_index = 0;
	while (outer_index < size -1)
	{
		inner_index = outer_index + 1;
		while (inner_index < size)
		{
			if (strcmp(argv[outer_index], argv[inner_index]) == 0)
				return (false);
			inner_index++;
		}
		outer_index++;
	}

	return (true);
}

// still something wrong but i think it the duplicate function works okay
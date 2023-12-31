/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:05:36 by tbui-quo          #+#    #+#             */
/*   Updated: 2023/09/12 17:16:07 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_valid_input(char **input, size_t size, size_t argc)
{
	size_t	index;

	index = 0;
	while (input[index] != NULL)
	{
		if (!is_valid_number(input[index])
			|| !is_valid_int_range(input[index]))
			return (false);
	index++;
	}
	if (has_no_duplicate_in_input(input, size, argc))
		return (true);
	else
		return (false);
}

bool	is_valid_number(char *str_nbr)
{
	if (!is_valid_start_character(*str_nbr))
		return (false);
	if ((*str_nbr == '+' || *str_nbr == '-')
		&& !is_valid_digit(str_nbr[1]))
		return (false);
	while (*++str_nbr)
	{
		if (!is_valid_digit(*str_nbr))
			return (false);
	}
	return (true);
}

bool	is_valid_int_range(char *str_nbr)
{
	if (ft_atoll(str_nbr) > INT_MAX || ft_atoll(str_nbr) < INT_MIN)
		return (false);
	return (true);
}

bool	has_no_duplicate_in_input(char **input, size_t size, size_t argc)
{
	size_t	outer_index;
	size_t	inner_index;
	int		number1;
	int		number2;

	outer_index = 0;
	if (argc == 2)
		size = count_items_in_array(input);
	while (outer_index < size -1)
	{
		inner_index = outer_index + 1;
		while (inner_index < size)
		{
			number1 = ft_atoi(input[outer_index]);
			number2 = ft_atoi(input[inner_index]);
			if (number1 == number2)
				return (false);
			inner_index++;
		}
		outer_index++;
	}
	return (true);
}

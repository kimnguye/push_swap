/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:09:00 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/20 16:29:45 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* take a list of integers as input (the 1st is at the top of the pile)
and display instructions to sort the pile */
int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	if (argc < 2)
		return (1);
	a = malloc (sizeof(t_list *));
	*a = NULL;
	b = malloc (sizeof(t_list *));
	*b = NULL;
	if (!a || !b)
		return (ft_printf("Error\n"), 1);
	if (ft_error(argc - 1, &argv[1], a))
		return (free(b), ft_printf("Error\n"), 1);
	instructions_ctr(a, b);
	return (ft_free_list(a), ft_free_list(b), 0);
}

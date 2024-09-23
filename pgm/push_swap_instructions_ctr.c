/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions_ctr.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:23:42 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/20 15:48:25 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		return (ft_printf("Error\n"), 1);
	ft_printf("\n-----------------\n   TOTAL: %i\n", instructions_ctr(a, b));
	ft_printf("-----------------\n");
	ft_print_list(a);
	if (ft_ps_is_sorted(a, b))
		ft_printf("Sorted list: YES\n");
	else
		ft_printf("Error: the list is not sorted !\n");
	ft_free_list(a);
	ft_free_list(b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_tester.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:33:07 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/20 15:33:49 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	*b;

	if (argc < 2)
		return (1);
	a = malloc (sizeof(t_list *));
	*a = NULL;
	if (!a)
		return (ft_printf("Error\n"), 1);
	if (ft_error(argc - 1, &argv[1], a))
		return (ft_printf("Error\n"), 1);
	ft_sort_list(a);
	ft_print_list(a);
	if (ft_ps_is_sorted(a, &b))
		ft_printf("Sorted list: YES\n");
	else
		ft_printf("Error: the list is not sorted !\n");
	return (ft_free_list(a), 0);
}

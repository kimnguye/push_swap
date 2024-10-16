/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules_tester.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:09:00 by kimnguye          #+#    #+#             */
/*   Updated: 2024/10/16 17:45:45 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//Enter a list of numbers (stack A) as arguments to the program.
/* main pour verifier que les rules fonctionnent et que le parsing fonctionne */
int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;
	char	*str;


	str = "10 20 30";
	if (argc < 2)
		return (1);
	a = malloc (sizeof(t_list *));
	*a = NULL;
	b = malloc (sizeof(t_list *));
	*b = NULL;
	if (!a)
		return (ft_printf("Error\n"), 1);
	if (ft_error(argc - 1, &argv[1], a))
		return (ft_printf("Error\n"), 1);
	if (ft_error(1, &str, b))
		return (ft_printf("Error\n"), 1);
	ft_printf("Parsing : OK\n");
	ft_viewer(a, b);
	ft_rot(a, A_PRINT);
	ft_viewer(a, b);
	ft_rrot(a, A_PRINT);
	ft_viewer(a, b);
	ft_swap(a, A_PRINT);
	ft_viewer(a, b);
	ft_swap(b, B_PRINT);
	ft_viewer(a, b);
	ft_ss(a, b);
	ft_viewer(a, b);
	ft_rot(b, B_PRINT);
	ft_viewer(a, b);
	ft_rrot(b, B_PRINT);
	ft_viewer(a, b);
	ft_push(a, b, A_PRINT);
	ft_viewer(a, b);
	ft_push(b, a, B_PRINT);
	ft_viewer(a, b);
	ft_rr(a, b);
	ft_viewer(a, b);
	ft_rrr(a, b);
	ft_viewer(a, b);
	ft_free_list(a);
	ft_free_list(b);
	return (0);
}

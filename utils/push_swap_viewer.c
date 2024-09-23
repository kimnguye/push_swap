/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_viewer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:24:43 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/16 12:32:51 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_viewer(t_list **a, t_list **b)
{
	t_list	*ptr_a;
	t_list	*ptr_b;

	ptr_a = *a;
	ptr_b = *b;
	ft_printf("stack A		stack B\n");
	while (ptr_a != NULL && ptr_b != NULL)
	{
		ft_printf("  %i		  %i\n", ptr_a->nb, ptr_b->nb);
		ptr_b = ptr_b->next;
		ptr_a = ptr_a->next;
	}
	while (ptr_a != NULL)
	{
		ft_printf("  %i\n", ptr_a->nb);
		ptr_a = ptr_a->next;
	}
	while (ptr_b != NULL)
	{
		ft_printf("		  %i\n", ptr_b->nb);
		ptr_b = ptr_b->next;
	}
	ft_printf("---------------------------\n");
}

void	ft_print_list(t_list **a)
{
	int		i;
	t_list	*ptr;

	ptr = *a;
	i = 0;
	ft_printf("      list:\n");
	ft_printf("-----------------\n");
	while (ptr->next)
	{
		ft_printf("	%i \n", ptr->nb);
		ptr = ptr->next;
		i++;
	}
	ft_printf("	%i \n", ptr->nb);
	ft_printf("-----------------\n");
}

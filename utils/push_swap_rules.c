/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:28:51 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/20 15:10:32 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* swap the first 2 elements of the stack
can print the instruction*/
void	ft_swap(t_list **pile, char print)
{
	t_list	*ptr;

	if (!*pile || !(*pile)->next)
		return ;
	ptr = (*pile)->next;
	(*pile)->next = ptr->next;
	ptr->next = *pile;
	*pile = ptr;
	if (print == A_PRINT)
		ft_printf("sa\n");
	if (print == B_PRINT)
		ft_printf("sb\n");
}

/*push the first element of B to the top of A
do nothing if b is empty
print the instruction*/
void	ft_push(t_list **a, t_list **b, char print)
{
	t_list	*ptr;

	if (!*b)
		return ;
	ptr = (*b);
	*b = (*b)->next;
	ft_lstadd_front(a, ptr);
	if (print == A_PRINT)
		ft_printf("pa\n");
	if (print == B_PRINT)
		ft_printf("pb\n");
}

/*rotate a stack (first becomes last)
can print or not the instruction*/
void	ft_rot(t_list **pile, char print)
{
	t_list	*tmp;

	tmp = *pile;
	if (!tmp || !tmp->next)
		return ;
	*pile = (*pile)->next;
	tmp->next = NULL;
	ft_lstadd_back(pile, tmp);
	if (print == A_PRINT)
		ft_printf("ra\n");
	if (print == B_PRINT)
		ft_printf("rb\n");
}

/*reverse rotate a stack (last become first)
can print or not the instruction*/
void	ft_rrot(t_list **pile, char print)
{
	t_list	*tmp;

	if (!*pile || !(*pile)->next)
		return ;
	tmp = ft_lstlast(*pile);
	ft_lstbfrlast(*pile)->next = NULL;
	ft_lstadd_front(pile, tmp);
	ft_lstlast(*pile)->next = NULL;
	if (print == A_PRINT)
		ft_printf("rra\n");
	if (print == B_PRINT)
		ft_printf("rrb\n");
}

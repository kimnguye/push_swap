/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:09:38 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/23 16:41:58 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_max(t_list *stack);
int		ft_min(t_list *stack);
void	ft_free_list(t_list **lst);
int		ft_ps_is_sorted(t_list **pile_a, t_list **pile_b);
t_list	**ft_dup_list(t_list **lst, int siz);

t_list	**ft_dup_list(t_list **lst, int siz)
{
	t_list	**dup;
	t_list	*ptr;
	int		i;

	dup = malloc(sizeof(t_list *));
	ptr = *lst;
	i = 0;
	while (i < siz)
	{
		ft_lstadd_back(dup, ft_lstnew(ptr->nb));
		ptr = ptr->next;
		i++;
	}
	return (dup);
}

/*returns the biggest number of the stack
*/
int	ft_max(t_list *stack)
{
	int	max;

	if (!stack)
		return (INT_NO_STACK);
	max = stack->nb;
	while (stack)
	{
		if (max < stack->nb)
			max = stack->nb;
		stack = stack->next;
	}
	return (max);
}

/*returns the lowest number of the stack*/
int	ft_min(t_list *stack)
{
	int		min;

	if (!stack)
		return (INT_NO_STACK);
	min = stack->nb;
	while (stack)
	{
		if (min > stack->nb)
			min = stack->nb;
		stack = stack->next;
	}
	return (min);
}

/*returns 1 if A is sorted and B is empty
returns 0 if not*/
int	ft_ps_is_sorted(t_list **pile_a, t_list **pile_b)
{
	t_list	*ptr;

	if (!*pile_a)
		return (0);
	ptr = *pile_a;
	while (ptr->next)
	{
		if (ptr->nb > ptr->next->nb)
			return (0);
		ptr = ptr->next;
	}
	ptr = *pile_b;
	if (ptr)
		return (0);
	return (1);
}

//free the list
void	ft_free_list(t_list **lst)
{
	int		n;
	int		i;
	t_list	*ptr;

	ptr = NULL;
	if (*lst == NULL)
		return (free(lst));
	i = 0;
	n = ft_lstsize(*lst);
	while (i < n)
	{
		ptr = (*lst)->next;
		free(*lst);
		*lst = ptr;
		i++;
	}
	free(lst);
}

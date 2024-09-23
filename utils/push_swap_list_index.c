/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:09:53 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/18 15:10:54 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_pa_index(t_list **a, t_list **b);
int		ft_min_index(t_list *stack);
int		ft_max_index(t_list *stack);

/*returns the index of the biggest number of the stack
*/
int	ft_max_index(t_list *stack)
{
	int	max;
	int	i_max;
	int	i;

	if (!stack)
		return (-2);
	i = 0;
	i_max = 0;
	max = stack->nb;
	while (stack)
	{
		if (max < stack->nb)
		{
			max = stack->nb;
			i_max = i;
		}
		stack = stack->next;
		i++;
	}
	return (i_max);
}

/*returns the index of the lowest number of the stack*/
int	ft_min_index(t_list *stack)
{
	int		min;
	int		i_min;
	int		i;

	if (!stack)
		return (-2);
	i = 0;
	i_min = 0;
	min = stack->nb;
	while (stack)
	{
		if (min > stack->nb)
		{
			min = stack->nb;
			i_min = i;
		}
		stack = stack->next;
		i++;
	}
	return (i_min);
}

/*find the right index for top(b) to be push to the sorted stack A*/
int	ft_pa_index(t_list **a, t_list **b)
{
	t_list	*ptr;
	int		i;

	i = 0;
	ptr = *a;
	while (ptr)
	{
		if (ptr->nb > (*b)->nb)
			return (i);
		ptr = ptr->next;
		i++;
	}
	return (i);
}

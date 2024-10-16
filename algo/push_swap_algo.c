/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:50:04 by kimnguye          #+#    #+#             */
/*   Updated: 2024/10/16 17:36:03 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	instructions_ctr(t_list **a, t_list **b);
int	ft_algo_three(t_list **a);
int	ft_algo_four(t_list **a, t_list **b);
int	ft_algo_five(t_list **a, t_list **b, int siz);

/*check if the list is already sorted,
print the list of instructions to sort A
returns the nb of instructions
returns -1 if malloc failed*/
int	instructions_ctr(t_list **a, t_list **b)
{
	int	ctr;
	int	siz;

	ctr = 0;
	siz = ft_lstsize(*a);
	if (ft_ps_is_sorted(a, b))
		return (0);
	if (siz == 2)
		return (ft_swap(a, A_PRINT), 1);
	if (siz == 3)
		ctr = ft_algo_three(a);
	else if (siz == 4)
		ctr = ft_algo_four(a, b);
	else if (siz == 5)
		ctr = ft_algo_five(a, b, siz);
	else
		ctr = ft_turkish(a, b, siz);
	return (ctr);
}

int	ft_algo_five(t_list **a, t_list **b, int siz)
{
	int	ctr;
	int	n;

	if (ft_is_sorted(a))
		return (0);
	ft_push(b, a, B_PRINT);
	ctr = ft_algo_four(a, b);
	n = ft_pa_index(a, b);
	if (siz - 1 - n < n)
	{
		n = siz - n - 1;
		ctr += ft_nrrot(a, A_PRINT, n);
		ft_push(a, b, A_PRINT);
		ctr += ft_nrot(a, A_PRINT, n + 1);
	}
	else
	{
		ctr += ft_nrot(a, A_PRINT, n);
		ft_push(a, b, A_PRINT);
		ctr += ft_nrrot(a, A_PRINT, n);
	}
	return (ctr + 2);
}

/*sort 4 numbers: we push an xtrem value*/
int	ft_algo_four(t_list **a, t_list **b)
{
	int	i_min;
	int	ctr;

	if (ft_is_sorted(a))
		return (0);
	ctr = 3;
	i_min = ft_min_index(*a);
	if (i_min == 0 || ft_max_index(*a) == 0)
		ctr = 2;
	else if (i_min == 3 || ft_max_index(*a) == 3)
		ft_rrot(a, A_PRINT);
	else if (i_min == 1 || i_min == 2)
		ft_swap(a, A_PRINT);
	ft_push(b, a, B_PRINT);
	ctr += ft_algo_three(a);
	ft_push(a, b, A_PRINT);
	if (ft_max_index(*a) == 0)
		return (ft_rot(a, A_PRINT), ctr + 1);
	return (ctr);
}

/*executes instructions to sort 3 numbers
returns the nb of instructions executed*/
int	ft_algo_three(t_list **a)
{
	int	i_min;
	int	i_max;

	i_min = ft_min_index(*a);
	i_max = ft_max_index(*a);
	if (i_min == 0 && i_max == 2)
		return (0);
	if (i_min == 0 && i_max == 1)
	{
		ft_swap(a, A_PRINT);
		ft_rot(a, A_PRINT);
		return (2);
	}
	if (i_min == 1 && i_max == 0)
		return (ft_rot(a, A_PRINT), 1);
	if (i_min == 1 && i_max == 2)
		return (ft_swap(a, A_PRINT), 1);
	if (i_min == 2 && i_max == 1)
		return (ft_rrot(a, A_PRINT), 1);
	ft_swap(a, A_PRINT);
	ft_rrot(a, A_PRINT);
	return (2);
}

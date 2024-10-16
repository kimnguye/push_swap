/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_turkish.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:31:09 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/18 14:44:44 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_turkish(t_list **a, t_list **b, int siz);
int		push_to_b(t_list **a, t_list **b, t_info *info);
int		push_back_to_a(t_list **a, t_list **b, t_info *info);
void	ft_update_info2(t_info *info, t_list *elem);
int		ft_end_turkish(t_list **a, int size);

/*returns (-1) if malloc failed
step 0: push to B (2 times) and initialize info
step 1: push dans B l'element optimum en triant (descending)
step 2: sort the 3 numbers left in A
step 3: update the info and push back all numbers to A
step 4: put back numbers in A
*/
int	ft_turkish(t_list **a, t_list **b, int total_size_a)
{
	int		ctr;
	t_info	*info;

	ctr = 2;
	ft_push(b, a, B_PRINT);
	ft_push(b, a, B_PRINT);
	info = ft_init_info(total_size_a, b, 'd');
	if (!info)
		return (-1);
	while (info->curr_siz_elemlist > 3)
	{
		ctr += push_to_b(a, b, info);
		ft_update_info2(info, *b);
	}
	ctr += ft_algo_three(a);
	ft_update_info(info, total_size_a, a, 'a');
	while (info->curr_size_targlist < total_size_a)
	{
		ctr += push_back_to_a(a, b, info);
		ft_update_info2(info, *a);
	}
	ft_end_turkish(a, total_size_a);
	return (free(info), ctr);
}

/*rotate or reverse rotate until min is on top
returns the nb of instructions executed
returns -2 on error*/
int	ft_end_turkish(t_list **a, int size)
{
	t_tks	*moves;
	int		ctr;

	moves = malloc(sizeof(t_tks));
	if (!moves)
		return (-2);
	ft_init_moves(moves);
	ctr = ft_min_index(*a);
	ft_move_to_top_a(moves, size, ctr);
	ctr = ft_nrot(a, A_PRINT, moves->ra);
	ctr += ft_nrrot(a, A_PRINT, moves->rra);
	return (free(moves), ctr);
}

/*calculates the opti elem to push to B,
executes and prints the instructions.
returns the nb of instrcutions executed
returns -2 if errors*/
int	push_to_b(t_list **a, t_list **b, t_info *info)
{
	t_list	*ptr;
	t_tks	*min_moves;
	t_tks	*calc_moves;

	ptr = *a;
	info->index_elem = 0;
	calc_moves = malloc(sizeof(t_tks));
	min_moves = malloc(sizeof(t_tks));
	if (!calc_moves || !min_moves)
		return (free(calc_moves), free(min_moves), -2);
	ft_init_moves(min_moves);
	while (ptr)
	{
		ft_calc_moves(calc_moves, ptr, b, info);
		if (calc_moves->tot == 0)
			return (free(min_moves),
				ft_exec_print_moves(a, b, calc_moves, info));
		if (!min_moves->tot || calc_moves->tot < min_moves->tot)
			ft_copy_moves(min_moves, calc_moves);
		ptr = ptr->next;
		info->index_elem++;
	}
	free(calc_moves);
	return (ft_exec_print_moves(a, b, min_moves, info));
}

/*calculates the best element to push to A,
executes and prints it and then :
returns the nb of instrcutions executed*/
int	push_back_to_a(t_list **a, t_list **b, t_info *info)
{
	t_list	*ptr;
	t_tks	*min_moves;
	t_tks	*calc_moves;

	ptr = *b;
	info->index_elem = 0;
	calc_moves = malloc(sizeof(t_tks));
	min_moves = malloc(sizeof(t_tks));
	if (!calc_moves || !min_moves)
		return (free(calc_moves), free(min_moves), -2);
	ft_init_moves(min_moves);
	while (ptr)
	{
		ft_calc_moves_2(calc_moves, ptr, a, info);
		if (calc_moves->tot == 0)
			return (free(min_moves),
				ft_exec_print_moves(a, b, calc_moves, info));
		if (!min_moves->tot || calc_moves->tot < min_moves->tot)
			ft_copy_moves(min_moves, calc_moves);
		ptr = ptr->next;
		info->index_elem++;
	}
	free(calc_moves);
	return (ft_exec_print_moves(a, b, min_moves, info));
}

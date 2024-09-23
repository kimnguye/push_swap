/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_turkish_exec_moves.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:02:29 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/18 14:45:39 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_exec_print_moves(t_list **a, t_list **b, t_tks *moves, t_info *info);
void	ft_copy_moves(t_tks *copy, t_tks *moves);
void	ft_init_moves(t_tks *moves);

void	ft_init_moves(t_tks *moves)
{
	moves->ra = 0;
	moves->rb = 0;
	moves->rr = 0;
	moves->rra = 0;
	moves->rrb = 0;
	moves->rrr = 0;
	moves->tot = 0;
}

void	ft_copy_moves(t_tks *copy, t_tks *moves)
{
	copy->ra = moves->ra;
	copy->rb = moves->rb;
	copy->rr = moves->rr;
	copy->rra = moves->rra;
	copy->rrb = moves->rrb;
	copy->rrr = moves->rrr;
	copy->tot = moves->tot;
}

/*executes the moves (rot and reverse rot);
prints the instructions;
frees t_tks *moves;
returns the nb of instructions executed;*/
int	ft_exec_print_moves(t_list **a, t_list **b, t_tks *moves, t_info *info)
{
	int	ctr;

	ctr = moves->tot + 1;
	while (moves->rr)
	{
		ft_rr(a, b);
		moves->rr--;
	}
	while (moves->rrr)
	{
		ft_rrr(a, b);
		moves->rrr--;
	}
	ft_nrot(a, A_PRINT, moves->ra);
	ft_nrot(b, B_PRINT, moves->rb);
	ft_nrrot(a, A_PRINT, moves->rra);
	ft_nrrot(b, B_PRINT, moves->rrb);
	if (info->sort == 'a')
		ft_push(a, b, A_PRINT);
	else
		ft_push(b, a, B_PRINT);
	return (free(moves), ctr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_define.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:25:43 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/18 14:39:05 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_DEFINE_H
# define PUSH_SWAP_DEFINE_H

# define A_PRINT 'a'
# define B_PRINT 'b'
# define NO 'n'

# define INT_NO_STACK -99

typedef struct s_rdx {
	int	*val;
	int	*old_pos;
	int	*new_pos;
}	t_rdx;

typedef struct s_tks {
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rr;
	int	rrr;
	int	tot;

}	t_tks;

typedef struct s_info {
	int	index_elem;
	int	index_targ;
	int	curr_siz_elemlist;
	int	curr_size_targlist;
	int	min_targlist;
	int	max_targlist;
	int	sort;
}	t_info;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_turkish_calc_moves.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:39:08 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/18 14:45:29 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_calc_moves(t_tks *moves, t_list *elem, t_list **list, t_info *info);
void	ft_calc_moves_2(t_tks *moves, t_list *obj, t_list **lst, t_info *info);
void	ft_move_to_top_a(t_tks *moves, int lst_size, int index);
void	ft_move_to_top_b(t_tks *moves, int lst_size, int index);
void	ft_opti_moves(t_tks *moves);

/*step 1 trouver lindex de elem dans la liste
step 2-a si indice proche du bas alors utiliser rrot
step 2-b si indice proche du haut alors utiliser rot
*/
void	ft_move_to_top_a(t_tks *moves, int lst_size, int index)
{
	if (index == 0)
		return ;
	else if (lst_size == index + 1)
		moves->rra = 1;
	else if (lst_size - 1 - index < index)
		moves->rra = lst_size - index;
	else
		moves->ra = index;
}

/*step 1 trouver lindex de elem dans la liste
step 2-a si indice proche du bas alors utiliser rrot
step 2-b si indice proche du haut alors utiliser rot
*/
void	ft_move_to_top_b(t_tks *moves, int lst_size, int index)
{
	if (index == 0)
		return ;
	else if (lst_size == index + 1)
		moves->rrb = 1;
	else if (lst_size - 1 - index < index)
		moves->rrb = lst_size - index;
	else
		moves->rb = index;
}

/*optimize the number of rotations and calculate the total*/
void	ft_opti_moves(t_tks *moves)
{
	moves->rr = 0;
	moves->rrr = 0;
	moves->tot = 0;
	while (moves->ra && moves->rb)
	{
		moves->ra--;
		moves->rb--;
		moves->rr++;
	}
	while (moves->rra && moves->rrb)
	{
		moves->rra--;
		moves->rrb--;
		moves->rrr++;
	}
	moves->tot = moves->ra + moves->rb
		+ moves->rr + moves->rra + moves->rrb
		+ moves->rrr;
}

/*fills moves with instructions for elem
to be pushed to targlist (descending sorting)
0 trouver la target dans list
1 calculer cb de rot ou rrot on a besoin pour le mettre en haut
2 calculer cb de rot ou rrot ou a besoin pour mettre target en haut
3 simplifier les rot et rrot pour rr et rrr + calculer moves total
4 retourner les moves a effectuer + le nb de moves*/
void	ft_calc_moves(t_tks *moves, t_list *elem,
	t_list **targlist, t_info *info)
{
	t_list	*target;

	ft_init_moves(moves);
	target = ft_find_target_d(elem, targlist, info);
	ft_move_to_top_a(moves, info->curr_siz_elemlist, info->index_elem);
	ft_move_to_top_b(moves, info->curr_size_targlist, info->index_targ);
	ft_opti_moves(moves);
	free(target);
}

/*fills moves with instructions for elem
to be pushed to targlist (ascending sorting)
0 trouver la target dans list
1 calculer cb de rot ou rrot on a besoin pour le mettre en haut
2 calculer cb de rot ou rrot ou a besoin pour mettre target en haut
3 simplifier les rot et rrot pour rr et rrr + calculer moves total
4 retourner les moves a effectuer + le nb de moves*/
void	ft_calc_moves_2(t_tks *moves, t_list *elem,
	t_list **targlist, t_info *info)
{
	t_list	*target;

	ft_init_moves(moves);
	target = ft_find_target_a(elem, targlist, info);
	ft_move_to_top_a(moves, info->curr_size_targlist, info->index_targ);
	ft_move_to_top_b(moves, info->curr_siz_elemlist, info->index_elem);
	ft_opti_moves(moves);
	free(target);
}
//ft_printf("min %i et max %i\n", info->min_targlist, info->max_targlist);

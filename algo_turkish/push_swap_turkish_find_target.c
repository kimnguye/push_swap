/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_turkish_find_target.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:20:06 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/18 14:45:54 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_find_target_d(t_list *elem, t_list **list, t_info *info);
t_list	*ft_find_target_a(t_list *elem, t_list **list, t_info *info);

/*returns the index of the target of elem in info (ascending sorting)
si elem appartient a info: target = plus petit nb > elem
sinon: cest le nouveau min/max, target = old_min*/
t_list	*ft_find_target_a(t_list *elem, t_list **list, t_info *info)
{
	t_list	*target;
	t_list	*ptr;
	int		i;

	ptr = *list;
	target = malloc (sizeof(t_list));
	target->nb = info->min_targlist;
	info->index_targ = ft_min_index(*list);
	i = 0;
	if (elem->nb > info->min_targlist && elem->nb < info->max_targlist)
	{
		while (ptr)
		{
			if ((ptr->nb > elem->nb && ptr->nb < target->nb)
				|| (elem->nb > target->nb))
			{
				target->nb = ptr->nb;
				info->index_targ = i;
			}
			i++;
			ptr = ptr->next;
		}
		return (target);
	}
	return (target);
}

/*returns the index of the target of elem in info (descending sorting)
si elem appartient a info: target = plus grand nb < elem
sinon: cest le nouveau min/max, target = old_max*/
t_list	*ft_find_target_d(t_list *elem, t_list **targlist, t_info *info)
{
	t_list	*target;
	t_list	*ptr;
	int		i;

	ptr = *targlist;
	target = malloc (sizeof(t_list));
	target->nb = info->max_targlist;
	info->index_targ = ft_max_index(*targlist);
	i = 0;
	if (elem->nb > info->min_targlist && elem->nb < info->max_targlist)
	{
		while (ptr)
		{
			if ((ptr->nb < elem->nb && ptr->nb > target->nb)
				|| (elem->nb < target->nb))
			{
				target->nb = ptr->nb;
				info->index_targ = i;
			}
			i++;
			ptr = ptr->next;
		}
		return (target);
	}
	return (target);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:33:07 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/20 15:35:10 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_list(t_list **lst);

void	ft_sort_list(t_list **lst)
{
	int		tmp;
	t_list	*ptr;

	ptr = *lst;
	while (ptr != NULL && ptr->next != NULL)
	{
		if (ptr->nb > ptr->next->nb)
		{
			tmp = ptr->nb;
			ptr->nb = ptr->next->nb;
			ptr->next->nb = tmp;
			ptr = *lst;
		}
		else
			ptr = ptr->next;
	}
}

/*returns 1 if pile_a is sorted
returns 0 if not*/
int	ft_is_sorted(t_list **pile_a)
{
	t_list	*ptr;

	ptr = *pile_a;
	while (ptr->next)
	{
		if (ptr->nb > ptr->next->nb)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

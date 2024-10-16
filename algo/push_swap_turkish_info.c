/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_turkish_info.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:33:26 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/18 14:43:46 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_info	*ft_init_info(int tot_siz, t_list **targlist, char c);
void	ft_update_info(t_info *info, int tot_siz, t_list **targlist, char c);
void	ft_update_info2(t_info *info, t_list *elem);

/*initialize the info according to the type of sorting (c == 'd' or c == 'a)*/
t_info	*ft_init_info(int tot_siz, t_list **targlist, char c)
{
	t_info	*info;
	int		nb;

	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->sort = c;
	info->min_targlist = ft_min(*targlist);
	info->max_targlist = ft_max(*targlist);
	info->index_elem = 0;
	info->index_targ = 0;
	nb = 3;
	if (c == 'd')
		nb = 2;
	info->curr_siz_elemlist = tot_siz - nb;
	info->curr_size_targlist = nb;
	return (info);
}

/*update the info according to the type of sorting (c == 'd' or c == 'a)*/
void	ft_update_info(t_info *info, int tot_siz, t_list **targlist, char c)
{
	info->sort = c;
	info->min_targlist = ft_min(*targlist);
	info->max_targlist = ft_max(*targlist);
	info->index_elem = 0;
	info->index_targ = 0;
	if (c == 'd')
	{
		info->curr_siz_elemlist = tot_siz - 2;
		info->curr_size_targlist = 2;
	}
	else
	{
	info->curr_siz_elemlist = tot_siz - 3;
	info->curr_size_targlist = 3;
	}
}

void	ft_update_info2(t_info *info, t_list *elem)
{
	info->curr_siz_elemlist--;
	info->curr_size_targlist++;
	if (elem->nb > info->max_targlist)
		info->max_targlist = elem->nb;
	else if (elem->nb < info->min_targlist)
		info->min_targlist = elem->nb;
}

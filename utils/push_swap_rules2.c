/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:09:54 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/09 12:43:54 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*rotate stack A and B and print the instruction*/
void	ft_rr(t_list **pile_a, t_list **pile_b)
{
	ft_rot(pile_a, NO);
	ft_rot(pile_b, NO);
	ft_printf("rr\n");
}

/*swap a and swap b
print the instruction*/
void	ft_ss(t_list **a, t_list **b)
{
	ft_swap(a, NO);
	ft_swap(b, NO);
	ft_printf("ss\n");
}

void	ft_rrr(t_list **pile_a, t_list **pile_b)
{
	ft_rrot(pile_a, NO);
	ft_rrot(pile_b, NO);
	ft_printf("rrr\n");
}

/*executes n times rot and returns n*/
int	ft_nrot(t_list **pile, char print, int n)
{
	while (n > 0)
	{
		ft_rot(pile, print);
		n--;
	}
	return (n);
}

/*executes n times rrot and returns n*/
int	ft_nrrot(t_list **pile, char print, int n)
{
	while (n > 0)
	{
		ft_rrot(pile, print);
		n--;
	}
	return (n);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_translator_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 08:21:02 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/20 16:35:44 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ps_translator(char *instr, t_list **a, t_list **b);
int	ps_swap_translator(char *instr, t_list **a, t_list **b);
int	ps_push_translator(char *instr, t_list **a, t_list **b);

int	ps_swap_translator(char *instr, t_list **a, t_list **b)
{
	if (!ft_strncmp(instr, "sa\n", ft_strlen(instr)))
		return (ft_swap(a, NO), 1);
	if (!ft_strncmp(instr, "sb\n", ft_strlen(instr)))
		return (ft_swap(b, NO), 1);
	if (!ft_strncmp(instr, "ss\n", ft_strlen(instr)))
		return (ft_ss(a, b), 1);
	return (0);
}

int	ps_push_translator(char *instr, t_list **a, t_list **b)
{
	if (!ft_strncmp(instr, "pa\n", ft_strlen(instr)))
		return (ft_push(a, b, NO), 1);
	else if (!ft_strncmp(instr, "pb\n", ft_strlen(instr)))
		return (ft_push(b, a, NO), 1);
	return (0);
}

int	ps_translator(char *instr, t_list **a, t_list **b)
{
	int	len;

	len = ft_strlen(instr);
	if (ps_swap_translator(instr, a, b))
		return (1);
	else if (ps_push_translator(instr, a, b))
		return (1);
	else if (!ft_strncmp(instr, "rra\n", len))
		return (ft_rrot(a, NO), 1);
	else if (!ft_strncmp(instr, "rrb\n", len))
		return (ft_rrot(b, NO), 1);
	else if (!ft_strncmp(instr, "rrr\n", len))
		return (ft_rrr(a, b), 1);
	else if (!ft_strncmp(instr, "ra\n", len))
		return (ft_rot(a, NO), 1);
	else if (!ft_strncmp(instr, "rb\n", len))
		return (ft_rot(b, NO), 1);
	else if (!ft_strncmp(instr, "rr\n", len))
		return (ft_rr(a, b), 1);
	else if (!ft_strncmp(instr, "Error\n", len))
		return (0);
	return (0);
}

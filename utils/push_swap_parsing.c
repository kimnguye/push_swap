/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:11:29 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/22 18:58:52 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_isnumber(const char *s);
long	ft_atol(const char *nptr);
int		ft_error(int n, char **str, t_list **pile_a);
int		ft_doublon(t_list **a);
void	ft_free_and_quit(t_list **a, char **str, int ctr);

/* returns 1 if :
- some args are  not numbers
- some numbers are not int
- there are duplicates */
int	ft_error(int n, char **str, t_list **pile_a)
{
	int	i;
	int	nb;
	int	ctr;

	i = 0;
	ctr = ft_countsplits(str[0], ' ');
	if (n == 1 && ctr > 1)
		str = ft_split(str[0], ' ');
	while (str[i])
	{
		if (!ft_isnumber(str[i]))
			return (ft_free_and_quit(pile_a, str, ctr), 1);
		nb = ft_atoi(str[i]);
		if (ft_atol(str[i]) != nb)
			return (ft_free_and_quit(pile_a, str, ctr), 1);
		ft_lstadd_back(pile_a, ft_lstnew(nb));
		i++;
	}
	if (ctr > 1)
		ft_free_split(str);
	if (ft_doublon(pile_a))
		return (ft_free_list(pile_a), 1);
	return (0);
}

void	ft_free_and_quit(t_list **a, char **str, int ctr)
{
	ft_free_list(a);
	if (ctr > 1)
		ft_free_split(str);
}

/*returns 1 if the list contains duplicates*/
int	ft_doublon(t_list **a)
{
	t_list	*i;
	t_list	*j;

	i = *a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->nb - j->nb == 0)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

// converts a string into a long
long	ft_atol(const char *nptr)
{
	long	nb;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	nb = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if ((nptr[i] == '+' || nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * nb);
}

//returns 1 if the string is a number
//returns 0 otherwise
int	ft_isnumber(const char *a)
{
	int	i;

	i = 0;
	if (a[i] == '+' || a[i] == '-')
		i++;
	while (a[i])
	{
		if (!ft_isdigit(a[i]))
			return (0);
		i++;
	}
	return (1);
}

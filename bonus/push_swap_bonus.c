/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:30:04 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/22 19:26:18 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ps_executor(int fd, t_list **a, t_list **b);
int	ps_translator(char *instr, t_list **a, t_list **b);

/*executes the instructions read in the terminal using gnl*/
int	ps_executor(int fd, t_list **a, t_list **b)
{
	char	*instr;
	int		ctr;

	instr = get_next_line(fd);
	ctr = 0;
	while (instr && instr[0] != '\n')
	{
		if (!ps_translator(instr, a, b))
		{
			free(instr);
			ft_free_list(a);
			ft_free_list(b);
			return (1);
		}
		else
			ctr++;
		free(instr);
		instr = get_next_line(fd);
	}
	free(instr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	if (argc < 2)
		return (1);
	a = malloc (sizeof(t_list *));
	*a = NULL;
	b = malloc (sizeof(t_list *));
	*b = NULL;
	if (!a || !b)
		return (ft_printf("Error\n"), 1);
	if (ft_error(argc - 1, &argv[1], a))
		return (ft_printf("Error\n"), free(b), 1);
	if (ps_executor(0, a, b))
		return (ft_printf("Error\n"), 1);
	if (ft_ps_is_sorted(a, b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_list(a);
	ft_free_list(b);
	return (0);
}

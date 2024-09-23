/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tester.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:23:06 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/18 14:37:46 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../push_swap.h"

// #define TROIS 3
// #define CINQ 5
// #define CENT 100
// #define CINQCENT 500

// void	ps_executor(int	fd, t_list **a, t_list **b);
// int		ps_translator(char *instr, t_list **a, t_list **b);
// void	ps_swap_translator(char *instr, t_list **a, t_list **b);
// void	ps_push_translator(char *instr, t_list **a, t_list **b);

// void	ps_txt(int size, int ctr)
// {
// 	if (size == TROIS)
// 	{
// 		if (ctr <= 3)
// 			ft_printf("nb instr = %i : OK\n", ctr);
// 		else
// 			ft_printf("nb instr = %i : KO\n", ctr);
// 		ft_printf("-----------------------\n");
// 	}
// 	else if (size == CINQ)
// 	{
// 		if (ctr < 9)
// 			ft_printf("nb instr %i < 9: OUTSTANDING\n", ctr);
// 		else if (ctr <= 12)
// 			ft_printf("nb instr = %i <= 12: OK\n", ctr);
// 		else
// 			ft_printf("nb instr = %i : KO\n", ctr);
// 		ft_printf("-----------------------\n");
// 	}
// 	else if (size == CENT)
// 	{
// 		if (ctr <= 700)
// 			ft_printf("\n-----------------------\n  size CENT < 700 : OK\n", ctr);
// 		else
// 			ft_printf("\n-----------------------\n  size CENT : KO\n", ctr);
// 		ft_printf("-----------------------\n");
// 	} else if (size == CINQCENT)
// 	{
// 		if (ctr <= 5500)
// 			ft_printf("\n-----------------------\n  size 500 < 5500 : OK\n", ctr);
// 		else
// 			ft_printf("\n-----------------------\n  size CINQCENT : KO\n", ctr);
// 		ft_printf("-----------------------\n");
// 	}
// }

// /*executes the instructions read in the terminal using gnl*/
// void	ps_executor(int	fd, t_list **a, t_list **b)
// {
// 	char *instr;
// 	int	ctr;
// 	int	size;

// 	size = ft_lstsize(*a);
// 	/*LIS ET EXECUTE LES INSTRUCTIONS AFFICHEES SUR LE TERMINAL*/
// 	instr = get_next_line(fd);
// 	ctr = 0;
// 	while (instr && instr[0] != '\n' && instr[0] != '-')
// 	{
// 		if (!ps_translator(instr, a, b))
// 		{
// 			ft_printf("KO");
// 			return ;
// 		}
// 		else
// 			ctr++;
// 		instr = get_next_line(fd);
// 	}
// 	/*COMPTE LE NB DINSTRUCTIONS*/
// 	ft_printf("\n-----------------------\n   TOTAL INSTR: %i\n", ctr);
// 	ft_printf("-----------------------\n");
// 	ft_printf("list size : %i\n-----------------------\n", size);
// 	/*VERIFIER SI ON PASSE LE NB DINSTRUCTIONS*/
// 	ps_txt(size, ctr);
// }

// int	main(int argc, char **argv)
// {
// 	t_list	**a;
// 	t_list	**b;

// 	if (argc < 2)
// 		return (1);
// 	a = malloc (sizeof(t_list *));
// 	*a = NULL;
// 	b = malloc (sizeof(t_list *));
// 	*b = NULL;
// 	if (!a || !b)
// 		return(ft_printf("Error\n"), 1);
// 	if (ft_error(argc - 1, &argv[1], a))
// 		return(ft_printf("Error\n"), 1);
// 	ps_executor(0, a, b);
// 	if (ft_is_sorted(a))
// 		ft_printf("OK\n");
// 	else
// 		ft_printf("KO\n");
// 	ft_free_list(a);
// 	ft_free_list(b);
// 	return (0);
// }

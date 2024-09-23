/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:24:36 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/20 15:34:55 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"
# include "header/push_swap_define.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

/*bonus*/
int		ps_translator(char *instr, t_list **a, t_list **b);
int		ps_swap_translator(char *instr, t_list **a, t_list **b);
int		ps_push_translator(char *instr, t_list **a, t_list **b);

/*turkish algo utils*/
int		ft_turkish(t_list **a, t_list **b, int siz);
int		push_to_b(t_list **a, t_list **b, t_info *info);
int		push_back_to_a(t_list **a, t_list **b, t_info *info);
int		ft_end_turkish(t_list **a, int size);

t_list	*ft_find_target_d(t_list *elem, t_list **list, t_info *info);
t_list	*ft_find_target_a(t_list *elem, t_list **list, t_info *info);

void	ft_calc_moves(t_tks *moves, t_list *elem, t_list **list, t_info *info);
void	ft_calc_moves_2(t_tks *mov, t_list *elem, t_list **lst, t_info *info);
void	ft_move_to_top_a(t_tks *moves, int lst_size, int index);
void	ft_move_to_top_b(t_tks *moves, int lst_size, int index);

int		ft_exec_print_moves(t_list **a, t_list **b, t_tks *moves, t_info *info);
void	ft_copy_moves(t_tks *copy, t_tks *moves);
void	ft_init_moves(t_tks *moves);

t_info	*ft_init_info(int tot_siz, t_list **targlist, char c);
void	ft_update_info(t_info *info, int tot_siz, t_list **targlist, char c);
void	ft_update_info2(t_info *info, t_list *elem);

/* algo */
int		instructions_ctr(t_list **a, t_list **b);
int		ft_algo_three(t_list **a);
int		ft_algo_four(t_list **a, t_list **b);
int		ft_algo_five(t_list **a, t_list **b, int siz);

/* parsing */
int		ft_isnumber(const char *s);
long	ft_atol(const char *nptr);
int		ft_error(int n, char **str, t_list **pile_a);
int		ft_doublon(t_list **a);

/*rules*/
void	ft_push(t_list **a, t_list **b, char print);
void	ft_swap(t_list **pile, char print);
void	ft_rot(t_list **pile, char print);
void	ft_rrot(t_list **pile, char print);
void	ft_ss(t_list **a, t_list **b);
void	ft_rr(t_list **pile_a, t_list **pile_b);
void	ft_rrr(t_list **pile_a, t_list **pile_b);

/*extra rules*/
int		ft_nrrot(t_list **pile, char print, int n);
int		ft_nrot(t_list **pile, char print, int n);

/*viewer*/
void	ft_print_list(t_list **a);
void	ft_viewer(t_list **a, t_list **b);

/*list utils*/
int		ft_max(t_list *stack);
int		ft_min(t_list *stack);
void	ft_free_list(t_list **lst);
int		ft_ps_is_sorted(t_list **pile_a, t_list **pile_b);
t_list	**ft_dup_list(t_list **lst, int siz);
void	ft_sort_list(t_list **lst);
int		ft_is_sorted(t_list **pile_a);

/* list index utils*/
int		ft_pa_index(t_list **a, t_list **b);
int		ft_min_index(t_list *stack);
int		ft_max_index(t_list *stack);

#endif

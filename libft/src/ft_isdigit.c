/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:12:16 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/02 15:02:21 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*returns 1 if c is a digit
returns 0 otherwise */
int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}
// int	main(void)
// {
// 	printf("%i : %i\n", isdigit('e'), ft_isdigit('e'));
// 	printf("%i : %i\n", isdigit('?'), ft_isdigit('?'));
// 	printf("%i : %i\n", isdigit('1'), ft_isdigit('1'));
// 	printf("%i : %i\n", isdigit('6'), ft_isdigit('6'));
// 	printf("%i : %i\n", isdigit(48), ft_isdigit(48));
// 	printf("%i : %i\n", isdigit('0'), ft_isdigit('0'));
// 	printf("%i : %i\n", isdigit(5), ft_isdigit(5));
// 	printf("%i : %i\n", isdigit('-'), ft_isdigit('-'));
// 	printf("%i : %i\n", isdigit('5'), ft_isdigit('5'));
// 	return (0);
// }

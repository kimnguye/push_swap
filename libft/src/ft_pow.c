/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:09:34 by kimnguye          #+#    #+#             */
/*   Updated: 2024/05/31 17:52:12 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_pow(int x, unsigned int p)
{
	long	res;

	res = 1;
	while (p > 0)
	{
		if (res * x / res != x)
			return (-1);
		res = res * x;
		p--;
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_binary.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/03 17:59:39 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/02/18 01:09:05 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_binary(unsigned int y)
{
	unsigned int	i;

	i = 1;
	i = i << 31;
	while (i > 0)
	{
		if (y & i)
			ft_printf ("1");
		else
			ft_printf("0");
		i = i / 2;
	}
	ft_printf("\n");
}

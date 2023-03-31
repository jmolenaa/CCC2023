/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_exit_with_error.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 15:36:47 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/02/17 13:59:57 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit_with_error(char *error_message)
{
	ft_putstr_fd(error_message, 2);
	exit(1);
}

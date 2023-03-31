/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 12:23:50 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/01/25 12:20:35 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		diff;
	char	*s1t;
	char	*s2t;

	i = 0;
	diff = 0;
	s1t = (char *)s1;
	s2t = (char *)s2;
	while (diff == 0 && i < n)
	{
		diff = (unsigned char) *(s1t + i) - (unsigned char) *(s2t + i);
		i++;
	}
	return (diff);
}

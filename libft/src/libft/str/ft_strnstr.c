/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 13:18:19 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/01/25 12:22:22 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	e;

	if (*(needle) == '\0')
		return ((char *)haystack);
	i = 0;
	while (i < len)
	{
		if (*(haystack + i) == '\0')
			break ;
		e = 0;
		while (*(haystack + i + e) == *(needle + e))
		{
			if (i + e == len)
				break ;
			if (*(needle + e + 1) == '\0')
				return ((char *)haystack + i);
			e++;
		}
		i++;
	}
	return (NULL);
}

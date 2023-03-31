/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   charconversion.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 09:17:34 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/01/26 11:13:11 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*conversiontochar(va_list ap, t_flags *f)
{
	char	*argstr;
	char	c;

	if (f->width < 1)
		f->width = 1;
	c = va_arg(ap, int);
	argstr = (char *)ft_calloc((f->width + 1), sizeof(char));
	if (!argstr)
		return (NULL);
	ft_memset(argstr, ' ', f->width);
	if (f->minusflag == 1)
		*(argstr) = c;
	else
		*(argstr + f->width - 1) = c;
	return (argstr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   percentconversion.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 20:44:08 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/01/26 11:15:06 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*conversiontopercent(t_flags *f)
{
	char	*argstr;

	if (f->width < 1)
		f->width = 1;
	argstr = (char *)ft_calloc(f->width + 1, sizeof(char));
	if (!argstr)
		return (NULL);
	ft_memset(argstr, ' ', f->width);
	if (f->zeroflag == 1 && f->minusflag == 0)
		ft_memset(argstr, '0', f->width);
	if (f->minusflag == 1)
		*(argstr) = '%';
	else
		*(argstr + f->width - 1) = '%';
	return (argstr);
}

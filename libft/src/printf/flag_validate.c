/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flagvalidate.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 15:43:51 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/01/26 11:14:26 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checkifzeroflagvalid(int i, const char *s, t_flags *f)
{
	if (f->zeroflag == 1)
	{
		if (*(s + i) == 'c' || *(s + i) == 's' || *(s + i) == 'p')
			return (1);
	}
	return (0);
}

int	checkifpoundflagvalid(int i, const char *s, t_flags *f)
{
	if (f->poundflag == 2)
	{	
		if (!(*(s + i) == 'x' || *(s + i) == 'X'))
			return (1);
	}
	return (0);
}

int	checkifspaceandplusflagvalid(int i, const char *s, t_flags *f)
{
	if (f->spaceflag == 1 || f->plusflag == 1)
	{
		if (!(*(s + i) == 'd' || *(s + i) == 'i'))
			return (1);
	}
	return (0);
}

int	checkifprecisionflagvalid(int i, const char *s, t_flags *f)
{
	if (f->prec >= 0)
	{
		if (*(s + i) == 'c' || *(s + i) == 'p')
			return (1);
	}
	return (0);
}

int	validatemultipleflags(t_flags *f)
{
	if (f->zeroflag == 1 && f->minusflag == 1)
		return (1);
	if (f->plusflag == 1 && f->spaceflag == 1)
		return (1);
	return (0);
}

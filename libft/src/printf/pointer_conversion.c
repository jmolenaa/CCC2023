/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pointerconversion.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 10:15:21 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/01/26 11:15:10 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	createstr(char *ptstr, int ptrstrlen, t_flags *f, char *argstr)
{
	if (f->minusflag == 1)
	{
		ft_strlcpy(argstr, "0x", 3);
		ft_strlcpy(argstr + 2, ptstr, ptrstrlen + 1);
		ft_memset(argstr + ptrstrlen + 2, ' ', f->width - ptrstrlen - 2);
	}
	else
	{
		ft_strlcpy(argstr + f->width - ptrstrlen - 2, "0x", 3);
		ft_strlcpy(argstr + f->width - ptrstrlen, ptstr, ptrstrlen + 1);
		ft_memset(argstr, ' ', f->width - ptrstrlen - 2);
	}
}

char	*conversiontopointer(va_list ap, t_flags *f)
{
	char	*argstr;
	void	*p;
	char	*ptstr;
	int		ptrstrlen;

	p = va_arg(ap, void *);
	ptstr = itoabase((size_t)p, "0123456789abcdef", 0);
	if (!ptstr)
		return (NULL);
	ptrstrlen = ft_strlen(ptstr);
	if (f->width < ptrstrlen + 2)
		f->width = ptrstrlen + 2;
	argstr = (char *)ft_calloc(f->width + 1, sizeof(char));
	if (argstr)
		createstr(ptstr, ptrstrlen, f, argstr);
	free(ptstr);
	return (argstr);
}

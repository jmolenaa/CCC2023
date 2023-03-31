/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unsignedconversion.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 08:01:12 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/01/26 11:15:17 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*allocateargstr(t_flags *f, char *unstr)
{
	int	unstrlen;

	unstrlen = ft_strlen(unstr);
	if (unstrlen >= f->width && unstrlen >= f->prec)
		f->width = unstrlen;
	else if (f->prec >= f->width)
		f->width = f->prec;
	return ((char *)ft_calloc(f->width + 1, sizeof(char)));
}

static void	createargstrminusflag(char *unstr, t_flags *f, char *argstr)
{
	int	unstrlen;

	unstrlen = ft_strlen(unstr);
	ft_memset(argstr, ' ', f->width);
	if (f->prec < unstrlen)
	{
		ft_strlcpy(argstr, unstr, unstrlen + 1);
		*(argstr + unstrlen) = ' ';
	}
	else
	{
		ft_strlcpy(argstr + f->prec - unstrlen, unstr, unstrlen + 1);
		ft_memset(argstr, '0', f->prec - unstrlen);
		*(argstr + f->prec) = ' ';
	}
	*(argstr + f->width) = '\0';
}

static void	createargstrnormal(char *unstr, t_flags *f, char *argstr)
{
	int	unstrlen;

	unstrlen = ft_strlen(unstr);
	ft_memset(argstr, ' ', f->width);
	ft_strlcpy(argstr + f->width - unstrlen, unstr, unstrlen + 1);
	if (f->prec >= unstrlen)
		ft_memset(argstr + f->width - f->prec, '0', f->prec - unstrlen);
	else if (f->zeroflag == 1 && f->prec == -1)
		ft_memset(argstr, '0', f->width - unstrlen);
}

char	*conversiontounsigned(va_list ap, t_flags *f)
{
	char			*argstr;
	char			*unstr;
	unsigned int	un;

	un = va_arg(ap, unsigned int);
	unstr = itoabase((size_t)un, "0123456789", 0);
	if (!unstr)
		return (NULL);
	if (un == 0 && f->prec == 0)
		*unstr = '\0';
	argstr = allocateargstr(f, unstr);
	if (argstr)
	{
		if (f->minusflag == 1)
			createargstrminusflag(unstr, f, argstr);
		else
			createargstrnormal(unstr, f, argstr);
	}
	free(unstr);
	return (argstr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hexaconversion.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 11:42:05 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/01/26 11:14:59 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*allocateargst(t_flags *f, char *hexastr)
{
	int	hexslen;

	hexslen = ft_strlen(hexastr) + f->poundflag;
	if (hexslen > f->width && hexslen > f->prec + f->poundflag)
		f->width = hexslen;
	else if (f->prec + f->poundflag > f->width)
		f->width = f->prec + f->poundflag;
	return ((char *)ft_calloc(f->width + 1, sizeof(char)));
}

static void	createargstrminusflag(char *hexastr, t_flags *f, char *argstr)
{
	int	hexslen;
	int	pound;

	pound = f->poundflag;
	hexslen = ft_strlen(hexastr);
	ft_memset(argstr, ' ', f->width);
	if (pound != 0)
		ft_strlcpy(argstr, "0x", 3);
	if (f->prec < hexslen)
	{
		ft_strlcpy(argstr + pound, hexastr, hexslen + 1);
		*(argstr + hexslen + pound) = ' ';
	}
	else
	{
		ft_strlcpy(argstr + f->prec + pound - hexslen, hexastr, hexslen + 1);
		ft_memset(argstr + pound, '0', f->prec - hexslen);
		*(argstr + f->prec + pound) = ' ';
	}
	*(argstr + f->width) = '\0';
}

static void	createargstrnormal(char *hexastr, t_flags *f, char *argstr)
{
	int	hexslen;
	int	pound;

	pound = f->poundflag;
	hexslen = ft_strlen(hexastr);
	ft_memset(argstr, ' ', f->width);
	if (pound != 0)
	{
		if (f->prec >= hexslen)
			ft_strlcpy(argstr + f->width - f->prec - pound, "0x", 3);
		else if (f->zeroflag == 1 && f->prec == -1)
			ft_strlcpy(argstr, "0x", 3);
		else
			ft_strlcpy(argstr + f->width - hexslen - pound, "0x", 3);
	}
	ft_strlcpy(argstr + f->width - hexslen, hexastr, hexslen + 1);
	if (f->prec >= hexslen)
		ft_memset(argstr + f->width - f->prec, '0', f->prec - hexslen);
	else if (f->zeroflag == 1 && f->prec == -1)
		ft_memset(argstr + pound, '0', f->width - hexslen - pound);
}

static void	changetoupper(char c, char *argstr)
{
	int	i;

	i = 0;
	if (c == 'X')
	{
		while (*(argstr + i) != '\0')
		{
			*(argstr + i) = ft_toupper(*(argstr + i));
			i++;
		}
	}
}

char	*conversiontohexa(va_list ap, t_flags *f, char c)
{
	char			*argstr;
	char			*hexastr;
	unsigned int	hexa;

	hexa = va_arg(ap, unsigned int);
	hexastr = itoabase((size_t)hexa, "0123456789abcdef", 0);
	if (!hexastr)
		return (NULL);
	if (hexa == 0 && f->prec == 0)
		*hexastr = '\0';
	if (hexa == 0)
		f->poundflag = 0;
	argstr = allocateargst(f, hexastr);
	if (argstr)
	{
		if (f->minusflag == 1)
			createargstrminusflag(hexastr, f, argstr);
		else
			createargstrnormal(hexastr, f, argstr);
		changetoupper(c, argstr);
	}
	free(hexastr);
	return (argstr);
}

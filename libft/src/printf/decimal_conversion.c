/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   decimalconversion.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 13:35:42 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/01/26 11:13:46 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*makedecstr(int dec, t_flags *f)
{
	char	*decstr;

	if (dec < 0 && dec != INT32_MIN)
		dec = dec * (-1);
	else if (dec == INT32_MIN)
		return (ft_strdup("2147483648"));
	decstr = itoabase((size_t)dec, "0123456789", 0);
	if (!decstr)
		return (NULL);
	if (dec == 0 && f->prec == 0)
		*(decstr) = '\0';
	return (decstr);
}

static char	*allocateargstr(t_flags *f, char *decstr, t_sign *s)
{
	int	decslen;

	decslen = ft_strlen(decstr);
	if (decslen + s->is >= f->width && decslen + s->is > f->prec)
		f->width = decslen + s->is;
	else if (f->prec >= f->width)
		f->width = f->prec + s->is;
	if (f->prec < decslen && f->prec != -1)
		f->prec = decslen;
	return ((char *)ft_calloc(f->width + 1, sizeof(char)));
}

static void	createargsminus(char *decstr, t_sign *s, t_flags *f, char *argstr)
{
	int	decslen;

	decslen = ft_strlen(decstr);
	ft_memset(argstr, '0', f->width);
	if (s->is)
		*argstr = s->sign;
	if (f->prec == -1)
	{
		ft_strlcpy(argstr + s->is, decstr, decslen + 1);
		ft_memset(argstr + decslen + s->is, ' ', f->width - s->is - decslen);
	}
	else
	{
		ft_strlcpy(argstr + s->is + f->prec - decslen, \
		decstr, decslen + 1);
		ft_memset(argstr + s->is + f->prec, ' ', f->width - s->is - f->prec);
	}
}

static void	createargsnormal(char *decstr, t_sign *s, t_flags *f, char *argstr)
{
	int	decslen;

	decslen = ft_strlen(decstr);
	ft_memset(argstr, ' ', f->width);
	if (f->prec != -1)
	{
		ft_memset(argstr + f->width - f->prec, '0', f->prec);
		if (s->is)
			*(argstr + f->width - f->prec - 1) = s->sign;
	}
	else if (f->zeroflag == 1)
	{
		ft_memset(argstr, '0', f->width);
		if (s->is)
			*argstr = s->sign;
	}
	else if (s->is)
		*(argstr + f->width - decslen - s->is) = s->sign;
	ft_strlcpy(argstr + f->width - decslen, decstr, decslen + 1);
}

char	*conversiontodecimal(va_list ap, t_flags *f)
{
	char	*argstr;
	char	*decstr;
	int		dec;
	t_sign	s;

	dec = va_arg(ap, int);
	settingsign(f, dec, &s);
	decstr = makedecstr(dec, f);
	if (!decstr)
		return (NULL);
	argstr = allocateargstr(f, decstr, &s);
	if (argstr)
	{
		if (f->minusflag == 1)
			createargsminus(decstr, &s, f, argstr);
		else
			createargsnormal(decstr, &s, f, argstr);
	}
	free(decstr);
	return (argstr);
}

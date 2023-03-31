/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flagfunctions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 14:05:04 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/01/26 11:14:14 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	setflagsnothing(t_flags *f)
{
	f->minusflag = 0;
	f->zeroflag = 0;
	f->poundflag = 0;
	f->spaceflag = 0;
	f->plusflag = 0;
	f->width = -1;
	f->prec = -1;
}

static int	setwidth(t_flags *f, int i, const char *s)
{
	f->width = 0;
	while (*(s + i) >= '0' && *(s + i) <= '9')
	{
		f->width = f->width * 10 + *(s + i) - 48;
		i++;
	}
	return (i);
}

static int	setprecision(t_flags *f, int i, const char *s)
{
	f->prec = 0;
	if (*(s + i) == 'c' || *(s + i) == 'p')
		f->prec = -2;
	while (*(s + i) >= '0' && *(s + i) <= '9')
	{
		f->prec = f->prec * 10 + *(s + i) - 48;
		i++;
	}
	return (i);
}

int	settingflags(t_string main, t_flags *f, int i, const char *s)
{
	while (ft_strchr(main.flagstr, *(s + i)) && *(s + i) != '\0')
	{
		if (*(s + i) == '0')
			f->zeroflag = 1;
		if (*(s + i) == '-')
			f->minusflag = 1;
		if (*(s + i) == '#')
			f->poundflag = 2;
		if (*(s + i) == ' ')
			f->spaceflag = 1;
		if (*(s + i) == '+')
			f->plusflag = 1;
		i++;
	}
	if (*(s + i) >= '0' && *(s + i) <= '9')
		i = setwidth(f, i, s);
	if (*(s + i) == '.')
		i = setprecision(f, i + 1, s);
	if (ft_strchr(main.converstr, *(s + i)))
		return (i);
	return (0);
}

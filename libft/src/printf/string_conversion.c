/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stringconversion.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 19:18:19 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/01/26 11:15:14 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*allocatememory(char *str, t_flags *f)
{
	int	strlen;

	strlen = ft_strlen(str);
	if (strlen > f->width && (strlen <= f->prec || f->prec == -1))
		f->width = strlen;
	else if (f->prec >= 0 && f->prec < strlen && f->prec >= f->width)
		f->width = f->prec;
	return ((char *)ft_calloc((f->width + 1), sizeof(char)));
}

static void	createstringwithminusflag(char *argstr, t_flags *f, char *str)
{
	int	strlen;

	strlen = ft_strlen(str);
	if (f->prec >= 0 && f->prec < strlen)
	{
		ft_strlcpy(argstr, str, f->prec + 1);
		ft_memset(argstr + f->prec, ' ', f->width - f->prec);
	}
	else
	{
		ft_strlcpy(argstr, str, strlen + 1);
		ft_memset(argstr + strlen, ' ', f->width - strlen);
	}
}

static void	createstringnormal(char *argstr, t_flags *f, char *str)
{
	int	strlen;

	strlen = ft_strlen(str);
	if (f->prec >= 0 && f->prec < strlen)
	{
		ft_strlcpy(argstr + f->width - f->prec, str, f->prec + 1);
		ft_memset(argstr, ' ', f->width - f->prec);
	}
	else
	{
		ft_strlcpy(argstr + f->width - strlen, str, strlen + 1);
		ft_memset(argstr, ' ', f->width - strlen);
	}
}

char	*conversiontostring(va_list ap, t_flags *f)
{
	char	*argstr;
	char	*str;
	int		check;

	check = 0;
	str = va_arg(ap, char *);
	if (str == (NULL))
	{
		str = ft_strdup("(null)");
		if (!str)
			return (NULL);
		check = 1;
	}
	argstr = allocatememory(str, f);
	if (argstr)
	{
		if (f->minusflag == 1)
			createstringwithminusflag(argstr, f, str);
		else
			createstringnormal(argstr, f, str);
	}
	if (check)
		free(str);
	return (argstr);
}

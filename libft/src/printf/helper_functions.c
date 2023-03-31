/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helperfunctions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 14:22:44 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/01/26 11:14:52 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_string	setmainstrings(void)
{
	char		*converstr;
	char		*flagstr;
	t_string	main;

	converstr = "cspdiuxX%";
	flagstr = "-0# +";
	main.converstr = converstr;
	main.flagstr = flagstr;
	return (main);
}

int	looptillpercentsign(const char *s, int i)
{
	while (*(s + i) != '%' && *(s + i) != '\0')
		i++;
	return (i);
}

void	settingsign(t_flags *f, int dec, t_sign *s)
{
	if (dec < 0)
		s->sign = '-';
	else if (f->plusflag == 1)
		s->sign = '+';
	else if (f->spaceflag == 1)
		s->sign = ' ';
	else
		s->sign = '\0';
	if (s->sign != '\0')
		s->is = 1;
	else
		s->is = 0;
}

char	*makeargumentstr(const char *s, int i, va_list ap, t_flags *f)
{
	char	*argstr;

	argstr = (NULL);
	if (*(s + i) == 'c')
		argstr = conversiontochar(ap, f);
	else if (*(s + i) == 's')
		argstr = conversiontostring(ap, f);
	else if (*(s + i) == 'p')
		argstr = conversiontopointer(ap, f);
	else if (*(s + i) == 'd' || *(s + i) == 'i')
		argstr = conversiontodecimal(ap, f);
	else if (*(s + i) == 'u')
		argstr = conversiontounsigned(ap, f);
	else if (*(s + i) == 'x' || *(s + i) == 'X')
		argstr = conversiontohexa(ap, f, *(s + i));
	else if (*(s + i) == '%')
		argstr = conversiontopercent(f);
	return (argstr);
}

char	*itoabase(size_t nbr, char *base, int sign)
{
	int		baselen;
	int		digits;
	size_t	nbrtemp;
	char	*numberstr;

	baselen = ft_strlen(base);
	digits = 1;
	nbrtemp = nbr;
	while (nbrtemp / baselen)
	{
		nbrtemp = nbrtemp / baselen;
		digits++;
	}
	numberstr = (char *)ft_calloc(sign + digits + 1, sizeof(char));
	if (!numberstr)
		return (NULL);
	if (sign == 1)
		*numberstr = '-';
	while (digits)
	{
		digits--;
		*(numberstr + sign + digits) = *(base + (nbr % baselen));
		nbr = nbr / baselen;
	}
	return (numberstr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 07:34:31 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/01/26 11:14:40 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	writestrinbeforepercent(const char *s, int *i)
{
	int		j;
	char	*str;
	int		ret;

	j = *i;
	ret = 0;
	*i = looptillpercentsign(s, *i);
	str = ft_substr(s, j, *i - j);
	if (!str)
		return (-1);
	ret = write(1, str, ft_strlen(str));
	free(str);
	return (ret);
}

static int	writeargumentstring(t_flags *f, const char *s, int *i, va_list ap)
{
	t_string	main;
	char		*argstr;
	int			ret;

	main = setmainstrings();
	setflagsnothing(f);
	(*i)++;
	*i = settingflags(main, f, *i, s);
	argstr = makeargumentstr(s, *i, ap, f);
	if (!argstr)
		return (-1);
	ret = write(1, argstr, f->width);
	free(argstr);
	return (ret);
}

static int	makestr(const char *s, va_list ap, t_flags *f)
{
	int		i;
	int		ret;
	int		retcheck;

	ret = 0;
	i = 0;
	while (*(s + i) != '\0')
	{
		retcheck = writestrinbeforepercent(s, &i);
		if (retcheck == -1)
			return (-1);
		ret = ret + retcheck;
		if (*(s + i) == '\0')
			break ;
		retcheck = writeargumentstring(f, s, &i, ap);
		if (retcheck == -1)
			return (-1);
		ret = ret + retcheck;
		i++;
	}
	return (ret);
}

int	ft_printf(const char *s, ...)
{
	t_string	main;
	va_list		ap;
	t_flags		f;
	int			ret;

	main = setmainstrings();
	if (validateinput(s, main, &f))
		return (-1);
	va_start(ap, s);
	ret = makestr(s, ap, &f);
	va_end(ap);
	return (ret);
}

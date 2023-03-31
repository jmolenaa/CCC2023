/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validation.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 09:12:33 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/01/26 11:15:21 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	validateflagsandconvchar(t_flags *f, int i, const char *s)
{
	if (i == 0 || *(s + i) == '\0')
		return (1);
	if (*(s + i) == '%')
		return (0);
	if (checkifzeroflagvalid(i, s, f))
		return (1);
	if (checkifpoundflagvalid(i, s, f))
		return (1);
	if (checkifspaceandplusflagvalid(i, s, f))
		return (1);
	if (checkifprecisionflagvalid(i, s, f))
		return (1);
	return (validatemultipleflags(f));
}

int	validateinputnormal(char const *s, t_string main)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0')
	{
		i = looptillpercentsign(s, i);
		if (*(s + i) == '\0')
			return (0);
		i++;
		if (ft_strchr(main.converstr, *(s + i)) == NULL || *(s + i) == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	validateinput(char const *s, t_string main, t_flags *f)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0')
	{
		setflagsnothing(f);
		i = looptillpercentsign(s, i);
		if (*(s + i) == '\0')
			return (0);
		i++;
		i = settingflags(main, f, i, s);
		if (validateflagsandconvchar(f, i, s))
			return (1);
		i++;
	}
	return (0);
}

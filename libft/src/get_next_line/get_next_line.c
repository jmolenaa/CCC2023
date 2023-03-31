/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/12 16:36:41 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/01/26 11:30:38 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <limits.h>

char	*createreturnstring(t_line *strlist)
{
	char	*retstr;
	int		totallen;
	int		i;
	t_line	*temp;

	totallen = 0;
	temp = strlist;
	while (temp != (NULL))
	{
		totallen = totallen + strlenornewline(temp->str, 0);
		temp = temp->next;
	}
	retstr = (char *)malloc((totallen + 1) * sizeof(char));
	if (retstr == (NULL))
		return (freeing(strlist, (NULL)), (NULL));
	*(retstr + totallen) = '\0';
	temp = strlist;
	while (temp != (NULL))
	{
		i = strlenornewline(temp->str, 0);
		totallen = totallen - stringcpy(retstr + totallen - i, temp->str, i);
		temp = temp->next;
	}
	freeing(strlist, (NULL));
	return (retstr);
}

t_line	*addnode(t_line *head, char *buff)
{
	t_line	*newnode;

	newnode = (t_line *)malloc(sizeof(t_line));
	if (newnode == (NULL))
	{
		freeing(head, NULL);
		return (NULL);
	}
	newnode->str = substr(buff, 0, 1, 0);
	if (newnode->str == (NULL))
	{
		freeing(head, NULL);
		free(newnode);
		return (NULL);
	}
	newnode->next = head;
	return (newnode);
}

t_line	*nextlinenobuffer(int fd, t_line *strlist, char **strtemp)
{
	int		i;
	int		check;
	char	buff[BUFFER_SIZE + 1];

	i = 1;
	while (i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			return (freeing(strlist, (NULL)));
		*(buff + i) = '\0';
		strlist = addnode(strlist, buff);
		if (strlist == (NULL))
			return (NULL);
		check = strlenornewline(buff, 1);
		if (check < i)
		{
			*strtemp = substr(buff, check + 1, 0, 0);
			if (*strtemp == (NULL))
				return (freeing(strlist, (NULL)));
			return (strlist);
		}
	}
	return (strlist);
}

t_line	*nextlinewithbuffer(char **strtemp, t_line *strlist)
{
	int	strtemplenornewline;

	strtemplenornewline = strlenornewline(*strtemp, 1);
	if (*(*strtemp + strtemplenornewline) == '\n')
	{
		strlist = addnode(strlist, *strtemp);
		if (strlist == (NULL))
			return (freeing(NULL, strtemp));
		*strtemp = substr(*strtemp, strtemplenornewline + 1, 0, 1);
		if (*strtemp == (NULL))
			return (freeing(strlist, (NULL)));
		return (strlist);
	}
	strlist = addnode(strlist, *strtemp);
	freeing(NULL, strtemp);
	return (strlist);
}

char	*get_next_line(int fd)
{
	t_line		*strlist;
	char		*retstr;
	static char	*strtemp[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	strlist = (NULL);
	if (*(strtemp + fd) != (NULL))
	{
		strlist = nextlinewithbuffer(strtemp + fd, strlist);
		if (*(strtemp + fd) == (NULL) && strlist != (NULL))
			strlist = nextlinenobuffer(fd, strlist, strtemp + fd);
	}
	else
		strlist = nextlinenobuffer(fd, strlist, strtemp + fd);
	if (strlist == (NULL))
		return (NULL);
	retstr = createreturnstring(strlist);
	if (retstr == (NULL))
		return (freeing((NULL), strtemp + fd), (NULL));
	if ((*(strtemp + fd) != (NULL) && *(*(strtemp + fd)) == '\0'))
		freeing(NULL, strtemp + fd);
	if (retstr != (NULL) && *retstr == '\0')
		return (free(retstr), (NULL));
	return (retstr);
}

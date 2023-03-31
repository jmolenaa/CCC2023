/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 09:29:59 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/03/09 14:26:32 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdarg.h>

	//Libft

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//functions that identify a character passed as a parameter

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);

//functions that deal with strings without modifying them

int			ft_atoi(const char *str);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);

//functions that deal with strings and modify them

void		ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			ft_tolower(int c);
int			ft_toupper(int c);

//functions that allocate memory

void		*ft_calloc(size_t count, size_t size);
char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);

//functions that deal with memory

void		ft_bzero(void *s, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);

//functions that write to file descriptors

void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);

//functions that deal with lists

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new_node);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new_node);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

	//Get next line

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_line
{
	char			*str;
	struct s_line	*next;
}					t_line;

char		*get_next_line(int fd);
int			strlenornewline(char *str, int newlineornot);
char		*substr(char *str, int start, int newlineornot, int freecheck);
t_line		*freeing(t_line *strlist, char **strtemp);
int			stringcpy(char *dest, char *src, int size);

	//Printf

typedef struct s_string
{
	char	*converstr;
	char	*flagstr;
}			t_string;

typedef struct s_flags
{
	int	minusflag;
	int	zeroflag;
	int	poundflag;
	int	spaceflag;
	int	plusflag;
	int	width;
	int	prec;
}		t_flags;

typedef struct s_sign
{
	int		is;
	char	sign;
}			t_sign;

int			ft_printf(const char *s, ...);
t_string	setmainstrings(void);
int			validateinputnormal(char const *s, t_string main);
int			looptillpercentsign(const char *s, int i);
void		setflagsnothing(t_flags *f);
char		*makeargumentstr(const char *s, int i, va_list ap, t_flags *f);
int			settingflags(t_string main, t_flags *f, int i, const char *s);
void		settingsign(t_flags *f, int dec, t_sign *s);
char		*itoabase(long unsigned int nbr, char *base, int sign);
int			validateinput(char const *s, t_string main, t_flags *f);
int			checkifzeroflagvalid(int i, const char *s, t_flags *f);
int			checkifpoundflagvalid(int i, const char *s, t_flags *f);
int			checkifspaceandplusflagvalid(int i, const char *s, t_flags *f);
int			checkifprecisionflagvalid(int i, const char *s, t_flags *f);
int			validatemultipleflags(t_flags *f);
char		*conversiontochar(va_list ap, t_flags *f);
char		*conversiontostring(va_list ap, t_flags *f);
char		*conversiontopointer(va_list ap, t_flags *f);
char		*conversiontodecimal(va_list ap, t_flags *f);
char		*conversiontounsigned(va_list ap, t_flags *f);
char		*conversiontohexa(va_list ap, t_flags *f, char c);
char		*conversiontopercent(t_flags *f);

//other

void		ft_exit_with_error(char *error_message);

#endif
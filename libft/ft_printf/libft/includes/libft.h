/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 12:36:05 by jlasne            #+#    #+#             */
/*   Updated: 2016/12/19 18:02:08 by estephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define _ERROR_	0x00
# define _SUCCESS_	0x01

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}				t_list;

void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strlen(const char *str);
int				ft_strwlen(int *str);
char			*ft_strdup(const char *s);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strcat(char *s1, char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int n);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
int				ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_strclr(char *s);
void			*ft_memalloc(size_t size);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_memdel(void **ap);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
char			**ft_split_whitespaces(char *str);
int				ft_power(int nb, int pow);
int				ft_cat(int argc, char **argv);
int				ft_strisdigit(char *str);
unsigned int	ft_atoi_base(const char *str, int base);
unsigned int	ft_atoi_nbase(const char *str, int base, int len);
char			*ft_itoa_base(unsigned int n, int base);
char			*ft_itoa_base_l(unsigned long int n, int base);
char			*ft_itoa_base_ll(unsigned long long int n, int base);
char			*ft_itoa_base_uint(uintmax_t n, int base);
int				ft_nblen(int n);
int				ft_nblen_l(long n);
int				ft_nblen_ll(long long n);
void			ft_putnbr_l(long n);
void			ft_putnbr_ll(long long n);
int				ft_strisdigit(char *str);
int				ft_charwlen(int c);
int				ft_binlen(unsigned int n);
int				ft_putnwstr(int *str, int len);
int				ft_putnwchar(int c, int size);
int				ft_putwchar(int c);
int				ft_putnstr(const char *str, int n);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_libft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:43:17 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/23 17:43:21 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIG_LIBFT_H
# define BIG_LIBFT_H

/* Standard headers */
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <fcntl.h>

/* ======================== */
/*         LIBFT            */
/* ======================== */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *pointer, int value, size_t count);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t destsize);
size_t	ft_strlcat(char *d, const char *s, size_t destsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, int chr);
char	*ft_strrchr(const char *str, int chr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *mem_block, int chr, size_t size);
int		ft_memcmp(const void *ptr_1, const void *ptr_2, size_t size);
char	*ft_strnstr(const char *largestr, const char *smallstr, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t element_count, size_t size);
char	*ft_strdup(char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* ======================== */
/*       FT_PRINTF          */
/* ======================== */
int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *i);
void	ft_putstr(char *str, int *i);
void	ft_print_adress(unsigned long long ptr, int *i);
void	ft_putnbr(int n, int *i);
void	ft_putnbr_unsigned(unsigned int n, int *i);
void	ft_putnbr_base(unsigned int nbr, char *base, int *i);

/* ======================== */
/*     GET_NEXT_LINE        */
/* ======================== */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 21
# endif

char	*get_next_line(int fd);

#endif

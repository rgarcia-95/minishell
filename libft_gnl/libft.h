/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 18:14:48 by rgarcia-          #+#    #+#             */
/*   Updated: 2021/02/16 12:06:55 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define BUFFER_SIZE 4096

typedef struct	s_split3
{
	int				i;
	int				aux;
	int				flag_cs;
	int				flag_cd;
}				t_split3;

typedef struct	s_split2_1
{
	int				i;
	int				aux;
	int				flag_cs;
	int				flag_cd;
}				t_split2_1;

typedef struct	s_split2_2
{
	int				i;
	int				num_w;
}				t_split2_2;

size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strnstr(const char *haystack, const char *needle,
				size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				get_next_line(int fd, char **line);
char			**ft_split3(char const *s);
void			ft_init_split3(t_split3 *t);
void			ft_write_ms(int i, char c);
char			**ft_split_2(char const *s);
void			ft_init_split2_1(t_split2_1 *t);
void			ft_init_split2_2(t_split2_2 *t, char const *s);
int				ft_num_w_split_2(char const *s, char c);
size_t			ft_strlcpy_split_2(char *dst, const char *src, size_t dstsize);
char			*ft_aux_malloc(char const *s, char *str, int i);
char			**ft_aux_split_2(char **str, char const *s, t_split2_2 *t);
char			*ft_malloc_split_2(char const *s, char c, int i);

#endif

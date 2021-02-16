/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:03:42 by javrodri          #+#    #+#             */
/*   Updated: 2021/02/16 12:34:37 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <signal.h>
# include <errno.h>
# include <fcntl.h>
# include "libft_gnl/libft.h"

# define PROMPT "\033[1;92m>>> "
# define READ_END 0
# define WRITE_END 1

typedef struct	s_node
{
	char			*content;
	struct s_node	*next;
	int				l_pipe;
	int				r_pipe;
	int				l_red_min;
	int				r_red_min;
	int				l_red_may;
	int				r_red_may;
	int				l_red_maymay;
	int				r_red_maymay;
}				t_node;

typedef struct	s_list_ms
{
	t_node			*first;
	int				size;
}				t_list_ms;

typedef struct	s_minishell
{
	int				i;
	int				status;
	char			*line;
	char			**env;
	char			**path;
	char			*home;
	char			**aux_args;
	char			*aux;
	char			*aux_path;
	char			**commands;
	char			*content;
	char			flags[8];
	char			*pwd;
	char			*cwd;
	char			*old_pwd;
	char			*old_cwd;
	char			*dolar;
	int				fd[2];
	int				save[2];
	int				dollar_z;
	t_node			*it;
}				t_minishell;

int				ft_get_path(t_minishell *s);
void			ft_show_prompt(t_minishell *s);
t_list_ms		*ft_fill_lists(char *str, t_minishell *s);
void			ft_check_flags(int i, int j, char *str, t_minishell *s);
void			ft_parse_commands(t_list_ms *list, t_minishell *s);
void			ft_free_lists(t_list_ms *list);
void			ft_free_matrix(char **matrix);
int				ft_pwd(t_minishell *s);
void			ft_cd(t_minishell *s);
int				ft_export(t_minishell *s, int z);
int				ft_unset(t_minishell *s, int z);
int				ft_find_string(char *s1, char *s2, t_minishell *s, int j);
void			ft_echo(t_minishell *s, int i, int flag);
void			ft_exit(t_minishell *s, int j);
void			ft_pipes(t_minishell *s);
void			ft_cases(t_minishell *s);
void			ft_init_pipes(t_minishell *s);
void			ft_reset_pipes(t_minishell *s);
void			ft_redir_mayor(t_minishell *s, char *str);
void			ft_redir_minor(t_minishell *s);
void			ft_redir_mayor_mayor(t_minishell *s, char *str);
void			ft_signal_c(int sign);
void			ft_signal_c1(int sign);
void			ft_signal_quit(int sign);
void			ft_signal_d(int sign);
void			ft_not_found(t_minishell *s);
void			ft_aux_commands(t_minishell *s, int i, int j);

#endif

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/08 18:39:10 by javrodri          #+#    #+#              #
#    Updated: 2021/02/02 18:25:12 by rgarcia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

SRCS	=	minishell.c					\
			ft_fill_lists.c				\
			ft_check_flags.c			\
			ft_parse_commands.c			\
			ft_free_lists.c				\
			ft_free_matrix.c			\
			ft_pwd.c					\
			ft_cd.c						\
			ft_export.c					\
			ft_unset.c					\
			ft_echo.c					\
			ft_exit.c					\
			ft_pipes.c					\
			ft_pipes_aux.c				\
			ft_redir.c					\
			ft_signals.c				\
			ft_aux_commands.c			\

LIBFT	=	libft_gnl/libft.a

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	$(OBJS)
		@$(MAKE) -C libft_gnl/
		@gcc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean	:
		@/bin/rm -f $(OBJS)
		@$(MAKE) clean -C libft_gnl/

fclean	:	clean
		@/bin/rm -f $(NAME)
		@$(MAKE) fclean -C libft_gnl/

re		:	fclean all

.PHONY	:	all clean fclean re
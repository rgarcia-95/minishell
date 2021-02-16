# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/09 17:07:17 by rgarcia-          #+#    #+#              #
#    Updated: 2021/02/16 11:38:10 by rgarcia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

HEADER	=	libft.h

SRCS	=	ft_strlen.c					\
			ft_strlcpy.c				\
			ft_strchr.c					\
			ft_strnstr.c				\
			ft_strncmp.c				\
			ft_atoi.c					\
			ft_isdigit.c				\
			ft_strdup.c					\
			ft_substr.c					\
			ft_strjoin.c				\
			ft_split.c					\
			ft_itoa.c					\
			ft_putstr_fd.c				\
			ft_putnbr_fd.c				\
			get_next_line.c				\
			ft_split_2.c				\
			ft_split2_aux.c				\
			ft_split_3.c				\
			ft_aux.c					\

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
		@ar -rcs $(NAME) $(OBJS)

%.o:%.c	$(HEADER)
		@gcc -Wall -Wextra -Werror -o $@ -c $< -I $(HEADER)

clean	:
		@/bin/rm -f $(OBJS)

fclean	:	clean
		@/bin/rm -f $(NAME)

re		:	fclean all
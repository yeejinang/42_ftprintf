# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yang <yang@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 11:38:54 by yang              #+#    #+#              #
#    Updated: 2021/07/02 11:40:02 by yang             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= libftprintf.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -I.

SRCS		= ft_eval_args.c ft_eval_pdiuxX.c ft_eval_utils.c \
				ft_solve_c.c ft_solve_pdiuxX.c ft_solve_s.c ft_printf.c

OBJS		= $(SRCS:.c=.o)

LIBFTDIR	= ../../libft

LIBFT		= libft.a

BONUS		= ft_eval_args.c ft_eval_pdiuxX.c ft_eval_utils.c \
				ft_solve_c.c ft_solve_pdiuxX.c ft_solve_s.c ft_printf.c

BONUS_OBJS	= $(BONUS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			cp  $(LIBFTDIR)/$(LIBFT) $(NAME)
			ar rcs $(NAME) $(OBJS)

bonus:		$(OBJS) $(BONUS_OBJS)
			ar rcs $(NAME) $(OBJS) $(BONUS_OBJS) 

clean:
			rm -f *.o

fclean:		clean
			rm -f $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re bonus

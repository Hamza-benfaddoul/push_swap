# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 10:32:44 by hbenfadd          #+#    #+#              #
#    Updated: 2023/01/17 23:14:04 by hbenfadd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc 
CFLAGS = -g -Wall -Wextra -Werror -I$(DIRINC)
CLIB = -L$(FTDIR) -lft
DIRINC = ./srcs/inc 
FTDIR = ./libft
LIBFT = ./libft/libft.a

RULE_FUN = push_tostack.c \
		reverse_rstacks.c \
		reverse_rstack.c \
		rotate_stacks.c \
		swap_topstack.c \
		swap_topstacks.c \
		rotate_stack.c

Help_fun = add_toArry.c \
		ft_lis.c \
		push_tob.c \
		get_bestmove.c \
		make_themove.c \
		positive_move.c \
		negative_move.c \
		get_abs.c \
		mix_move.c \
		get_bigone.c \
		check_error.c \
		addnbr_to_stack.c \
		get_smallone.c

SRCS = $(addprefix ./srcs/, push_swap.c) \
	   $(addprefix ./srcs/Help-functions/, $(Help_fun)) \
	   $(addprefix ./srcs/rule-function/, $(RULE_FUN)) \
	   main.c

BONUS_FUN = main.c \
	    ft_checker.c \
	    isstack_sorted.c

GET_NEXT_LINE = get_next_line.c \
				get_next_line_utils.c

BONUSSRCS = $(addprefix ./srcs/bonus/, $(BONUS_FUN)) \
			$(addprefix ./get_nextline/, $(GET_NEXT_LINE)) \
			$(addprefix ./srcs/Help-functions/, $(Help_fun)) \
			$(addprefix ./srcs/rule-function/, $(RULE_FUN))

OBJS = $(SRCS:.c=.o)
BONUSOBJS = $(BONUSSRCS:.c=.o)

all : $(NAME)
bonus : $(BONUSOBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUSOBJS) $(CLIB) -o checker

$(NAME) : $(LIBFT) $(OBJS)
	$(CC)  $(CFLAGS) $(OBJS) $(CLIB) -o $(NAME) 

$(LIBFT) :
	make all bonus -C ./libft
clean :
	rm -f $(OBJS) $(BONUSOBJS)
	make clean -C ./libft
fclean : clean
	rm -f $(NAME) checker
	make fclean -C ./libft
re : fclean all

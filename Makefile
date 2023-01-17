# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 10:32:44 by hbenfadd          #+#    #+#              #
#    Updated: 2023/01/17 08:53:51 by hbenfadd         ###   ########.fr        #
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

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC)  $(CFLAGS) $(OBJS) $(CLIB) -o $(NAME) 
$(LIBFT) :
	make all bonus -C ./libft
clean :
	rm -f $(OBJS)
	make clean -C ./libft
fclean : clean
	rm -f $(NAME) 
	make fclean -C ./libft
re : fclean all

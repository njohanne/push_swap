# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njohanne <njohanne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/27 17:14:23 by njohanne          #+#    #+#              #
#    Updated: 2022/05/26 17:35:55 by njohanne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

BONUS_NAME = cheker

SRC		=	push_swap.c \
			utils/ft_error.c \
			utils/ft_isdigit.c \
			utils/ft_pars_atoi.c \
			utils/ft_sorted_ready.c \
			utils/ft_find_min.c \
			utils/ft_putstr.c \
			utils/ft_parser_str.c \
			utils/ft_strlen.c \
			utils/ft_strdup.c \
			utils/ft_split.c \
			utils/ft_strjoin.c \
			operation/ft_pa_pb.c \
			operation/ft_ra_rb_rr.c \
			operation/ft_rra_rrb_rrr.c \
			operation/ft_sa_sb_ss.c \
			sort/ft_minisort.c \
			sort/ft_full_sort.c 
			
BONUS_SRC =	bonus/push_swap_bonus.c \
			bonus/ft_parse.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			utils/ft_error.c \
			utils/ft_isdigit.c \
			utils/ft_pars_atoi.c \
			utils/ft_sorted_ready.c \
			utils/ft_find_min.c \
			utils/ft_putstr.c \
			utils/ft_parser_str.c \
			utils/ft_strlen.c \
			utils/ft_strdup.c \
			utils/ft_split.c \
			utils/ft_strjoin.c \
			operation/ft_pa_pb.c \
			operation/ft_ra_rb_rr.c \
			operation/ft_rra_rrb_rrr.c \
			operation/ft_sa_sb_ss.c \
			sort/ft_minisort.c \
			sort/ft_full_sort.c 		

OBJ		=	$(SRC:.c=.o)

BONUS_OBJ	=	$(BONUS_SRC:.c=.o)

CC		=	cc

FLAGS	=	-Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

bonus : $(BONUS_OBJ)
	$(CC) $(FLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)

clean:
			rm -f $(OBJ) $(BONUS_OBJ)

fclean:	clean
			rm -f $(NAME) $(BONUS_NAME)

re:			fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 17:39:08 by ehaggon           #+#    #+#              #
#    Updated: 2019/10/24 20:32:49 by ehaggon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_printf_init.c ft_add_new_param.c ft_atoi.c  \
ft_free_buf.c ft_memset.c ft_percent_main.c ft_colour_main.c \
ft_strnew.c ft_print_result.c param_fill/ft_get_flags.c \
param_fill/ft_get_length.c param_fill/ft_get_prec.c \
param_fill/ft_get_width.c param_fill/ft_param_fill.c \
types/ft_type_c_up.c types/ft_type_c.c \
types/ft_type_d_up.c types/ft_type_d/ft_type_d.c \
types/ft_type_f_up.c types/ft_type_f.c \
types/ft_type_o_up.c types/ft_type_o.c \
types/ft_type_percent.c \
types/ft_type_s_up.c types/ft_type_s.c \
types/ft_type_u_up.c types/ft_type_u.c \
types/ft_type_x_up.c types/ft_type_x.c \
ft_itoa_base.c ft_itoa.c \
ft_num_dig.c types/ft_type_d/ft_print_d.c ft_strlen.c\
types/ft_type_d/check_utils_d.c ft_memnew.c ft_putchar.c \
ft_itoa_base_ll.c \
types/ft_type_p/ft_type_p.c \

OBJ = $(SRC:.c=.o)

INC = ./inc

CC = gcc
FLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: src/%.c
	@$(CC) $(FLAGS) -I $(INC) -o $@ -c $<

all : $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

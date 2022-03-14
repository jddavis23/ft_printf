# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdavis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 16:19:40 by jdavis            #+#    #+#              #
#    Updated: 2022/03/14 16:38:02 by jdavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDES = libft/

CC = gcc -Wall -Wextra -Werror -I libft/

SRC = solve_c_s.c
SRC += ft_printf.c
SRC += flags_plus.c
SRC += char_digit.c
SRC += solve_x_o.c
SRC += num_to_ascii.c
SRC += solve_d_i.c
SRC += solve_u.c
SRC += solve_p.c
SRC += solve_f.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@$(CC) -c -I ./includes $(SRC)
	@ar rc $(NAME) $(OBJ) libft/*.o
	ranlib $(NAME)

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all re clean fclean

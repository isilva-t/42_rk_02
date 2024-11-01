# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 09:55:09 by isilva-t          #+#    #+#              #
#    Updated: 2024/07/06 11:04:02 by isilva-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c \
	   	proj/com_rotate.c \
	   	proj/com_rev_rotate.c \
	   	proj/com_push.c \
	   	proj/com_swap.c \
	   		proj/free_error.c \
	   			proj/order_big_stack.c \
	   			proj/order_small_stack.c \
	   				proj/stack_index.c \
	   				proj/stack_init.c \
	   				proj/stack_utils.c \
		utils/libft/ft_split.c \
		utils/libft/ft_strlen.c \
		utils//libft/ft_substr.c \
		utils/libft/ft_strdup.c \
		utils/libft/ft_lstsize.c \
		utils/libft/ft_isdigit.c \
		utils/libft/ft_lstlast.c \
			utils/ft_printf/ft_printf.c \
			utils/ft_printf/pf_print_ptr.c \
			utils/ft_printf/pf_put_nbr_base.c 
#		test/print_section.c
#		MY TEST ONLY: UNCOMMENT LINE ABOVE TO USE PRINT FUNCTION.
#		UNCOMENT IN push_swap.h TOO

OBJS = ${SRCS:.c=.o}

NAME = push_swap

MSG1 = @echo "________ Compiled Mandatory files!"
MSG2 = @echo "________ Compiled Bonus files!"
MSG3 = @echo "___________ Cleared!"
MSG4 = @echo "_______________ Full Cleared!"

$(NAME):
	$(CC) ${CFLAGS} $(SRCS) -o $(NAME)
	${MSG1}
	
all: ${NAME}

clean:
	@rm -rf ${OBJS}
	${MSG3}

fclean: clean
	@rm -rf ${NAME}
	${MSG4}

re: fclean all

.PHONY: all clean fclean re

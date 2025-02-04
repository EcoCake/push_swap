# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 19:37:03 by amezoe            #+#    #+#              #
#    Updated: 2025/02/04 10:37:13 by amezoe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS		= 	ft_printf.c ft_basic_funcs.c ft_hexadecimal.c \
				ft_pointers.c ft_unsigned.c
LIBFTDIR	= 	../libft/

LIBFT		= 	$(LIBFTDIR)libft.a
OBJS		= 	$(SRCS:.c=.o)

CC			= 	cc
RM			= 	@rm -rf
CCFLAGS		= 	-Wall -Werror -Wextra -I.

NAME		= 	libftprintf.a

%.o:			%.c
				@$(CC) $(CCFLAGS) -c $< -o $@

all:			$(NAME)
				
$(NAME):		$(OBJS)
				@make -sC ${LIBFTDIR}
				@ar rcs $(NAME) $(LIBFT) $(OBJS)

clean:
				$(RM) $(OBJS)
				@make --no-print-directory -C $(LIBFTDIR) clean

fclean:			clean
				$(RM) $(NAME)
				@make --no-print-directory -C $(LIBFTDIR) fclean

re:				fclean all

.PHONY:			all clean fclean re
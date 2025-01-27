# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 19:37:03 by amezoe            #+#    #+#              #
#    Updated: 2024/12/06 16:52:13 by amezoe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

LIBFT			= ./libft/libft.a
LIBFTDIR		= ./libft

SRC_DIR			= ./files
SRC_FILES		= ft_hexadecimal.c ft_pointers.c ft_unsigned.c ft_basic_funcs.c ft_printf.c
SRCS			= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJS			= $(SRCS:.c=.o)

CC				= cc
AR				= ar rcs
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror
CP				= cp

all:			$(NAME)

$(NAME): 		$(LIBFT) $(OBJS)
				$(CP) $(LIBFT) $(NAME)
				$(AR) $(NAME) $(OBJS)

$(LIBFT): 		$(LIBFTDIR)
				@$(MAKE) -C $(LIBFTDIR)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				@$(MAKE) clean -C $(LIBFTDIR)
				$(RM) $(OBJS)

fclean:			clean
				@$(MAKE) fclean -C $(LIBFTDIR)
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
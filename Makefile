SRCSDIR		=	src
SRCS		=	$(SRCSDIR)/find_min_max.c $(SRCSDIR)/parse.c $(SRCSDIR)/helper_utils.c \
                $(SRCSDIR)/list_utils.c $(SRCSDIR)/push_swap.c $(SRCSDIR)/swap_funcs.c \
                $(SRCSDIR)/rotate_funcs.c 

LIBFTDIR	=	include/libft
PRINTFDIR	=	include/printf

LIBFT		=	$(LIBFTDIR)/libft.a
PRINTF		=	$(PRINTFDIR)/libftprintf.a

OBJS		=	$(SRCS:.c=.o)

CC			=	@cc
RM			=	@rm -f
CCFLAGS		=	-Wall -Werror -Wextra

BLUE		=	\033[0;94m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
CYAN		=	\033[0;96m
COLOR		=	\033[0m

CLEAR		=	\033c

SUCCESS		=	@echo "$(GREEN)success !! o(≧▽≦)o$(COLOR)"
S_OBJS		=	@echo "$(BLUE)cleaning of objects completed <(￣︶￣)>$(COLOR)"
S_NAME		=	@echo "$(CYAN)full clean completed ! ヽ(・∀・)ﾉ$(COLOR)"

NAME		=	push_swap

%.o:		%.c
			$(CC) $(CCFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -sC $(LIBFTDIR)
			@make -sC $(PRINTFDIR)
			@$(CC) $(CCFLAGS) $(OBJS) ${LIBFT} ${PRINTF} -o $(NAME)
			$(SUCCESS)

clean:
			$(RM) $(OBJS)
			@make --no-print-directory -sC $(PRINTFDIR) clean
			$(S_OBJS)

fclean:		clean
			$(RM) $(NAME)
			@make --no-print-directory -sC $(PRINTFDIR) fclean
			$(S_NAME)

re:			fclean all

.PHONY:		all clean fclean re
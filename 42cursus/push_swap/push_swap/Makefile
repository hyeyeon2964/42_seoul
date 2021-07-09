SRCS_PS =	./push_swap_srcs/push_swap.c \
			./push_swap_srcs/call_function.c \
			./push_swap_srcs/quick_sort.c \
			./push_swap_srcs/handle_operation_list.c \
			./push_swap_srcs/operation_function.c \
			./push_swap_srcs/optimize.c \

SRCS_CH =	./checker_srcs/checker.c \
			./checker_srcs/get_next_line.c \
			./checker_srcs/get_next_line_utils.c \

SRCS_CM =	./common_srcs/p_function.c \
			./common_srcs/r_function.c \
			./common_srcs/s_function.c \
			./common_srcs/rr_function.c \
			./common_srcs/error_check_before.c \
			./common_srcs/error_check_after.c \
			./common_srcs/ft_atoi.c \
			./common_srcs/ft_strdup.c \
			./common_srcs/handle_free.c \
			./common_srcs/sort_function.c \
			./common_srcs/sort_check.c \
			./common_srcs/lst_function.c \
			./common_srcs/find_minmax.c \
			./common_srcs/find_pivot.c \
			./common_srcs/init_stack.c \

NAME_PS = push_swap
NAME_CH = checker
OBJS_PS = $(SRCS_PS:.c=.o)
OBJS_CH = $(SRCS_CH:.c=.o)
OBJS_CM = $(SRCS_CM:.c=.o)
INCS = .
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

all : $(NAME_PS) $(NAME_CH)

$(NAME_PS) : $(OBJS_PS) $(OBJS_CM)
		$(CC) $(CFLAGS) -o $(NAME_PS) $(OBJS_PS) $(OBJS_CM) -I $(INCS)

$(NAME_CH) : $(OBJS_CH) $(OBJS_CM)
		$(CC) $(CFLAGS) -o $(NAME_CH) $(OBJS_CH) $(OBJS_CM) -I $(INCS)

clean :
		$(RM) $(OBJS_PS) $(OBJS_CH) $(OBJS_CM)

fclean : clean
		$(RM) $(NAME_PS) $(NAME_CH)

re : fclean all

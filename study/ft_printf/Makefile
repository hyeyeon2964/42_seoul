SRCS	= ./ft_printf.c \
          ./ft_utils.c \
          ./ft_utils2.c \
          ./option_check.c \
          ./print_number.c \
          ./print_p.c \
          ./print_result.c \
          ./print_string.c \
          ./print_x.c \

NAME	= libftprintf.a
OBJS	= $(SRCS:.c=.o)
INCS	= .
RM		= rm -f
LIBC	= ar rc
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all




NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c  ft_printf_helpers.c

SRCB = bonus/ft_printf_bonus.c bonus/ft_printf_utils_bonus.c  bonus/ft_printf_helpers_bonus.c bonus/libft_bonus.c

CC = cc

CFLAGS = -c -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

OBJB = $(SRCB:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	ar -r $(NAME) $(OBJS)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

$(OBJB) : $(SRCB)
	$(CC) $(CFLAGS) -c $(SRCB)

bonus : $(OBJB) 
	rm -rf $(NAME)
	ar -r $(NAME) $(OBJB) 

clean :
	rm -rf *.o
	rm -rf $(OBJS)  $(OBJB)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: fclean clean all re bonus
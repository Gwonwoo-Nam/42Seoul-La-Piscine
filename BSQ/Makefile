CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCDIR = srcs
INCDIR = includes

SRCS = $(SRCDIR)/main.c $(SRCDIR)/find_max.c $(SRCDIR)/read_file.c $(SRCDIR)/get_info.c $(SRCDIR)/sub_fun.c
OBJS = $(SRCS:.c=.o)

NAME = bsq

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@ -I $(INCDIR)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all 

.PHONY : all clean fclean re

NAME = philo

SRCS = philo.c tool.c init_input.c init_philo.c

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)

DEL = rm -rf

%o: %c 
	@$(CC) $(CFLAG) -c $< -o $@ 

all: $(NAME)
	
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@$(DEL) $(OBJS)

fclean: clean
	@$(DEL) $(NAME)

re: fclean all

norm:
	@echo "---- NORMINETTE ----"
	@norminette -R CheckDefine *.h
	@norminette -R CheckForbiddenSourceHeader *.c
	@norminette -R CheckDefine checker_bo/*.h
	@norminette -R CheckForbiddenSourceHeader checker_bo/*.c
	@echo "---- THANK YOU ^w^Y ----"

.PHONY: norm clean fclean all re
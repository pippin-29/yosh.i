NAME			:= yosh.i

LIBFT_A			:= libft/libft.a
INCLUDES_PATH	:= -I/usr/local/Cellar/readline/8.1.2/include
LINK_PATH		:= -L/usr/local/Cellar/readline/8.1.2/lib
LINK_LIB		:= -lreadline
FLAGS			:= -Wextra -Werror -Wall
ADDSAN			:= -g -fsanitize=address
SOURCE			:= source/*.c

COMPILE = gcc -o $(NAME) $(FLAGS) $(SOURCE) $(LIBFT_A) $(INCLUDES_PATH) $(LINK_PATH) $(LINK_LIB)
all:
			$(X86) $(COMPILE) $(ADDSAN)

run: all
			./$(NAME)
clean:
			
fclean: clean
			rm -rf $(NAME)

re: fclean all

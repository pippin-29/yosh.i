NAME 	:= yosh.i

LIBFT_A := libft/libft.a
LIBFT 	:= libft/

LINKL	:= -lreadline
X86   	:= arch -x86_64
FLAGS	:= -Wextra -Werror -Wall
ADDSAN  := -g -fsanitize=address
SOURCE 	:= source/*.c

COMPILE = gcc $(FLAGS) $(SOURCE) $(LINKL) $(LIBFT_A) -o $(NAME)

all:
			$(X86) $(COMPILE) $(ADDSAN)

run: all
			./$(NAME)
clean:
			
fclean: clean
			rm -rf $(NAME)

re: fclean all

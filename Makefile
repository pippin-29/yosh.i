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
			$(X86) make -C $(LIBFT)
			$(X86) $(COMPILE) $(ADDSAN)

clean:
			make clean -C $(LIBFT)

fclean:
			make fclean -C $(LIBFT)
			rm -rf $(NAME)

re: fclean all

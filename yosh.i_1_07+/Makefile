NAME			:= yosh.i

LIBFT			:= libft/
LIBFT_A			:= libft/libft.a
INCLUDES_PATH	:= -I/opt/homebrew/opt/readline/include
LINK_PATH		:= -L/opt/homebrew/opt/readline/lib
INCLUDES_PATH	+= -I/usr/local/Cellar/readline/8.1.2/include
LINK_PATH		+= -L/usr/local/Cellar/readline/8.1.2/lib
LINK_LIB		:= -lreadline
FLAGS			:= -Wextra -Werror -Wall
ADDSAN			:= -g -fsanitize=address
SOURCE			:= 	source/builtin1.c \
					source/builtin2.c \
					source/env.c \
					source/expander_norm.c \
					source/expander.c \
					source/free.c \
					source/history.c \
					source/io.c \
					source/main.c \
					source/op.c \
					source/parse.c \
					source/pipe-io.c \
					source/print.c \
					source/prompt.c \
					source/quotes.c \
					source/redirection.c \
					source/run.c \
					source/setup.c \
					source/signal.c

all:
			echo COMPILING... PLEASE STAND BY.
			
			gcc -o $(NAME) $(FLAGS) $(SOURCE) $(LIBFT_A) $(INCLUDES_PATH) $(LINK_PATH) $(LINK_LIB) 
			
run: all
			./$(NAME)
clean:
			
fclean: clean
			rm -rf $(NAME)

re: fclean all

.SILENT:

# NOTES

# All command invocation has been silenced.
# libft is recompiled to facilitate movement between x86_64 intel and M1 Apple

# make clean -C $(LIBFT)
# make -C $(LIBFT)

# $(ADDSAN)
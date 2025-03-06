NAME = push_swap
CC = @clang
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LIBFT_FLAGS = -L./libft_plus -lft_plus
LIBFT_DIR = ./libft_plus
LIBFT_LIB = $(LIBFT_DIR)/libft_plus.a
RM = @rm -rf

FILES = ps_execute \
		ps_initialize \
		ps_operations \
		ps_phase_one \
		ps_phase_two \
		ps_utilities \
		push_swap \

SRCS_DIR = ./src/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./obj/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(SRCS_DIR)push_swap.h $(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAGS)
	@echo "push_swap compiled"

$(LIBFT_LIB):
	@make -s -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS) $(NAME) $(OBJS_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)

re: clean $(NAME)

fre: fclean $(NAME)

.PHONY: all clean fclean re fre

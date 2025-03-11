NAME := push_swap

CC := @gcc
CFLAGS := -Werror -Wall -Wextra -g
RM := @rm -rf

FILES := ps_exec \
		ps_init \
		ps_operations_1 \
		ps_operations_2 \
		ps_operations_3 \
		ps_phase_one \
		ps_phase_two \
		ps_utils \
		push_swap

HDRS := ./push_swap.h

SRCS_DIR := ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR := ./obj/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(HDRS) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: clean $(NAME)

fre: fclean $(NAME)

.PHONY: all clean fclean re fre

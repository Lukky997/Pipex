CC = cc -g
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
LIBFT_DIR = BIG_LIBFT
LIBFT = $(LIBFT_DIR)/lib/libbiglibft.a
INCLUDE_LIBFT = $(LIBFT_DIR)/includes
INCLUDE = includes

PATH_SRCS = src
HEADER = $(INCLUDE)/pipex.h

SRCS = \
	$(PATH_SRCS)/pipex.c \
	$(PATH_SRCS)/pipex_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -I$(INCLUDE) -I$(INCLUDE_LIBFT) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I$(INCLUDE) -I$(INCLUDE_LIBFT) -L$(LIBFT_DIR)/lib -lbiglibft
	@echo "pipex compilation done."

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory
	@echo "BIG LIBFT compilation done."

clean:
	@rm -rf $(OBJS)
	@make -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re

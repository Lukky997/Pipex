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

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[1;90m
RED = \033[1;91m
GREEN = \033[1;92m
YELLOW = \033[1;93m
BLUE = \033[1;94m
MAGENTA = \033[1;95m
CYAN = \033[1;96m
WHITE = \033[1;97m

loading_bar:
	@i=0; \
	spin='⠋⠙⠹⠸⠼⠴⠦⠧⠇⠏'; \
	len=$$(expr length "$$spin"); \
	while [ $$i -le 20 ]; do \
		pos=$$(( (i % len) + 1 )); \
		char=$$(expr substr "$$spin" $$pos 1); \
		bar="$$(printf '%0.s▓' $$(seq 1 $$i))"; \
		printf "\r\033[1;96m[%-20s] %3d%% %s\033[0m" "$$bar" $$(( $$i * 5 )) "$$char"; \
		sleep 0.05; \
		i=$$((i+1)); \
	done; \
	printf "\r$(MAGENTA)✅ PIPEX COMPILATION DONE$(DEF_COLOR)%-20s\n" "" 

all: $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -I$(INCLUDE) -I$(INCLUDE_LIBFT) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I$(INCLUDE) -I$(INCLUDE_LIBFT) -L$(LIBFT_DIR)/lib -lbiglibft
	@$(MAKE) --no-print-directory loading_bar

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory
	@echo "\033[1m$(GREEN)✅ LIBFT COMPILATION DONE$(DEF_COLOR)"

clean:
	@rm -rf $(OBJS)
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@echo "\033[1m$(YELLOW)🧹 Cleaned object files$(DEF_COLOR)"

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "\033[1m$(RED)🧨 Removed $(NAME)$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re

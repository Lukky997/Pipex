# **************************************************************************** #
#                                  BIG LIBFT                                  #
# **************************************************************************** #

NAME		= lib/libbiglibft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f
INCLUDES	= -Iincludes

# Source files
SRCS = \
	srcs/libc/ft_atoi.c \
	srcs/libc/ft_bzero.c \
	srcs/libc/ft_calloc.c \
	srcs/libc/ft_isalnum.c \
	srcs/libc/ft_isalpha.c \
	srcs/libc/ft_isascii.c \
	srcs/libc/ft_isdigit.c \
	srcs/libc/ft_isprint.c \
	srcs/libc/ft_itoa.c \
	srcs/libc/ft_memchr.c \
	srcs/libc/ft_memcmp.c \
	srcs/libc/ft_memcpy.c \
	srcs/libc/ft_memmove.c \
	srcs/libc/ft_memset.c \
	srcs/libc/ft_putchar_fd.c \
	srcs/libc/ft_putendl_fd.c \
	srcs/libc/ft_putnbr_fd.c \
	srcs/libc/ft_putstr_fd.c \
	srcs/libc/ft_split.c \
	srcs/libc/ft_strchr.c \
	srcs/libc/ft_strdup.c \
	srcs/libc/ft_striteri.c \
	srcs/libc/ft_strjoin.c \
	srcs/libc/ft_strlcat.c \
	srcs/libc/ft_strlcpy.c \
	srcs/libc/ft_strlen.c \
	srcs/libc/ft_strmapi.c \
	srcs/libc/ft_strncmp.c \
	srcs/libc/ft_strnstr.c \
	srcs/libc/ft_strrchr.c \
	srcs/libc/ft_strtrim.c \
	srcs/libc/ft_substr.c \
	srcs/libc/ft_tolower.c \
	srcs/libc/ft_toupper.c \
	srcs/gnl/get_next_line.c \
	srcs/printf/srcs/ft_print_adress.c \
	srcs/printf/srcs/ft_printf.c \
	srcs/printf/srcs/ft_putchar.c \
	srcs/printf/srcs/ft_putnbr_base.c \
	srcs/printf/srcs/ft_putnbr.c \
	srcs/printf/srcs/ft_putnbr_unsigned.c \
	srcs/printf/srcs/ft_putstr.c

# Object files in obj/ with matching structure
OBJS = $(SRCS:srcs/%.c=obj/%.o)

# Default rule
all: $(NAME)

# Create lib
$(NAME): $(OBJS)
	@mkdir -p lib
	@$(AR) $(NAME) $(OBJS)
	@echo "\033[1;32m\n✅ Compiled and archived: $(NAME)\033[0m"

BAR_LENGTH := 50
UPDATE_BAR = $(shell echo -n "$(1)" | awk '{ printf("%-*s", '"$(BAR_LENGTH)"', $$1); }')


# Compile to obj/ while preserving directory structure
obj/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo -n "\r[\033[0;34m$(shell echo $(words $(OBJS)) | awk '{print int($$1*100/$(BAR_LENGTH))"%"}')\033[0m] Compiling..."

# Clean object files
clean:
	@$(RM) $(OBJS)
	@echo "\033[0;33m🧹 Cleaned object files\033[0m"

# Clean all
fclean: clean
	@$(RM) $(NAME)
	@echo "\033[1;31m🧨 Removed $(NAME)\033[0m"

# Recompile all
re: fclean all

.PHONY: all clean fclean re
